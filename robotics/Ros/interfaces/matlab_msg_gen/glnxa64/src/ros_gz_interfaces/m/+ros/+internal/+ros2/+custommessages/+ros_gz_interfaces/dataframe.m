function [data, info] = dataframe
%Dataframe gives an empty data for ros_gz_interfaces/Dataframe
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'ros_gz_interfaces/Dataframe';
[data.header, info.header] = ros.internal.ros2.messages.std_msgs.header;
info.header.MLdataType = 'struct';
[data.src_address, info.src_address] = ros.internal.ros2.messages.ros2.char('string',1,NaN,0);
[data.dst_address, info.dst_address] = ros.internal.ros2.messages.ros2.char('string',1,NaN,0);
[data.data, info.data] = ros.internal.ros2.messages.ros2.default_type('uint8',NaN,0);
[data.rssi, info.rssi] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
info.MessageType = 'ros_gz_interfaces/Dataframe';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,9);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.stamp';
info.MatPath{3} = 'header.stamp.sec';
info.MatPath{4} = 'header.stamp.nanosec';
info.MatPath{5} = 'header.frame_id';
info.MatPath{6} = 'src_address';
info.MatPath{7} = 'dst_address';
info.MatPath{8} = 'data';
info.MatPath{9} = 'rssi';
