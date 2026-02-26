function pub = SendJointSpeeds(qdot, topic)
% SendJointSpeeds Publish a 3- or 6-element joint velocity vector to a ROS 2 velocity controller.
%
%   pub = SendJointSpeeds(qdot)
%   pub = SendJointSpeeds(qdot, topic)
%
% Inputs
%   qdot : [3x1], [1x3], [6x1], or [1x6] double.
%          If 3 elements are provided → padded to 6.
%
%   topic: (optional) topic string. Default: "/forward_velocity_controller/commands"
%
% Output
%   pub  : (optional) ros2publisher handle.

    if nargin < 2 || isempty(topic)
        topic = "/forward_velocity_controller/commands";
    end

    % Validate numeric
    if ~isnumeric(qdot)
        error("SendJointSpeeds:InputType", "qdot must be numeric.");
    end

    % Accept 3 or 6 elements
    n = numel(qdot);
    if n == 3
        qdot = reshape(double(qdot), 1, 3);
    elseif n == 6
        qdot = reshape(double(qdot), 1, 6);
    else
        error("SendJointSpeeds:InputSize", ...
              "qdot must be a 3- or 6-element numeric vector.");
    end

    % Persistent node & publisher
    persistent node velPub currentTopic
    if isempty(node) || ~isvalid(node)
        node = ros2node("matlab_velocity_pub");
        currentTopic = "";
    end
    if isempty(velPub) || ~isvalid(velPub) || ~strcmp(currentTopic, topic)
        velPub = ros2publisher(node, topic, "std_msgs/Float64MultiArray");
        currentTopic = topic;
    end

    % Build + send message
    msg = ros2message("std_msgs/Float64MultiArray");
    msg.data = qdot;
    send(velPub, msg);

    if nargout > 0
        pub = velPub;
    end
end
