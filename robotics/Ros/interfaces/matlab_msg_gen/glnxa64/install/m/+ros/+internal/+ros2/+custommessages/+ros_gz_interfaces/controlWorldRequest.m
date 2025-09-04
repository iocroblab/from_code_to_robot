function [data, info] = controlWorldRequest
%ControlWorld gives an empty data for ros_gz_interfaces/ControlWorldRequest
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'ros_gz_interfaces/ControlWorldRequest';
[data.world_control, info.world_control] = ros.internal.ros2.custommessages.ros_gz_interfaces.worldControl;
info.world_control.MLdataType = 'struct';
info.MessageType = 'ros_gz_interfaces/ControlWorldRequest';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,12);
info.MatPath{1} = 'world_control';
info.MatPath{2} = 'world_control.pause';
info.MatPath{3} = 'world_control.step';
info.MatPath{4} = 'world_control.multi_step';
info.MatPath{5} = 'world_control.reset';
info.MatPath{6} = 'world_control.reset.all';
info.MatPath{7} = 'world_control.reset.time_only';
info.MatPath{8} = 'world_control.reset.model_only';
info.MatPath{9} = 'world_control.seed';
info.MatPath{10} = 'world_control.run_to_sim_time';
info.MatPath{11} = 'world_control.run_to_sim_time.sec';
info.MatPath{12} = 'world_control.run_to_sim_time.nanosec';
