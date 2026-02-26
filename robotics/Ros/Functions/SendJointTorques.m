function pub = SendJointTorques(tau, topic)
% SendJointTorques Publish a 3- or 6-element torque vector to a ROS 2 effort controller.
%
%   pub = SendJointTorques(tau)
%   pub = SendJointTorques(tau, topic)
%
% Inputs
%   tau   : [3x1], [1x3], [6x1], or [1x6] double
%
%   topic : (optional) topic string. Default: "/forward_effort_controller/commands"
%
% Output
%   pub   : (optional) ros2publisher handle.

    if nargin < 2 || isempty(topic)
        topic = "/forward_effort_controller/commands";
    end

    % Validate numeric
    if ~isnumeric(tau)
        error("SendJointTorques:InputType", "tau must be numeric.");
    end

    n = numel(tau);
    if n == 3
        tau = reshape(double(tau), 1, 3);
    elseif n == 6
        tau = reshape(double(tau), 1, 6);
    else
        error("SendJointTorques:InputSize", ...
              "tau must be a 3- or 6-element numeric vector.");
    end

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

    % Build + send
    msg = ros2message("std_msgs/Float64MultiArray");
    msg.data = tau;
    send(effortPub, msg);

    if nargout > 0
        pub = effortPub;
    end
end
