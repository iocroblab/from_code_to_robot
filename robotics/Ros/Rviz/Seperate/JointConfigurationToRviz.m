function success = JointConfigurationToRviz(JointConfiguration)
%JOINTCONFIGURATIONTORVIZ Publish a 6-DOF joint configuration to RViz via ROS2.
%   success = JointConfigurationToRviz(JointConfiguration) assumes that 
%   RvizSetup has already initialized the ROS2 node, publisher, and JointState
%   message template in the base workspace.

arguments
    % Ensure a 1×6 vector of doubles within [-4π, 4π]
    JointConfiguration %(1,6) double {>= -4*pi, <= 4*pi}
end
arguments (Output)
    % Logical output indicating success of send operation
    success (1,1) logical
end

try
    % Retrieve pre-initialized ROS components from base workspace
    node = evalin('base', 'MatlabToRvizNode');
    jsPub = evalin('base', 'JointStatePublisher');
    jsMsg = evalin('base', 'JointState');

    % Update joint positions and timestamp
    jsMsg.position = JointConfiguration;
    jsMsg.header.stamp = ros2time(node, 'now');

    % Publish the message
    send(jsPub, jsMsg);

    % Update the base workspace template if desired
    assignin('base', 'JointState', jsMsg);

    success = true;
catch ME
    warning('JointConfigurationToRviz:PublishFailed', '%s', ME.message);
    success = false;
end
end
