function RvizSetup()
%RVIZSETUP Summary of this function goes here
%   Detailed explanation goes here




MatlabToRvizNode = ros2node("MatlabToRviz",0);


JointStatePublisher=ros2publisher(MatlabToRvizNode,"/joint_states","sensor_msgs/JointState");


JointState=ros2message(JointStatePublisher);

JointState.name{1}='shoulder_pan_joint';
JointState.name{2}='shoulder_lift_joint';
JointState.name{3}='elbow_joint';
JointState.name{4}='wrist_1_joint';
JointState.name{5}='wrist_2_joint';
JointState.name{6}='wrist_3_joint';

assignin('base', 'MatlabToRvizNode', MatlabToRvizNode);
assignin('base', 'JointStatePublisher', JointStatePublisher);
assignin('base', 'JointState', JointState);
end