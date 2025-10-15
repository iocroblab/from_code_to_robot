function varargout = GetJointValues(value, order, timeout)
% GetJointValues Return joint positions, velocities, and efforts from /joint_states.
%
%   [pos, vel, eff] = GetJointValues()          % returns all three [6x1] in default order
%   pos = GetJointValues('State')               % returns joint positions [6x1]
%   vel = GetJointValues('Speed')               % returns joint velocities [6x1]
%   eff = GetJointValues('Effort')              % returns joint efforts [6x1]
%   [pos, vel, eff] = GetJointValues('All')    % returns all three as [6x1] each
%
%   pos = GetJointValues(value, order)          % custom joint order (1x6 string/cellstr)
%   pos = GetJointValues(value, order, timeout) % custom timeout in seconds (default 5.0)
%
% Notes:
% - Blocks up to `timeout` seconds waiting for a /joint_states message.
% - Reorders outputs to match `order`, independent of /joint_states.name order.
% - If 'All' is requested (default), three outputs are returned; otherwise a single output
%   corresponding to the requested type (State, Speed, or Effort) is returned.

    arguments
        value (1,:) char {mustBeMember(value,{'State','Speed','Effort','All'})} = 'All'
        order cell = {'shoulder_pan_joint','shoulder_lift_joint','elbow_joint', ...
                      'wrist_1_joint','wrist_2_joint','wrist_3_joint'}
        timeout double = 5.0
    end

    if isstring(order), order = cellstr(order(:).'); end
    if ~iscell(order) || numel(order) ~= 6
        error('GetJointValues:BadOrder','`order` must be a 6-element cell array or string array of joint names.');
    end

    % Persistent ROS 2 node + subscriber
    persistent node sub
    if isempty(node) || ~isvalid(node)
        node = ros2node("matlab_jointstate_listener");
        sub  = ros2subscriber(node, "/joint_states", "sensor_msgs/JointState");
    end

    % Receive one message (blocking up to timeout)
    msg = receive(sub, timeout);
    if isempty(msg)
        error("GetJointValues:Timeout", "No /joint_states message received within %.1f s.", timeout);
    end

    % Basic checks
    names = cellstr(msg.name);
    pos   = double(msg.position);
    vel   = double(msg.velocity);
    eff   = double(msg.effort);

    if numel(names) < 6
        error("GetJointValues:TooFewJoints", "Expected at least 6 joints, got %d.", numel(names));
    end

    % Build index map from incoming names to desired order
    [tf, idx] = ismember(order, names);
    if ~all(tf)
        missing = order(~tf);
        error('GetJointValues:MissingNames', ...
              'The following joints are missing in /joint_states: %s', strjoin(missing, ', '));
    end

    % Reorder outputs
    q   = reshape(pos(idx), 6, 1);
    dq  = reshape(vel(idx), 6, 1);
    tau = reshape(eff(idx), 6, 1);

    % Return only requested output(s)
    switch lower(value)
        case 'state'
            varargout = {q};
        case 'speed'
            varargout = {dq};
        case 'effort'
            varargout = {tau};
        case 'all'
            varargout = {q, dq, tau};
    end
end
