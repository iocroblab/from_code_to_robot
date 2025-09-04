function [data, info] = worldReset
%WorldReset gives an empty data for ros_gz_interfaces/WorldReset
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'ros_gz_interfaces/WorldReset';
[data.all, info.all] = ros.internal.ros2.messages.ros2.default_type('logical',1,0, NaN, [0]);
[data.time_only, info.time_only] = ros.internal.ros2.messages.ros2.default_type('logical',1,0, NaN, [0]);
[data.model_only, info.model_only] = ros.internal.ros2.messages.ros2.default_type('logical',1,0, NaN, [0]);
info.MessageType = 'ros_gz_interfaces/WorldReset';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,3);
info.MatPath{1} = 'all';
info.MatPath{2} = 'time_only';
info.MatPath{3} = 'model_only';
