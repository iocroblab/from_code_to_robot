function [data, info] = logicalCameraImageModel
%LogicalCameraImageModel gives an empty data for ros_gz_interfaces/LogicalCameraImageModel
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'ros_gz_interfaces/LogicalCameraImageModel';
[data.name, info.name] = ros.internal.ros2.messages.ros2.char('string',1,NaN,0);
[data.pose, info.pose] = ros.internal.ros2.messages.geometry_msgs.pose;
info.pose.MLdataType = 'struct';
info.MessageType = 'ros_gz_interfaces/LogicalCameraImageModel';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,11);
info.MatPath{1} = 'name';
info.MatPath{2} = 'pose';
info.MatPath{3} = 'pose.position';
info.MatPath{4} = 'pose.position.x';
info.MatPath{5} = 'pose.position.y';
info.MatPath{6} = 'pose.position.z';
info.MatPath{7} = 'pose.orientation';
info.MatPath{8} = 'pose.orientation.x';
info.MatPath{9} = 'pose.orientation.y';
info.MatPath{10} = 'pose.orientation.z';
info.MatPath{11} = 'pose.orientation.w';
