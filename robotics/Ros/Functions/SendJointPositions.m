function pub = SendJointPositions(q, topic)
% SendJointPositions Publish a 3- or 6-element joint position vector to a ROS 2 position controller.
%
%   pub = SendJointPositions(q)
%   pub = SendJointPositions(q, topic)
%
% Inputs
%   q    : [3x1], [1x3], [6x1], or [1x6] double.
%
%   topic: (optional) topic string. Default: "/forward_position_controller/commands"
%
% Output
%   pub  : (optional) ros2publisher handle.

    if nargin < 2 || isempty(topic)
        topic = "/forward_position_controller/commands";
    end

    % Validate numeric
    if ~isnumeric(q)
        error("SendJointPosition:InputType", "q must be numeric.");
    end

    % Accept 3 or 6 elements
    n = numel(q);
    if n == 3
        q = reshape(double(q), 1, 3);
    elseif n == 6
        q = reshape(double(q), 1, 6);
    else
        error("SendJointPosition:InputSize", ...
              "q must be a 3- or 6-element numeric vector.");
    end

    % Persistent node & publisher
    persistent node posPub currentTopic
    if isempty(node) || ~isvalid(node)
        node = ros2node("matlab_position_pub");
        currentTopic = "";
    end
    if isempty(posPub) || ~isvalid(posPub) || ~strcmp(currentTopic, topic)
        posPub = ros2publisher(node, topic, "std_msgs/Float64MultiArray");
        currentTopic = topic;
    end

    % Build + send message
    msg = ros2message("std_msgs/Float64MultiArray");
    msg.data = q;
    send(posPub, msg);

    if nargout > 0
        pub = posPub;
    end
end
