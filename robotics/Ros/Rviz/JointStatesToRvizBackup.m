function success = JointStatesToRviz(JointConfiguration,ur_model, time)
%JOINTCONFIGURATIONTORVIZ Initialize and publish a 6-DOF joint configuration to RViz via ROS2.
%   On first call, this function sets up the ROS2 node, publisher, and message. 
%   Subsequent calls will reuse the same resources for efficiency.
%
%   success = JointConfigurationToRviz(JointConfiguration)
%   - JointConfiguration: 1×6 vector of joint angles (radians) within [-4π, 4π]
%   - success: logical true if message was published without error, false otherwise

arguments
    JointConfiguration 
    ur_model char= 'ur3e'
    time = 5
end
arguments (Output)
    success (1,1) logical
end

persistent node jsPub jsMsg

% if isunix %only start up Rviz automatically if run on Ubuntu
%     promt = strcat(['cd Ros/Repo/; ' ...
%         'source install/setup.bash; ' ...
%         'ros2 launch ur_description view_ur.launch.py ur_type:=', ur_model]); 
%     StartIfNotRunning('view_ur\.launch\.py', promt);
% 
% 
% elseif ispc
%     promt=strcat('wsl docker exec -dit gz-modified bash -c "cd Ros/Repo && source install/setup.bash && ros2 launch ur_description view_ur.launch.py ur_type:=', ur_model, '"');
%     StartIfNotRunning('view_ur\.launch\.py', promt, "windows");    
% end
% --- Initialization on first call ---
if isempty(node) || ~isvalid(node)
    % Create a ROS2 node
    node = ros2node("MatlabToRvizNode");
    % Create a JointState publisher
    jsPub = ros2publisher(node, "/joint_states", "sensor_msgs/JointState");
    % Prepare a reusable message template
    jsMsg = ros2message(jsPub);
    jsMsg.name = {
        'shoulder_pan_joint';
        'shoulder_lift_joint';
        'elbow_joint';
        'wrist_1_joint';
        'wrist_2_joint';
        'wrist_3_joint'};
end

%format input joint states
if size(JointConfiguration,1)==6 && size(JointConfiguration,2)~=6
    JointConfiguration = JointConfiguration'; 
end

% --- Publish the joint configurations ---
NumJointStates = size(JointConfiguration,1);
desiredRate = NumJointStates/time; 
r = ros2rate(node, desiredRate);

reset(r);
for i=1:NumJointStates
    try
        % Assign positions
        jsMsg.position = JointConfiguration(i,:);
        % Timestamp the message
        jsMsg.header.stamp = ros2time(node, 'now');
        % Send to RViz
        send(jsPub, jsMsg);
        success = true;
        % Pause to maintain the desired publishing rate
        if NumJointStates~=1
        waitfor(r);
        end

    catch ME
        warning('JointConfigurationToRviz:PublishFailed', '%s', ME.message);
        success = false;
    end
end
end
