function [data, info] = deleteEntityRequest
%DeleteEntity gives an empty data for ros_gz_interfaces/DeleteEntityRequest
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'ros_gz_interfaces/DeleteEntityRequest';
[data.entity, info.entity] = ros.internal.ros2.custommessages.ros_gz_interfaces.entity;
info.entity.MLdataType = 'struct';
info.MessageType = 'ros_gz_interfaces/DeleteEntityRequest';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,12);
info.MatPath{1} = 'entity';
info.MatPath{2} = 'entity.NONE';
info.MatPath{3} = 'entity.LIGHT';
info.MatPath{4} = 'entity.MODEL';
info.MatPath{5} = 'entity.LINK';
info.MatPath{6} = 'entity.VISUAL';
info.MatPath{7} = 'entity.COLLISION';
info.MatPath{8} = 'entity.SENSOR';
info.MatPath{9} = 'entity.JOINT';
info.MatPath{10} = 'entity.id';
info.MatPath{11} = 'entity.name';
info.MatPath{12} = 'entity.type';
