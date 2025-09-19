function pub = SendJointTorques(tau, topic)
% SendJointTorques Publish a 6-element torque vector to a ROS 2 effort controller.
%
%   pub = SendJointTorques(tau)
%   pub = SendJointTorques(tau, topic)
%
% Inputs
%   tau   : [6x1] or [1x6] double, torques [Nm] in the controller's joint order.
%   topic : (optional) topic string. Default: "/forward_effort_controller/commands"
%
% Output
%   pub   : (optional) the persistent ros2publisher handle.
%
% Notes
% - Uses persistent ROS 2 node "matlab_effort_pub" and publisher for efficiency.
% - Call in a loop with ros2rate to hold torque over time.

    if nargin < 2 || isempty(topic)
        topic = "/forward_effort_controller/commands";
    end

    % Validate and shape input
    if ~isnumeric(tau) || numel(tau) ~= 6
        error("SendJointTorques:InputSize", "tau must be a 6-element numeric vector.");
    end
    tau = reshape(double(tau), 1, 6);

    % Persistent node & publisher
    persistent node effortPub currentTopic
    if isempty(node) || ~isvalid(node)
        node = ros2node("matlab_effort_pub");
        currentTopic = "";
    end
    if isempty(effortPub) || ~isvalid(effortPub) || ~strcmp(currentTopic, topic)
        effortPub = ros2publisher(node, topic, "std_msgs/Float64MultiArray");
        currentTopic = topic;
    end

    % Build + send message
    msg = ros2message("std_msgs/Float64MultiArray");
    msg.data = tau;
    send(effortPub, msg);

    if nargout > 0
        pub = effortPub;
    end
end
