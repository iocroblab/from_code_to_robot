function TargetFrameBroadcaster(homogeneousTransform, childFrame, parentFrame)    

    % TARGETFRAMEBROADCASTER Function to publish a static transform between frames
    %
    % Input Arguments:
    %     homogeneousTransform - 4x4 homogeneous transformation matrix
    %     childFrame - name of the child frame
    %     parentFrame - name of the parent frame (default is 'world')
    
    % Validate the size of the input transformation matrix
    arguments
        homogeneousTransform 
        childFrame 
        parentFrame char= 'world'
    end
    
    % Check if the input is a 4x4 matrix
    if ~isequal(size(homogeneousTransform), [4, 4])
        error('Input must be a 4x4 homogeneous transformation matrix.');
    end
    
    % Create a ROS 2 node for broadcasting the transform
    tf2broadcaster_node = ros2node("tf2broadcaster_node", 0);
    % Create a transform tree with specified Quality of Service settings
    qos = struct('History', 'keeplast', 'Depth', 10, 'Reliability', 'reliable', 'Durability', 'volatile');
   
    tftree = ros2tf(tf2broadcaster_node,'DynamicBroadcasterQoS',qos);
    
    % Create a TransformStamped message
    tfStampedMsg = ros2message('geometry_msgs/TransformStamped');
    % Set the child frame ID
    tfStampedMsg.child_frame_id = childFrame;
    % Set the parent frame ID
    tfStampedMsg.header.frame_id = parentFrame;
    % Extract translation from the homogeneous transformation matrix
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
    sendTransform(tftree,tfStampedMsg, "UseStatic", false)
    % Print confirmation of the published transform
    fprintf("Published static transform: %s → %s\n", ...
            tfStampedMsg.header.frame_id, tfStampedMsg.child_frame_id);
end
