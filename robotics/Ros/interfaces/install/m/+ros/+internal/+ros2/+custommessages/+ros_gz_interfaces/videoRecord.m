function [data, info] = videoRecord
%VideoRecord gives an empty data for ros_gz_interfaces/VideoRecord
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'ros_gz_interfaces/VideoRecord';
[data.header, info.header] = ros.internal.ros2.messages.std_msgs.header;
info.header.MLdataType = 'struct';
[data.start, info.start] = ros.internal.ros2.messages.ros2.default_type('logical',1,0);
[data.stop, info.stop] = ros.internal.ros2.messages.ros2.default_type('logical',1,0);
[data.format, info.format] = ros.internal.ros2.messages.ros2.char('string',1,NaN,0);
[data.save_filename, info.save_filename] = ros.internal.ros2.messages.ros2.char('string',1,NaN,0);
info.MessageType = 'ros_gz_interfaces/VideoRecord';
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
info.MatPath{6} = 'start';
info.MatPath{7} = 'stop';
info.MatPath{8} = 'format';
info.MatPath{9} = 'save_filename';
