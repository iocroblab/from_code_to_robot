function client = SendJointTrajectory(q, time, topic)
% SendJointTrajectory Send a joint trajectory (single or multi-point) to a ROS 2
% FollowJointTrajectory action server (e.g., scaled_joint_trajectory_controller).
%
%   client = SendJointTrajectory(q)
%   client = SendJointTrajectory(q, time)
%   client = SendJointTrajectory(q, time, topic)
%
% Inputs
%   q     : [6x1], [1x6], [Nx6], or [6xN] double (radians), UR joint order:
%           shoulder_pan_joint, shoulder_lift_joint, elbow_joint,
%           wrist_1_joint, wrist_2_joint, wrist_3_joint
%           NOTE: If q is 6x6, EACH COLUMN is treated as a configuration.
%
%   time  : (optional)
%           - scalar > 0 : total duration in seconds, points are spaced evenly
%           - vector Nx1 or 1xN : absolute time_from_start for each point (seconds)
%           Default: 2.0 for single point; for trajectory default is linspace(0,2,N)
%
%   topic : (optional) action name. Default:
%           "/scaled_joint_trajectory_controller/follow_joint_trajectory"
%
% Output
%   client: (optional) ros2actionclient handle.

    if nargin < 3 || isempty(topic)
        topic = "/scaled_joint_trajectory_controller/follow_joint_trajectory";
    end
    topic = string(topic);

    % ---------------- Validate / reshape q ----------------
    if ~isnumeric(q) || isempty(q)
        error("SendJointTrajectory:InputType", "q must be numeric and non-empty.");
    end
    q = double(q);

    if isvector(q)
        if numel(q) ~= 6
            error("SendJointTrajectory:InputSize", "q vector must have 6 elements.");
        end
        q = reshape(q, 1, 6);     % 1x6
    else
        r = size(q,1);
        c = size(q,2);

        % Special rule: if 6x6, interpret columns as configurations
        if r == 6 && c == 6
            q = q.';              % -> 6 points, Nx6
        elseif c == 6
            % Nx6 already: rows are waypoints
            % do nothing
        elseif r == 6
            % 6xN: columns are waypoints
            q = q.';              % -> Nx6
        else
            error("SendJointTrajectory:InputSize", ...
                "q must have one dimension equal to 6 (Nx6 or 6xN). Got %dx%d.", r, c);
        end
    end

    N = size(q,1);

    % ---------------- Handle time ----------------
    if nargin < 2 || isempty(time)
        if N == 1
            tvec = 2.0;
        else
            tvec = linspace(0, 2.0, N);
        end
    else
        if ~isnumeric(time) || any(~isfinite(time(:)))
            error("SendJointTrajectory:Time", "time must be finite numeric.");
        end

        if isscalar(time)
            if time <= 0
                error("SendJointTrajectory:Time", "Scalar time must be > 0 (seconds).");
            end
            if N == 1
                tvec = double(time);
            else
                tvec = linspace(0, double(time), N);
            end
        else
            tvec = double(time(:))'; % row
            if numel(tvec) ~= N
                error("SendJointTrajectory:TimeSize", ...
                    "If time is a vector, it must have N elements (same as number of trajectory points).");
            end
            if any(tvec < 0) || any(diff(tvec) < 0)
                error("SendJointTrajectory:TimeMonotonic", ...
                    "Time vector must be nonnegative and nondecreasing.");
            end
        end
    end

    % Persistent node & action client
    persistent node trajClient currentTopic
    if isempty(node) || ~isvalid(node)
        node = ros2node("matlab_scaled_traj_sender");
        currentTopic = "";
    end

    if isempty(trajClient) || ~isvalid(trajClient) || currentTopic ~= topic
        trajClient = ros2actionclient(node, topic, "control_msgs/FollowJointTrajectory");
        currentTopic = topic;

        ok = waitForServer(trajClient, "Timeout", 5);
        if ~ok
            error("SendJointTrajectory:NoServer", ...
                "No action server at '%s'. Check controller is active and action name is correct.", topic);
        end
    end

    % Goal
    goal = ros2message(trajClient);
    goal.trajectory.joint_names = { ...
        'shoulder_pan_joint', 'shoulder_lift_joint', 'elbow_joint', ...
        'wrist_1_joint', 'wrist_2_joint', 'wrist_3_joint' };

    % Keep MATLAB type compatibility by emptying the pre-typed fields
    goal.path_tolerance = goal.path_tolerance([]);
    goal.goal_tolerance = goal.goal_tolerance([]);
    goal.goal_time_tolerance.sec = int32(0);
    goal.goal_time_tolerance.nanosec = uint32(0);

    % Build trajectory points
    pts(1,N) = ros2message("trajectory_msgs/JointTrajectoryPoint"); %#ok<AGROW>
    for k = 1:N
        pt = ros2message("trajectory_msgs/JointTrajectoryPoint");
        pt.positions = q(k,:);

        % IMPORTANT: prevent size mismatch validation
        pt.velocities    = [];
        pt.accelerations = [];
        pt.effort        = [];

        % time_from_start
        tk = tvec(k);
        sec  = floor(tk);
        nsec = round((tk - sec) * 1e9);
        if nsec >= 1e9
            sec  = sec + 1;
            nsec = nsec - 1e9;
        end
        pt.time_from_start.sec     = int32(sec);
        pt.time_from_start.nanosec = uint32(nsec);

        pts(k) = pt;
    end

    goal.trajectory.points = pts;

    sendGoal(trajClient, goal);

    if nargout > 0
        client = trajClient;
    end
end
