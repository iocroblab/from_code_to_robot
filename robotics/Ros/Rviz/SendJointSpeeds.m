function pub = SendJointSpeeds(qdot, topic)
% SendJointSpeeds Publish a 6-element joint velocity vector to a ROS 2 velocity controller.
%
%   pub = SendJointSpeeds(qdot)
%   pub = SendJointSpeeds(qdot, topic)
%
% Inputs
%   qdot : [6x1] or [1x6] double, joint speeds [rad/s] in the controller's joint order.
%   topic: (optional) topic string. Default: "/forward_velocity_controller/commands"
%
% Output
%   pub  : (optional) the persistent ros2publisher handle.
%
% Notes
% - Uses persistent ROS 2 node "matlab_velocity_pub".
% - Call in a loop with ros2rate to hold velocity over time.

    if nargin < 2 || isempty(topic)
        topic = "/forward_velocity_controller/commands";
    end

    % Validate and shape input
    if ~isnumeric(qdot) || numel(qdot) ~= 6
        error("SendJointSpeeds:InputSize", "qdot must be a 6-element numeric vector.");
    end
    qdot = reshape(double(qdot), 1, 6);

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
