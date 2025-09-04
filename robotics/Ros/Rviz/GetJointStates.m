function q = GetJointStates(order, timeout)
% GetJointStates Return joint positions as [6x1] in a specified joint order.
%
%   q = GetJointStates()                    % uses default UR order:
%                                           % {'shoulder_pan_joint','shoulder_lift_joint', ...
%                                           %  'elbow_joint','wrist_1_joint','wrist_2_joint','wrist_3_joint'}
%   q = GetJointStates(order)               % custom order (1x6 or 6x1 string/cellstr)
%   q = GetJointStates(order, timeout)      % custom timeout in seconds (default 5.0)
%
% Notes:
% - Blocks up to `timeout` seconds waiting for a /joint_states message.
% - Reorders positions to match `order`, independent of /joint_states.name order.

    if nargin < 1 || isempty(order)
        order = {'shoulder_pan_joint','shoulder_lift_joint','elbow_joint', ...
                 'wrist_1_joint','wrist_2_joint','wrist_3_joint'};
    end
    if isstring(order), order = cellstr(order(:).'); end
    if ~iscell(order) || numel(order) ~= 6
        error('GetJointStates:BadOrder','`order` must be a 6-element cell array or string array of joint names.');
    end

    if nargin < 2 || isempty(timeout)
        timeout = 5.0;
    end

    % Persistent node + subscriber
    persistent node sub
    if isempty(node) || ~isvalid(node)
        node = ros2node("matlab_jointstate_listener");
        sub  = ros2subscriber(node, "/joint_states", "sensor_msgs/JointState");
    end

    % Receive one message (blocking up to timeout)
    msg = receive(sub, timeout);
    if isempty(msg)
        error("GetJointStates:Timeout", "No /joint_states message received within %.1f s.", timeout);
    end

    % Basic checks
    names = cellstr(msg.name);
    pos   = double(msg.position);
    if numel(names) < 6 || numel(pos) < 6
        error("GetJointStates:TooFewJoints", "Expected at least 6 joints, got %d.", numel(names));
    end

    % Build index map from incoming names to desired order
    [tf, idx] = ismember(order, names);
    if ~all(tf)
        missing = order(~tf);
        error('GetJointStates:MissingNames', ...
              'The following joints are missing in /joint_states: %s', strjoin(missing, ', '));
    end

    % Reorder and return as 6x1
    q = reshape(pos(idx), 6, 1);
end
