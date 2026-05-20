function CapstoneROS_functionnew(e, Base_fruit, TCP_fruit, tracked_fruit, varargin)
% CapstoneROS_function(e, Base_fruit, TCP_fruit, tracked_fruit, Name,Value,...)
%
% Real-time teleop/vision-error driven velocity IK controller.
% This function is intended to be called INSIDE an external rate-controlled loop.
%
% Required inputs:
%   e             : [3x1] or [1x3] translational error/velocity command [x, y, z]
%   Base_fruit    : string/char fruit name that should trigger base-frame motion
%   TCP_fruit     : string/char fruit name that should trigger TCP-frame motion
%   tracked_fruit : string/char currently tracked fruit name
%
% Name-Value optional:
%   'ur_model'     : 'ur3e' default, or 'ur5e','ur10e','ur16e','ur3','ur5','ur10'
%   'kx'           : 0.3 default
%   'ky'           : 0.3 default
%   'kz'           : 0.3 default
%   'q_dot_limits' : ones(6,1) default
%
% Behavior:
% - If tracked_fruit matches Base_fruit, e is interpreted in base frame.
% - If tracked_fruit matches TCP_fruit, e is interpreted in TCP/tool frame.
% - No rotational velocity is commanded.
% - If tracked_fruit matches neither, the robot stops.

    % -------------------- Parse inputs --------------------
    p = inputParser;
    p.FunctionName = mfilename;

    addRequired(p, 'e', @(x) isnumeric(x) && (numel(x) == 3) && all(isfinite(x)));
    addRequired(p, 'Base_fruit', @(x) isstring(x) || ischar(x));
    addRequired(p, 'TCP_fruit', @(x) isstring(x) || ischar(x));
    addRequired(p, 'tracked_fruit', @(x) isstring(x) || ischar(x));

    addParameter(p, 'ur_model', 'ur3e', @(x) isstring(x) || ischar(x));
    addParameter(p, 'kx', 0.3, @(x) isnumeric(x) && isscalar(x) && isfinite(x));
    addParameter(p, 'ky', 0.3, @(x) isnumeric(x) && isscalar(x) && isfinite(x));
    addParameter(p, 'kz', 0.3, @(x) isnumeric(x) && isscalar(x) && isfinite(x));
    addParameter(p, 'q_dot_limits', ones(6,1), ...
        @(x) isnumeric(x) && isequal(size(x), [6,1]) && all(isfinite(x)) && all(x >= 0));

    parse(p, e, Base_fruit, TCP_fruit, tracked_fruit, varargin{:});
    opts = p.Results;

    e = e(:);

    Base_fruit    = lower(strtrim(string(Base_fruit)));
    TCP_fruit     = lower(strtrim(string(TCP_fruit)));
    tracked_fruit = lower(strtrim(string(tracked_fruit)));

    % -------------------- Persistent state --------------------
    persistent setup_completed
    persistent dead v_max_lin v_max_ang sigma_thresh lambda_max
    persistent ur ur_home ur_name_RS_Toolbox
    persistent T_home R_home R_safe r0 band_width r_peak1 r_peak2 r1

    % Fixed home configuration
    if isempty(ur_home)
        ur_home = [0,-pi/2,0,-pi/2,0,0]';
    end

    % Map to Robotics System Toolbox model name
    desired_name_RS = string(mapURTypeToRobotName(opts.ur_model));

    % -------------------- One-time setup --------------------
    if isempty(setup_completed) || ~setup_completed
        dead = 0.03;

        v_max_lin = 0.25;    % [m/s]
        v_max_ang = 1.00;    % [rad/s], kept for safety although angular command is zero

        sigma_thresh = 0.05;
        lambda_max   = 1.0;

        ur_name_RS_Toolbox = desired_name_RS;
        ur = loadrobot(char(ur_name_RS_Toolbox), ...
            "DataFormat", "column", ...
            "Gravity", [0,0,-9.81]);

        [T_home, R_home, R_safe, r0, band_width, r_peak1, r_peak2, r1] = ...
            recomputeWorkspace(ur, ur_home);

        VisualizeWorkspace(R_home);

        setup_completed = true;
    end

    % -------------------- Recompute setup if model changed --------------------
    if ~strcmpi(string(ur_name_RS_Toolbox), desired_name_RS)
        ur_name_RS_Toolbox = desired_name_RS;

        ur = loadrobot(char(ur_name_RS_Toolbox), ...
            "DataFormat", "column", ...
            "Gravity", [0,0,-9.81]);

        [T_home, R_home, R_safe, r0, band_width, r_peak1, r_peak2, r1] = ...
            recomputeWorkspace(ur, ur_home);

        VisualizeWorkspace(R_home);
    end

    % -------------------- Main control --------------------
    try
        % --- Joint state ---
        q = GetJointStates();

        % --- Tool pose in base ---
        T_base_tool = getTransform(ur, q, "tool0", "base_link");
        Rbt = T_base_tool(1:3,1:3);

        % --- Workspace radius in shoulder_link ---
        T_cur_reach = getTransform(ur, q, "tool0", "shoulder_link");
        r_cur = norm(tform2trvec(T_cur_reach));

        % --- Donut scaling ---
        if r_cur >= r1
            s = 0;
        elseif r_cur >= r_peak2
            x = (r_cur - r_peak2) / (r1 - r_peak2);
            s = 0.5 * (1 + cos(pi * x));
        elseif r_cur >= r_peak1
            s = 1;
        else
            if r_cur <= r0
                s = 0;
            else
                x = (r_cur - r0) / (r_peak1 - r0);
                s = 0.5 * (1 - cos(pi * x));
            end
        end

        % If outside workspace or scaling kills motion -> stop
        if s <= 0
            SendJointSpeeds(zeros(6,1));
            return;
        end

        % --- Deadband ---
        e(abs(e) < dead) = 0;

        % --- Apply component gains ---
        v_input = [
            opts.kx * e(1);
            opts.ky * e(2);
            opts.kz * e(3)
        ];

        % --- Apply workspace scaling ---
        v_input = s * v_input;

        % -----------------------------------------------------
        % Frame selection based on tracked fruit
        % -----------------------------------------------------
        if tracked_fruit == Base_fruit
            % e is interpreted directly in base frame
            v_lin_base = v_input;

        elseif tracked_fruit == TCP_fruit
            % e is interpreted in TCP/tool frame and rotated into base frame
            v_lin_base = Rbt * v_input;

        else
            % No valid target selected -> stop safely
            SendJointSpeeds(zeros(6,1));
            return;
        end

        % No rotational velocity
        v_ang_base = zeros(3,1);

        % Full Cartesian twist in [linear; angular] order
        v_cmd = [v_lin_base; v_ang_base];

        % --- Cartesian saturation ---
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
        Jgeo = geometricJacobian(ur, q, "tool0");   % usually [omega; v]
        J = [Jgeo(4:6,:); Jgeo(1:3,:)];             % convert to [v; omega]

        % Damping based on linear part
        Jv = J(1:3,:);
        sigma_min = min(svd(Jv));

        if sigma_min < sigma_thresh
            lambda = lambda_max * (1 - min(1, sigma_min / sigma_thresh));
        else
            lambda = 0;
        end

        A = J * J' + (lambda^2) * eye(6);
        q_dot = J' * (A \ v_cmd);

        % --- Joint velocity saturation ---
        q_dot_limits = opts.q_dot_limits;
        q_dot_limits_safe = max(q_dot_limits, 1e-6);

        ratio = abs(q_dot) ./ q_dot_limits_safe;
        s_q = max(ratio);

        if s_q > 1
            q_dot = q_dot / s_q;
        end

        q_dot = min(max(q_dot, -q_dot_limits_safe), q_dot_limits_safe);

        % --- Command + visualize ---
        SendJointSpeeds(q_dot);

        JointStatesToRviz(q, string(opts.ur_model), [], ...
            "Ellipsoid", true, ...
            "SendJointStates", false, ...
            "EllipsoidResolution", 10);

    catch ME
        try
            SendJointSpeeds(zeros(6,1));
        catch
        end

        rethrow(ME);
    end
end

% -------------------------------------------------------------------------
function [T_home, R_home, R_safe, r0, band_width, r_peak1, r_peak2, r1] = recomputeWorkspace(ur, ur_home)
    T_home = getTransform(ur, ur_home, "tool0", "shoulder_link");
    R_home = norm(tform2trvec(T_home));
    R_safe = 0.5 * R_home;

    r0 = 0;
    band_width = 0.25 * R_home;
    r_peak1 = R_safe - band_width/2;
    r_peak2 = R_safe + band_width/2;
    r1 = R_home;
end

% -------------------------------------------------------------------------
function name = mapURTypeToRobotName(ur_type)
    ur_type = string(lower(ur_type));

    if startsWith(ur_type, "universalur")
        name = char(ur_type);
        return;
    end

    switch ur_type
        case "ur3e"
            name = 'universalUR3e';
        case "ur5e"
            name = 'universalUR5e';
        case "ur10e"
            name = 'universalUR10e';
        case "ur16e"
            name = 'universalUR16e';
        case "ur3"
            name = 'universalUR3';
        case "ur5"
            name = 'universalUR5';
        case "ur10"
            name = 'universalUR10';
        otherwise
            error('Unsupported ur_type "%s". Add mapping in mapURTypeToRobotName.', ur_type);
    end
end