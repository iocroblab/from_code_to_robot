function [data, info] = float32Array
%Float32Array gives an empty data for ros_gz_interfaces/Float32Array
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'ros_gz_interfaces/Float32Array';
[data.data, info.data] = ros.internal.ros2.messages.ros2.default_type('single',NaN,0);
info.MessageType = 'ros_gz_interfaces/Float32Array';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,1);
info.MatPath{1} = 'data';
