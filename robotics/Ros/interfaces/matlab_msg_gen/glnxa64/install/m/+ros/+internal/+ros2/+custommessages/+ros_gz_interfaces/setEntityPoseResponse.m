function [data, info] = setEntityPoseResponse
%SetEntityPose gives an empty data for ros_gz_interfaces/SetEntityPoseResponse
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'ros_gz_interfaces/SetEntityPoseResponse';
[data.success, info.success] = ros.internal.ros2.messages.ros2.default_type('logical',1,0);
info.MessageType = 'ros_gz_interfaces/SetEntityPoseResponse';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,1);
info.MatPath{1} = 'success';
