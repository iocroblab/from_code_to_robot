function TargetFrameBroadcaster(homogeneousTransform)    
    % FRAMEBROADCASTER Function to publish a static transform using ROS 2
    %
    % Input Arguments:
    %     homogeneousTransform - A 4x4 matrix representing the transformation

    % Validate the input homogeneous transform
    if ~isequal(size(homogeneousTransform), [4, 4])
        error('Input must be a 4x4 homogeneous transformation matrix.');
    end
    
    % Create a ROS 2 node for broadcasting transforms
    tf2broadcaster_node = ros2node("tf2broadcaster_node", 0);
    % Create a transform tree with specified Quality of Service settings
    tftree = ros2tf(tf2broadcaster_node,'StaticBroadcasterQoS',struct('Depth',50));

    
    % Create a TransformStamped message
    tfStampedMsg = ros2message('geometry_msgs/TransformStamped');
    tfStampedMsg.child_frame_id = 'Target_frame'; % Set the child frame ID
    tfStampedMsg.header.frame_id = 'world'; % Set the parent frame ID
    
    % Extract translation from the homogeneous transform
    tfStampedMsg.transform.translation.x = homogeneousTransform(1,4);
    tfStampedMsg.transform.translation.y = homogeneousTransform(2,4);
    tfStampedMsg.transform.translation.z = homogeneousTransform(3,4);
    
    % Convert rotation matrix to quaternion
    Tquat=rotm2quat(homogeneousTransform(1:3,1:3)); 
    % Set the quaternion values in the message
    tfStampedMsg.transform.rotation.w = Tquat(1);
    tfStampedMsg.transform.rotation.x = Tquat(2);
    tfStampedMsg.transform.rotation.y = Tquat(3);
    tfStampedMsg.transform.rotation.z = Tquat(4);
    
    % Send the transform message
    sendTransform(tftree,tfStampedMsg)
    % Print confirmation of the published transform
    fprintf("Published static transform: %s → %s\n", ...
            tfStampedMsg.header.frame_id, tfStampedMsg.child_frame_id);
end
