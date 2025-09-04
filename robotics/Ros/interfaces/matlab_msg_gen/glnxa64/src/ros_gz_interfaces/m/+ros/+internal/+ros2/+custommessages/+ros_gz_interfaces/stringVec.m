function [data, info] = stringVec
%StringVec gives an empty data for ros_gz_interfaces/StringVec
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'ros_gz_interfaces/StringVec';
[data.header, info.header] = ros.internal.ros2.messages.std_msgs.header;
info.header.MLdataType = 'struct';
[data.data, info.data] = ros.internal.ros2.messages.ros2.char('string',NaN,NaN,0);
info.MessageType = 'ros_gz_interfaces/StringVec';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,6);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.stamp';
info.MatPath{3} = 'header.stamp.sec';
info.MatPath{4} = 'header.stamp.nanosec';
info.MatPath{5} = 'header.frame_id';
info.MatPath{6} = 'data';
