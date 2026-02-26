function varargout = GetJointValues(value, order, timeout)
% GetJointValues Return joint positions, velocities, efforts and (optionally) time from /joint_states.
%
%   [pos, vel, eff, t] = GetJointValues()                % returns all three [6x1] in default order
%   pos = GetJointValues('State')                     % returns joint positions [Nx1]
%   vel = GetJointValues('Speed')                     % returns joint velocities [Nx1]
%   eff = GetJointValues('Effort')                    % returns joint efforts [Nx1]
% optional: [pos, t] = GetJointValues('State')

%   [pos, vel, eff]       = GetJointValues('All')     % returns all three [Nx1]
%   [pos, vel, eff, t]    = GetJointValues('All')     % same + time stamp [scalar, seconds]
%
%   [pos, vel, eff, t]    = GetJointValues('threelink')
%       % like 'All', but only for the first 3 joints in `order`
%
%   pos = GetJointValues(value, order)                % custom joint order (3 or 6 names)
%   pos = GetJointValues(value, order, timeout)       % custom timeout in seconds (default 5.0)
%
% Notes:
% - Polls up to `timeout` seconds waiting for a /joint_states message.
% - Reorders outputs to match `order`, independent of /joint_states.name order.
% - `order` default has 6 joint names; in 'threelink' mode only the first 3 are used.
% - If 'All' is requested (default), three outputs (pos,vel,eff) are returned;
%   a 4th optional output returns the message time stamp in seconds.
% - In 'threelink' mode, outputs are [3x1] for q,dq,tau plus scalar time.

    arguments
        value (1,:) char {mustBeMember(value,{'State','Speed','Effort','All','threelink'})} = 'All'
        order cell = {'shoulder_pan_joint','shoulder_lift_joint','elbow_joint', ...
                      'wrist_1_joint','wrist_2_joint','wrist_3_joint'}
        timeout double = 5.0
    end

    if isstring(order), order = cellstr(order(:).'); end
    if ~iscell(order)
        error('GetJointValues:BadOrder', ...
              '`order` must be a cell array or string array of joint names.');
    end

    % Determine number of joints and effective order
    if strcmpi(value, 'threelink')
        % Fast path: fixed 3-link case, use first 3 joint names
        if numel(order) < 3
            error('GetJointValues:BadOrderSize', ...
                  '`order` must contain at least 3 joint names for ''threelink'' mode (got %d).', numel(order));
        end
        nJoints = 3;
        order   = order(1:3);
    else
        % General case: allow 3 or 6 joints
        nJoints = numel(order);
        if ~(nJoints == 3 || nJoints == 6)
            error('GetJointValues:BadOrderSize', ...
                  '`order` must contain either 3 or 6 joint names (got %d).', nJoints);
        end
    end

    % Persistent ROS 2 node + subscriber
    persistent node sub
    if isempty(node) || ~isvalid(node)
        node = ros2node("matlab_jointstate_listener");
        sub  = ros2subscriber(node, "/joint_states", "sensor_msgs/JointState");
    end

    % Poll LatestMessage up to `timeout` seconds
    tStart = tic;
    msg = sub.LatestMessage;
    while isempty(msg) && toc(tStart) < timeout
        pause(0.01);  % don't busy-wait
        msg = sub.LatestMessage;
    end

    if isempty(msg)
        error("GetJointValues:Timeout", ...
              "No /joint_states message received within %.1f s.", timeout);
    end

    % Extract time stamp (ROS 2 -> seconds as double)
    t = double(msg.header.stamp.sec) + double(msg.header.stamp.nanosec)*1e-9;

    % Basic checks
    names = cellstr(msg.name);
    pos   = double(msg.position);
    vel   = double(msg.velocity);
    eff   = double(msg.effort);

    if numel(names) < nJoints
        error("GetJointValues:TooFewJoints", ...
              "Expected at least %d joints, got %d.", nJoints, numel(names));
    end

    % Build index map from incoming names to desired order
    [tf, idx] = ismember(order, names);
    if ~all(tf)
        missing = order(~tf);
        error('GetJointValues:MissingNames', ...
              'The following joints are missing in /joint_states: %s', ...
              strjoin(missing, ', '));
    end

    % Reorder outputs (size [nJoints x 1])
    q   = reshape(pos(idx),  nJoints, 1);
    dq  = reshape(vel(idx),  nJoints, 1);
    tau = reshape(eff(idx),  nJoints, 1);

    % Return only requested output(s)
    switch lower(value)
        case 'state'
            varargout = {q,t};
        case 'speed'
            varargout = {dq,t};
        case 'effort'
            varargout = {tau,t};
        case 'all'
            % 4. Output is time; caller can ignore if only 3 outputs requested
            varargout = {q, dq, tau, t};
        case 'threelink'
            % Behaves like 'All' but only for first 3 joints
            varargout = {q, dq, tau, t};
    end
end
