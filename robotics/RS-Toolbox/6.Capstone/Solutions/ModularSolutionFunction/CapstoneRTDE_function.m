function CapstoneRTDE_function(e, fruit, urRTDEObject, varargin)
% CapstoneROS_function(e, fruit, Name,Value,...)
%
% Real-time teleop/vision-error driven velocity IK controller.
% This function is intended to be called INSIDE an external rate-controlled loop.
%
% Required inputs:
%   e     : [3x1] or [1x3] error signal [e_x, e_z, e_scale]
%   fruit : string/char label of currently detected fruit (e.g., "orange")
%   urRTDEObject: ur RTDE object created with urRTDEClient(robot_ip)
%
% Name-Value (all optional):
%   'ur_model'            : 'ur3e' (default) or 'ur5e','ur10e','ur16e','ur3','ur5','ur10'
%   'kx'                  : 0.3 (default)
%   'kz'                  : 0.3 (default)
%   'kt'                  : 0.3 (default)
%   'q_dot_limits'        : ones(6,1) (default)
%   'fruit_to_be_tracked' : 'orange' (default)
%
% Notes:
% - Setup (robot model + workspace radii + visualization) is done once.
% - If ur_model changes across calls, only the dependent setup is recomputed.
% - ur_home is fixed and valid for all Universal Robots models.

    % -------------------- Parse inputs --------------------
    p = inputParser;
    p.FunctionName = mfilename;

    addRequired(p, 'e', @(x) isnumeric(x) && (numel(x) == 3) && all(isfinite(x)));
    addRequired(p, 'fruit', @(x) (isstring(x) || ischar(x)));

    addParameter(p, 'ur_model', 'ur3e', @(x) (isstring(x) || ischar(x)));
    addParameter(p, 'kx', 0.3, @(x) isnumeric(x) && isscalar(x) && isfinite(x));
    addParameter(p, 'kz', 0.3, @(x) isnumeric(x) && isscalar(x) && isfinite(x));
    addParameter(p, 'kt', 0.3, @(x) isnumeric(x) && isscalar(x) && isfinite(x));
    addParameter(p, 'q_dot_limits', ones(6,1), @(x) isnumeric(x) && isequal(size(x), [6,1]) && all(isfinite(x)) && all(x >= 0));
    addParameter(p, 'fruit_to_be_tracked', 'orange', @(x) (isstring(x) || ischar(x)));

    parse(p, e, fruit, varargin{:});
    opts = p.Results;

    e = e(:);
    fruit = string(fruit);
    fruit_to_be_tracked = string(opts.fruit_to_be_tracked);

    % -------------------- Persistent state --------------------
    persistent setup_completed
    persistent dead v_max_lin v_max_ang sigma_thresh lambda_max
    persistent ur ur_home ur_name_RS_Toolbox
    persistent T_home R_home R_safe r0 band_width r_peak1 r_peak2 r1

    % Fixed home configuration (valid for all UR "universalUR..." models)
    if isempty(ur_home)
        ur_home = [0,-pi/2,0,-pi/2,0,0]';
    end

    % Map to Robotics System Toolbox model name
    desired_name_RS = string(mapURTypeToRobotName(opts.ur_model));

    % -------------------- One-time setup --------------------
    if isempty(setup_completed) || ~setup_completed
        % Controller constants (persist)
        dead = 0.03;
        v_max_lin = 0.25;    % [m/s]
        v_max_ang = 1.00;    % [rad/s]
        sigma_thresh = 0.02;
        lambda_max   = 0.02;

        % Load robot
        ur_name_RS_Toolbox = desired_name_RS;
        ur = loadrobot(char(ur_name_RS_Toolbox), "DataFormat","column", "Gravity",[0,0,-9.81]);

        % Compute workspace radii + visualize
        [T_home, R_home, R_safe, r0, band_width, r_peak1, r_peak2, r1] = ...
            recomputeWorkspace(ur, ur_home);

        VisualizeWorkspace(R_home);

        setup_completed = true;
    end

    % -------------------- Recompute setup if model changed --------------------
    if ~strcmpi(string(ur_name_RS_Toolbox), desired_name_RS)
        ur_name_RS_Toolbox = desired_name_RS;
        ur = loadrobot(char(ur_name_RS_Toolbox), "DataFormat","column", "Gravity",[0,0,-9.81]);

        [T_home, R_home, R_safe, r0, band_width, r_peak1, r_peak2, r1] = ...
            recomputeWorkspace(ur, ur_home);

        VisualizeWorkspace(R_home);
    end

    % -------------------- If wrong fruit: stop (safety) --------------------
    if ~strcmpi(fruit, fruit_to_be_tracked)
        % Safety behavior: stop if not tracking target fruit
        try
            SendJointSpeeds(zeros(6,1));
        catch
        end
        return;
    end

    % -------------------- Main control --------------------
    try
        % --- Joint state ---
        q = readJointConfiguration(urRTDEObject);
        
        % --- Tool pose in base (for frame mapping) ---
        T_base_tool = getTransform(ur, q, "tool0", "base_link");
        Rbt = T_base_tool(1:3,1:3);
        pbt = tform2trvec(T_base_tool).';  % 3x1

        % --- Error signal ---
        e_x = e(1);
        e_z = e(2);
        e_scale = e(3);

        % --- Workspace radius in shoulder_link ---
        T_cur_reach = getTransform(ur, q, "tool0", "shoulder_link");
        r_cur = norm(tform2trvec(T_cur_reach));

        % --- Donut scaling: slow inside, fast mid, slow outside ---
        if r_cur >= r1
            s = 0;
        elseif r_cur >= r_peak2
            x = (r_cur - r_peak2) / (r1 - r_peak2);   % [0,1]
            s = 0.5 * (1 + cos(pi * x));              % 1 -> 0
        elseif r_cur >= r_peak1
            s = 1;
        else
            if r_cur <= r0
                s = 0;
            else
                x = (r_cur - r0) / (r_peak1 - r0);    % [0,1]
                s = 0.5 * (1 - cos(pi * x));          % 0 -> 1
            end
        end

        % If outside workspace or scaling kills motion -> stop for safety
        if s <= 0
            
            sendSpeedJCommands(ur , zeros(6,1));

            return;
        end

        % --- Deadband ---
        if abs(e_x) < dead,     e_x = 0; end
        if abs(e_z) < dead,     e_z = 0; end
        if abs(e_scale) < dead, e_scale = 0; end

        % --- Scaling ---
        e_x     = e_x     * s;
        e_z     = e_z     * s;
        e_scale = e_scale * s;

        % --- Desired twist in base ---
        v_base = zeros(6,1);
        v_base(1) = opts.kx * e_x;
        v_base(3) = opts.kz * e_z;

        v_tool = zeros(6,1);
        v_tool(3) = opts.kt * e_scale;  % tool Z linear

        % Tool twist -> base twist (adjoint)
        v_tool_lin_b = Rbt * v_tool(1:3) + cross(pbt, Rbt * v_tool(4:6));
        v_tool_ang_b = Rbt * v_tool(4:6);
        v_cmd = v_base + [v_tool_lin_b; v_tool_ang_b];

        % --- Cartesian saturation (norm-based) ---
        v_lin = v_cmd(1:3);
        v_ang = v_cmd(4:6);

        nlin = norm(v_lin);
        nang = norm(v_ang);

        if nlin > v_max_lin && nlin > 0
            v_lin = v_lin * (v_max_lin / nlin);
        end
        if nang > v_max_ang && nang > 0
            v_ang = v_ang * (v_max_ang / nang);
        end

        v_cmd = [v_lin; v_ang];

        % --- Jacobian and DLS IK ---
        Jgeo = geometricJacobian(ur, q, "tool0");     % typically [omega; v]
        J = [Jgeo(4:6,:); Jgeo(1:3,:)];               % force [v; omega]

        % Damping based on linear part (your original choice)
        Jv = J(1:3,:);
        sigma_min = min(svd(Jv));

        if sigma_min < sigma_thresh
            lambda = lambda_max * (1 - min(1, sigma_min / sigma_thresh));
        else
            lambda = 0;
        end

        A = (J*J' + (lambda^2)*eye(6));
        q_dot = J' * (A \ v_cmd);

        % --- Joint velocity saturation (preserve direction) ---
        q_dot_limits = opts.q_dot_limits;
        q_dot_limits_safe = max(q_dot_limits, 1e-6);   % avoid /0
        ratio = abs(q_dot) ./ q_dot_limits_safe;
        s_q = max(ratio);

        if s_q > 1
            q_dot = q_dot / s_q;
        end

        % tiny safety clip
        q_dot = min(max(q_dot, -q_dot_limits_safe), q_dot_limits_safe);

        % --- Command + visualize ---
        
        sendSpeedJCommands(urRTDEObject, q_dot);

        JointStatesToRviz(q, string(opts.ur_model), [], ...
            "Ellipsoid", true, "EllipsoidResolution", 10);

    catch ME
        try
            sendSpeedJCommands(ur , zeros(6,1));
        catch
        end
        rethrow(ME);
    end
end

% -------------------------------------------------------------------------
function [T_home, R_home, R_safe, r0, band_width, r_peak1, r_peak2, r1] = recomputeWorkspace(ur, ur_home)
    % Workspace radius from home pose (shoulder_link frame)
    T_home = getTransform(ur, ur_home, "tool0", "shoulder_link");
    R_home = norm(tform2trvec(T_home));
    R_safe = 0.5 * R_home;

    % Donut band parameters
    r0 = 0;
    band_width = 0.25 * R_home;
    r_peak1 = R_safe - band_width/2;
    r_peak2 = R_safe + band_width/2;
    r1 = R_home;
end

% -------------------------------------------------------------------------
function name = mapURTypeToRobotName(ur_type)
% mapURTypeToRobotName  Maps UR type strings (e.g. 'ur5e') to full robot names
%                       (e.g. 'universalUR5e'). If the input is already a
%                       valid 'universalUR...' name, it is returned unchanged.

    ur_type = string(lower(ur_type));

    % If it's already a full model name, just return it
    if startsWith(ur_type, "universalur")
        name = char(ur_type);
        return;
    end

    switch ur_type
        case "ur3e",  name = 'universalUR3e';
        case "ur5e",  name = 'universalUR5e';
        case "ur10e", name = 'universalUR10e';
        case "ur16e", name = 'universalUR16e';
        case "ur3",   name = 'universalUR3';
        case "ur5",   name = 'universalUR5';
        case "ur10",  name = 'universalUR10';
        otherwise
            error('Unsupported ur_type "%s". Add mapping in mapURTypeToRobotName.', ur_type);
    end
end