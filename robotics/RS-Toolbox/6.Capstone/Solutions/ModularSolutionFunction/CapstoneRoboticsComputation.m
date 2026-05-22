function q_dot = CapstoneRoboticsComputation( ...
    ur, q, detected_fruit, Base_fruit, TCP_fruit, v_input_saturated, ...
    r0, r_peak1, r_peak2, r1)
% CapstoneRoboticsComputation
%
% Computes the UR joint velocity command q_dot from a saturated Cartesian
% linear velocity input.
%
% The input velocity is first scaled based on the current TCP distance from
% the shoulder_link. Inside the valid workspace region the robot moves at
% full commanded speed. Near the inner and outer workspace boundaries, a
% smooth cosine ramp reduces the commanded velocity to zero.
%
% Depending on detected_fruit, the velocity command is interpreted either in
% the base frame or in the TCP/tool frame. TCP-frame commands are rotated
% into the base frame before inverse kinematics is computed.
%
% The final joint velocity is computed using damped least-squares inverse
% kinematics. Rotational TCP velocity is constrained to zero by commanding a
% zero angular velocity in the 6D Cartesian twist.
%
% Inputs:
%   ur                - rigidBodyTree robot model
%   q                 - current robot configuration
%   detected_fruit    - selected command-frame identifier
%   Base_fruit        - identifier for base-frame command mode
%   TCP_fruit         - identifier for TCP-frame command mode
%   v_input_saturated - saturated 3x1 Cartesian linear velocity input
%   r0                - inner zero-velocity workspace radius
%   r_peak1           - start of full-speed workspace region
%   r_peak2           - end of full-speed workspace region
%   r1                - outer zero-velocity workspace radius
%
% Output:
%   q_dot             - 6x1 joint velocity command

    % --- Static parameters ---
    q_dot_limits = ones(6, 1);
    sigma_thresh = 0.2;
    lambda_max = 1;

    % --- Ensure column vector ---
    v_input_saturated = v_input_saturated(:);

    if numel(v_input_saturated) ~= 3
        error("v_input_saturated must be a 3x1 linear velocity vector.");
    end

    % --- Tool pose in base ---
    T_base_tool = getTransform(ur, q, "tool0", "base_link");
    Rbt = T_base_tool(1:3, 1:3);

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

    v_scaled = s * v_input_saturated;

    % --- Interpret velocity command frame ---
    if detected_fruit == Base_fruit
        % Input velocity is interpreted directly in base frame
        v_lin_base = v_scaled;

    elseif detected_fruit == TCP_fruit
        % Input velocity is interpreted in TCP/tool frame
        % and rotated into the base frame
        v_lin_base = Rbt * v_scaled;

    else
        % No valid command frame detected
        v_lin_base = zeros(3, 1);
    end

    % --- Full Cartesian twist in [linear; angular] order ---
    v_ang_base = zeros(3, 1);
    v_cmd = [v_lin_base; v_ang_base];

    % --- Jacobian and damped least-squares IK ---
    Jgeo = geometricJacobian(ur, q, "tool0");   % MATLAB gives [omega; v]
    J = [Jgeo(4:6, :); Jgeo(1:3, :)];           % convert to [v; omega]

    sigma_min = min(svd(J));

    if sigma_min < sigma_thresh
        lambda = lambda_max * (1 - min(1, sigma_min / sigma_thresh));
    else
        lambda = 0;
    end

    pinvJ = J' / (J * J' + lambda^2 * eye(6));
    q_dot = pinvJ * v_cmd;

    % --- Joint velocity saturation ---
    ratio = abs(q_dot) ./ q_dot_limits;
    s_q = max(ratio);

    if s_q > 1
        q_dot = q_dot / s_q;
    end

    % Final numerical safety clamp
    q_dot = min(max(q_dot, -q_dot_limits), q_dot_limits);
end