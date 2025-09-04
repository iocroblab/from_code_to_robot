function [data, info] = altimeter
%Altimeter gives an empty data for ros_gz_interfaces/Altimeter
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'ros_gz_interfaces/Altimeter';
[data.header, info.header] = ros.internal.ros2.messages.std_msgs.header;
info.header.MLdataType = 'struct';
[data.vertical_position, info.vertical_position] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
[data.vertical_velocity, info.vertical_velocity] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
[data.vertical_reference, info.vertical_reference] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
info.MessageType = 'ros_gz_interfaces/Altimeter';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,8);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.stamp';
info.MatPath{3} = 'header.stamp.sec';
info.MatPath{4} = 'header.stamp.nanosec';
info.MatPath{5} = 'header.frame_id';
info.MatPath{6} = 'vertical_position';
info.MatPath{7} = 'vertical_velocity';
info.MatPath{8} = 'vertical_reference';
