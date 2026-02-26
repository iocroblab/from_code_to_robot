function StaticFrameBroadcaster(T, childFrame, parentFrame)

arguments
    T (4,4) double
    childFrame (1,1) string = "Target_frame"
    parentFrame (1,1) string = "base_link"
end

persistent node tftree

% Keep node alive across calls
if isempty(node) || ~isvalid(node)
    node = ros2node("tf2_static_broadcaster");
    
    % Correct QoS for /tf_static
    qos = struct( ...
        'History',     'keeplast', ...
        'Depth',       1, ...
        'Reliability', 'reliable', ...
        'Durability',  'transientlocal');
    
    tftree = ros2tf(node, "StaticBroadcasterQoS", qos);
end

msg = ros2message("geometry_msgs/TransformStamped");
msg.child_frame_id = char(childFrame);
msg.header.frame_id = char(parentFrame);

% Stamp (don't leave zero time)
msg.header.stamp = ros2time(node, "now");

msg.transform.translation.x = T(1,4);
msg.transform.translation.y = T(2,4);
msg.transform.translation.z = T(3,4);

q = rotm2quat(T(1:3,1:3)); % [w x y z]
msg.transform.rotation.w = q(1);
msg.transform.rotation.x = q(2);
msg.transform.rotation.y = q(3);
msg.transform.rotation.z = q(4);

sendTransform(tftree, msg, "UseStatic", true);

fprintf("Published static transform: %s → %s\n", parentFrame, childFrame);

end
