% function success = JointStatesToRviz(JointConfiguration, ur_type, time, varargin)
% %JOINTSTATESTORVIZ Publish joint states (ROS 2) and, optionally, manipulability
% % ellipsoid to RViz. If a trajectory is given, optionally publish a yellow
% % PointCloud2 of the end-effector path. Also supports clearing topics.
% %
% %   success = JointStatesToRviz(JointConfiguration, ur_type, time, Name,Value)
% %
% %   Inputs
% %     JointConfiguration : [N x 6] or [1 x 6] joint angles (rad).
% %     ur_type            : char, e.g. 'ur3e', 'ur5e', ...
% %     time               : total duration [s] to play the N states. ([] okay)
% %
% %   Name-Value options (all optional):
% %     'Ellipsoid'           : true|false            (default: false)
% %     'EllipsoidKind'       : 'trans'|'rot'         (default: 'trans')
% %     'EllipsoidResolution' : positive int          (default: 25)
% %     'EllipsoidEvery'      : positive int          (default: 1 → send all)
% %     'BaseFrame'           : char                  (default: 'base_link')
% %     'ToolFrame'           : char                  (default: 'tool0')
% %     'JointStateTopic'     : char                  (default: '/joint_states')
% %     'EllipsoidTopic'      : char                  (default: '/manip_ellipsoid')
% %     'Trajectory'          : true|false            (default: N>1)
% %     'TrajectoryTopic'     : char                  (default: '/trajectory_path')
% %
% %   Default for 'Trajectory':
% %     - Single pose (N==1): false
% %     - Trajectory (N>1):   true (unless explicitly passed as false)
% %
% %   (C) 2025
% 
% arguments
%     JointConfiguration
%     ur_type char = 'ur3e'
%     time double = []
% end
% arguments (Repeating)
%     varargin
% end
% 
% % ---- Default time from length ----
% if isempty(time)
%     time = (size(JointConfiguration,1) <= 1) * 1 + (size(JointConfiguration,1) > 1) * 5;
% end
% 
% % ---- Normalize JointConfiguration to [N x 6] ----
% if size(JointConfiguration,2) ~= 6 && size(JointConfiguration,1) == 6
%     JointConfiguration = JointConfiguration.'; % make row
% end
% if size(JointConfiguration,2) ~= 6
%     error('JointConfiguration must have 6 columns.');
% end
% N = size(JointConfiguration,1);
% 
% % ---- Parse options ----
% p = inputParser;
% addParameter(p,'Ellipsoid',false,@(x)islogical(x)&&isscalar(x));
% addParameter(p,'EllipsoidKind','trans',@(s)ischar(s)||isstring(s));
% addParameter(p,'EllipsoidResolution',25,@(n)isnumeric(n)&&isscalar(n)&&n>2);
% addParameter(p,'EllipsoidEvery',1,@(n)isnumeric(n)&&isscalar(n)&&n>=1);
% addParameter(p,'BaseFrame','base_link',@(s)ischar(s)||isstring(s));
% addParameter(p,'ToolFrame','tool0',@(s)ischar(s)||isstring(s));
% addParameter(p,'JointStateTopic','/joint_states',@(s)ischar(s)||isstring(s));
% addParameter(p,'EllipsoidTopic','/manip_ellipsoid',@(s)ischar(s)||isstring(s));
% addParameter(p,'Trajectory',false,@(x)islogical(x)&&isscalar(x));           % may be overridden by default rule
% addParameter(p,'TrajectoryTopic','/trajectory_path',@(s)ischar(s)||isstring(s));
% parse(p, varargin{:});
% opt = p.Results;
% opt.EllipsoidEvery = max(1, floor(opt.EllipsoidEvery)); % sanitize
% 
% % Apply default logic for 'Trajectory' only if user didn't pass it
% useDefaultTraj = any(strcmp(p.UsingDefaults,'Trajectory'));
% if useDefaultTraj
%     doTrajectory = (N > 1);
% else
%     doTrajectory = logical(opt.Trajectory);
% end
% 
% success = false;
% 
% % ---------- Persistent ROS2 node & publishers ----------
% persistent node jsPub ellPub trajPub jsMsg
% try
%     if isempty(node) || ~isvalid(node)
%         node = ros2node("MatlabToRvizNode");
%     end
%     if isempty(jsPub) || ~isvalid(jsPub)
%         jsPub = ros2publisher(node, char(opt.JointStateTopic), "sensor_msgs/JointState");
%     end
%     if isempty(ellPub) || ~isvalid(ellPub)
%         ellPub = ros2publisher(node, char(opt.EllipsoidTopic), "sensor_msgs/PointCloud2");
%     end
%     if isempty(trajPub) || ~isvalid(trajPub)
%         trajPub = ros2publisher(node, char(opt.TrajectoryTopic), "sensor_msgs/PointCloud2");
%     end
%     if isempty(jsMsg)
%         jsMsg = ros2message(jsPub);
%         jsMsg.name = {
%             'shoulder_pan_joint';
%             'shoulder_lift_joint';
%             'elbow_joint';
%             'wrist_1_joint';
%             'wrist_2_joint';
%             'wrist_3_joint'};
%     end
% catch ME
%     warning('ROS 2 setup failed: %s', ME.message);
%     return
% end
% 
% % ---------- Load / cache UR model ----------
% try
%     mdlName = mapURTypeToRobotName(ur_type);
%     model = loadrobot(mdlName, "DataFormat", "row", "Gravity", [0 0 -9.81]); %#ok<NASGU>
% catch ME
%     warning('Failed to load robot model for "%s": %s', ur_type, ME.message);
%     return
% end
% 
% % ---------- Clear topics if disabled ----------
% if ~doTrajectory
%     % Clear any previously displayed trajectory in RViz
%     try, publishEmptyPointCloud(trajPub, node, char(opt.BaseFrame)); catch, end
% end
% if ~opt.Ellipsoid
%     % Clear any previously displayed ellipsoid in RViz
%     try, publishEmptyPointCloud(ellPub, node, char(opt.BaseFrame)); catch, end
% end
% 
% % ---------- If requested, precompute & publish EE trajectory as yellow PointCloud2 ----------
% if doTrajectory
%     try
%         pathXYZ = zeros(N,3,'single');
%         for i = 1:N
%             T_ee = getTransform(model, JointConfiguration(i,:), char(opt.ToolFrame), model.BaseName);
%             pathXYZ(i,:) = single(T_ee(1:3,4)).';
%         end
%         publishPathPointCloud(trajPub, node, pathXYZ, char(opt.BaseFrame));  % yellow
%     catch ME
%         warning('Trajectory path publish failed: %s', ME.message);
%     end
% end
% 
% % ---------- Playback rate ----------
% desiredRate = max(1e-3, N / time);
% r = ros2rate(node, desiredRate);
% reset(r);
% 
% % ---------- Main loop ----------
% allOK = true;
% for i = 1:N
%     q = JointConfiguration(i,:);
% 
%     % Publish joint state
%     try
%         jsMsg.position = q;
%         jsMsg.header.stamp = ros2time(node, 'now');
%         send(jsPub, jsMsg);
%     catch ME
%         warning('JointStatesToRviz:PublishFailed', '%s', ME.message);
%         allOK = false;
%     end
% 
%     % Manipulability ellipsoid (optional, with decimation)
%     if opt.Ellipsoid
%         try
%             sendThis = (mod(i-1, opt.EllipsoidEvery) == 0);
%             % Also ensure the very last state is sent at least once
%             if (i == N) && ~sendThis
%                 sendThis = true;
%             end
%             if sendThis
%                 J = geometricJacobian(model, q, char(opt.ToolFrame));  % 6x6
% 
%                 % Heuristic split into rotational vs translational:
%                 if mean(vecnorm(J(1:3,:),2,2)) > mean(vecnorm(J(4:6,:),2,2))
%                     Jr = J(1:3,:); Jt = J(4:6,:);
%                 else
%                     Jt = J(1:3,:); Jr = J(4:6,:);
%                 end
%                 switch lower(opt.EllipsoidKind)
%                     case {'trans','t','translation','translational'}, Jx = Jt;
%                     case {'rot','r','rotation','rotational'},         Jx = Jr;
%                     otherwise,                                        Jx = Jt;
%                 end
% 
%                 [U,S,~] = svd(Jx,'econ');   % 3x3
%                 T_ee = getTransform(model, q, char(opt.ToolFrame), model.BaseName);
%                 p_ee = T_ee(1:3,4).';        % 1x3
% 
%                 publishEllipsoidPointCloud(ellPub, node, U, S, p_ee, opt.EllipsoidResolution, char(opt.BaseFrame));
%             end
%         catch ME
%             warning('Ellipsoid publish failed: %s', ME.message);
%             allOK = false;
%         end
%     end
% 
%     if N ~= 1
%         waitfor(r);
%     end
% end
% 
% success = allOK;
% 
% end % function
% 
% % ===================== Helpers =====================
% 
% function name = mapURTypeToRobotName(ur_type)
% switch lower(string(ur_type))
%     case "ur3e",  name = 'universalUR3e';
%     case "ur5e",  name = 'universalUR5e';
%     case "ur10e", name = 'universalUR10e';
%     case "ur3",   name = 'universalUR3';
%     case "ur5",   name = 'universalUR5';
%     case "ur10",  name = 'universalUR10';
%     case "ur16e", name = 'universalUR16e';
%     otherwise
%         error('Unsupported ur_type "%s". Add mapping in mapURTypeToRobotName.', ur_type);
% end
% end
% 
% function publishPathPointCloud(pub, node, xyz, frame_id)
% % Publish Nx3 EE path as yellow sensor_msgs/PointCloud2
% if isempty(xyz), publishEmptyPointCloud(pub,node,frame_id); return, end
% if size(xyz,2) ~= 3, error('xyz must be Nx3.'); end
% 
% xyz = single(xyz);
% good = all(isfinite(xyz),2);
% xyz  = xyz(good,:);
% N    = size(xyz,1);
% 
% % Yellow RGB (255,255,0)
% R = uint8(255*ones(1,N));
% G = uint8(255*ones(1,N));
% B = uint8(0*ones(1,N));
% rgb_u32 = uint32(R)*2^16 + uint32(G)*2^8 + uint32(B);
% rgb_f32 = typecast(rgb_u32,'single');   % 1xN
% 
% msg = ros2message(pub);
% msg.header.frame_id = frame_id;
% 
% % Define fields x,y,z,rgb (FLOAT32)
% f = repmat(ros2message("sensor_msgs/PointField"),4,1);
% names = {'x','y','z','rgb'}; offs = [0 4 8 12]; dtype = uint8(7); % FLOAT32
% for i=1:4
%     f(i).name = names{i};
%     f(i).offset = uint32(offs(i));
%     f(i).datatype = dtype;
%     f(i).count = uint32(1);
% end
% msg.fields = f;
% msg.is_bigendian = false;
% msg.height = uint32(1);
% msg.width  = uint32(N);
% msg.point_step = uint32(16);
% msg.row_step   = uint32(16 * N);
% msg.is_dense   = true;
% 
% A = [xyz.'; rgb_f32];      % 4xN
% msg.data = typecast(A(:),'uint8');
% msg.header.stamp = ros2time(node,"now");
% 
% send(pub, msg);
% end
% 
% function publishEmptyPointCloud(pub, node, frame_id)
% % Send an "empty" PointCloud2 to clear RViz display
% msg = ros2message(pub);
% msg.header.frame_id = frame_id;
% msg.header.stamp = ros2time(node,"now");
% 
% % Keep the same field schema RViz expects (x,y,z,rgb as FLOAT32)
% f = repmat(ros2message("sensor_msgs/PointField"),4,1);
% names = {'x','y','z','rgb'}; offs = [0 4 8 12]; dtype = uint8(7); % FLOAT32
% for i=1:4
%     f(i).name = names{i};
%     f(i).offset = uint32(offs(i));
%     f(i).datatype = dtype;
%     f(i).count = uint32(1);
% end
% msg.fields = f;
% msg.is_bigendian = false;
% msg.height = uint32(1);
% msg.width  = uint32(0);
% msg.point_step = uint32(16);
% msg.row_step   = uint32(0);
% msg.is_dense   = false;
% msg.data = uint8([]);
% 
% send(pub, msg);
% end
% 
% function publishEllipsoidPointCloud(pub, node, U, S, p_ee, res, frame_id)
% % Build & publish sensor_msgs/PointCloud2 with x,y,z,rgb (FLOAT32)
% if ~(isequal(size(U),[3 3]) && isequal(size(S),[3 3]))
%     error('U and S must be 3x3.');
% end
% if numel(p_ee) ~= 3
%     error('p_ee must be 1x3 or 3x1.');
% end
% p_ee = reshape(p_ee,1,3);
% 
% % Unit sphere -> ellipsoid
% [xs,ys,zs] = sphere(res);          % (res+1)x(res+1)
% P  = [xs(:)'; ys(:)'; zs(:)']./2;  % 3xN (radius=0.5 for density)
% SP = S * P;         % 3xN
% E0 = U * SP;        % 3xN
% E  = E0 + p_ee.';   % 3xN
% 
% % Color by local radius
% r    = sqrt(sum(SP.^2,1));
% rmin = min(r); rmax = max(r);
% g    = (rmax>rmin) * ((r - rmin) / (rmax - rmin)) + (rmax==rmin) * ones(size(r));
% 
% xyz = single(E.');             % Nx3
% good = all(isfinite(xyz),2);
% xyz  = xyz(good,:);
% g    = g(good);
% N    = size(xyz,1);
% 
% R = uint8(255*(1 - g));
% G = uint8(255*g);
% B = uint8(0*g);
% rgb_u32 = uint32(R)*2^16 + uint32(G)*2^8 + uint32(B);
% rgb_f32 = typecast(rgb_u32,'single');
% 
% msg = ros2message(pub);
% msg.header.frame_id = frame_id;
% 
% % Define fields x,y,z,rgb (FLOAT32)
% f = repmat(ros2message("sensor_msgs/PointField"),4,1);
% names = {'x','y','z','rgb'}; offs = [0 4 8 12]; dtype = uint8(7); % FLOAT32
% for i=1:4
%     f(i).name = names{i};
%     f(i).offset = uint32(offs(i));
%     f(i).datatype = dtype;
%     f(i).count = uint32(1);
% end
% msg.fields = f;
% msg.is_bigendian = false;
% msg.height = uint32(1);
% msg.width  = uint32(N);
% msg.point_step = uint32(16);
% msg.row_step   = uint32(16 * N);
% msg.is_dense   = true;
% 
% A = [xyz.'; rgb_f32];                 % 4xN
% msg.data = typecast(A(:),'uint8');
% msg.header.stamp = ros2time(node,"now");
% 
% send(pub, msg);
% end
function success = JointStatesToRviz(JointConfiguration, ur_type, time, varargin)
%JOINTSTATESTORVIZ Publish joint states (ROS 2) and, optionally, manipulability
% ellipsoid to RViz. If a trajectory is given, optionally publish a yellow
% PointCloud2 of the end-effector path. Also supports clearing topics.
%
%   success = JointStatesToRviz(JointConfiguration, ur_type, time, Name,Value)
%
%   Inputs
%     JointConfiguration : [N x 6] or [1 x 6] joint angles (rad).
%     ur_type            : char, e.g. 'ur3e', 'ur5e', ...
%     time               : total duration [s] to play the N states. ([] okay)
%
%   Name-Value options (all optional):
%     'Ellipsoid'           : true|false            (default: false)
%     'EllipsoidKind'       : 'trans'|'rot'         (default: 'trans')
%     'EllipsoidResolution' : positive int          (default: 35)
%     'EllipsoidEvery'      : positive int          (default: 1 → send all)
%     'BaseFrame'           : char                  (default: 'base_link')
%     'ToolFrame'           : char                  (default: 'tool0')
%     'JointStateTopic'     : char                  (default: '/joint_states')
%     'EllipsoidTopic'      : char                  (default: '/manip_ellipsoid')
%     'Trajectory'          : true|false            (default: N>1)
%     'TrajectoryTopic'     : char                  (default: '/trajectory_path')
%     'PrecomputeEllipsoids': true|false|[]         (default: [] → auto true if Ellipsoid&&N>1)
%
%   Default for 'Trajectory':
%     - Single pose (N==1): false
%     - Trajectory (N>1):   true (unless explicitly passed as false)
%
%   (C) 2025

arguments
    JointConfiguration
    ur_type = []
    time double = []
end
arguments (Repeating)
    varargin
end

% ---- Default time from length ----
if isempty(time)
    time = (size(JointConfiguration,1) <= 1) * 1 + (size(JointConfiguration,1) > 1) * 5;
end
    if isempty(ur_type)
        ur_type = 'ur3e';
    end
% ---- Normalize JointConfiguration to [N x 6] ----
if size(JointConfiguration,2) ~= 6 && size(JointConfiguration,1) == 6
    JointConfiguration = JointConfiguration.'; % make row
end
if size(JointConfiguration,2) ~= 6
    error('JointConfiguration must have 6 columns.');
end
N = size(JointConfiguration,1);

% ---- Parse options ----
p = inputParser;
addParameter(p,'Ellipsoid',false,@(x)islogical(x)&&isscalar(x));
addParameter(p,'EllipsoidKind','trans',@(s)ischar(s)||isstring(s));
addParameter(p,'EllipsoidResolution',35,@(n)isnumeric(n)&&isscalar(n)&&n>2);
addParameter(p,'EllipsoidEvery',1,@(n)isnumeric(n)&&isscalar(n)&&n>=1);
addParameter(p,'BaseFrame','base_link',@(s)ischar(s)||isstring(s));
addParameter(p,'ToolFrame','tool0',@(s)ischar(s)||isstring(s));
addParameter(p,'JointStateTopic','/joint_states',@(s)ischar(s)||isstring(s));
addParameter(p,'EllipsoidTopic','/manip_ellipsoid',@(s)ischar(s)||isstring(s));
addParameter(p,'Trajectory',false,@(x)islogical(x)&&isscalar(x));           % may be overridden by default rule
addParameter(p,'TrajectoryTopic','/trajectory_path',@(s)ischar(s)||isstring(s));
addParameter(p,'PrecomputeEllipsoids',[],@(x)(islogical(x)&&isscalar(x))||isempty(x));
parse(p, varargin{:});
opt = p.Results;
opt.EllipsoidEvery = max(1, floor(opt.EllipsoidEvery)); % sanitize

% Apply default logic for 'Trajectory' only if user didn't pass it
useDefaultTraj = any(strcmp(p.UsingDefaults,'Trajectory'));
if useDefaultTraj
    doTrajectory = (N > 1);
else
    doTrajectory = logical(opt.Trajectory);
end

% Default for PrecomputeEllipsoids
if isempty(opt.PrecomputeEllipsoids)
    precompEll = (opt.Ellipsoid && N > 1);
else
    precompEll = logical(opt.PrecomputeEllipsoids);
end

success = false;

% ---------- Persistent ROS2 node & publishers ----------
persistent node jsPub ellPub trajPub jsMsg
try
    if isempty(node) || ~isvalid(node)
        node = ros2node("MatlabToRvizNode");
    end
    if isempty(jsPub) || ~isvalid(jsPub)
        jsPub = ros2publisher(node, char(opt.JointStateTopic), "sensor_msgs/JointState");
    end
    if isempty(ellPub) || ~isvalid(ellPub)
        ellPub = ros2publisher(node, char(opt.EllipsoidTopic), "sensor_msgs/PointCloud2");
    end
    if isempty(trajPub) || ~isvalid(trajPub)
        trajPub = ros2publisher(node, char(opt.TrajectoryTopic), "sensor_msgs/PointCloud2");
    end
    if isempty(jsMsg)
        jsMsg = ros2message(jsPub);
        jsMsg.name = {
            'shoulder_pan_joint';
            'shoulder_lift_joint';
            'elbow_joint';
            'wrist_1_joint';
            'wrist_2_joint';
            'wrist_3_joint'};
    end
catch ME
    warning('ROS 2 setup failed: %s', ME.message);
    return
end

% ---------- Load / cache UR model ----------
try
    mdlName = mapURTypeToRobotName(ur_type);
    model = loadrobot(mdlName, "DataFormat", "row", "Gravity", [0 0 -9.81]); %#ok<NASGU>
catch ME
    warning('Failed to load robot model for "%s": %s', ur_type, ME.message);
    return
end

% ---------- Clear topics if disabled ----------
if ~doTrajectory
    % Clear any previously displayed trajectory in RViz
    try, publishEmptyPointCloud(trajPub, node, char(opt.BaseFrame)); catch, end
end
if ~opt.Ellipsoid
    % Clear any previously displayed ellipsoid in RViz
    try, publishEmptyPointCloud(ellPub, node, char(opt.BaseFrame)); catch, end
end

% ---------- If requested, precompute & publish EE trajectory as yellow PointCloud2 ----------
if doTrajectory
    try
        pathXYZ = zeros(N,3,'single');
        for i = 1:N
            T_ee = getTransform(model, JointConfiguration(i,:), char(opt.ToolFrame), model.BaseName);
            pathXYZ(i,:) = single(T_ee(1:3,4)).';
        end
        publishPathPointCloud(trajPub, node, pathXYZ, char(opt.BaseFrame));  % yellow
    catch ME
        warning('Trajectory path publish failed: %s', ME.message);
    end
end

% ---------- Precompute ellipsoids (optional; default on for Ellipsoid && N>1) ----------
ellPayload = []; sendMask = [];
if precompEll
    try
        [xs,ys,zs] = sphere(opt.EllipsoidResolution);      % (res+1)x(res+1)
        P = single([xs(:)'; ys(:)'; zs(:)'])/2;            % 3xM, radius=0.5 for density
        sendMask = false(1,N);
        sendMask(1:opt.EllipsoidEvery:N) = true;
        sendMask(N) = true; % ensure last
        ellPayload = cell(1,N);   % each cell: struct('xyz' Nx3 single, 'rgb_f32' 1xN single)
        for k = find(sendMask)
            q  = JointConfiguration(k,:);
            J  = geometricJacobian(model, q, char(opt.ToolFrame));
            % Split J robustly into translational vs rotational
            if mean(vecnorm(J(1:3,:),2,2)) > mean(vecnorm(J(4:6,:),2,2))
                Jr = J(1:3,:); Jt = J(4:6,:);
            else
                Jt = J(1:3,:); Jr = J(4:6,:);
            end
            switch lower(opt.EllipsoidKind)
                case {'trans','t','translation','translational'}, Jx = Jt;
                case {'rot','r','rotation','rotational'},         Jx = Jr;
                otherwise,                                        Jx = Jt;
            end

            [U,S,~] = svd(Jx,'econ');   % 3x3
            T  = getTransform(model, q, char(opt.ToolFrame), model.BaseName);
            p  = single(T(1:3,4));
            SP = S * P;                  % 3xM
            E  = U * SP + p;             % 3xM

            % Color by local radius (red→green)
            r = sqrt(sum(SP.^2,1));
            rmin=min(r); rmax=max(r);
            if rmax>rmin, g = (r - rmin)/(rmax - rmin); else, g = ones(size(r)); end
            R=uint8(255*(1-g)); G=uint8(255*g); B=uint8(0*g);
            rgb_u32 = uint32(R)*2^16 + uint32(G)*2^8 + uint32(B);
            rgb_f32 = typecast(rgb_u32,'single');     % 1xM float32

            ellPayload{k} = struct('xyz', single(E.'), 'rgb_f32', rgb_f32);
        end
    catch ME
        warning('Precompute ellipsoids failed: %s', ME.message);
        ellPayload = []; sendMask = [];
    end
end

% ---------- Playback rate ----------
desiredRate = max(1e-3, N / time);
r = ros2rate(node, desiredRate);
reset(r);

% ---------- Main loop ----------
allOK = true;
for i = 1:N
    q = JointConfiguration(i,:);

    % Publish joint state
    try
        jsMsg.position = q;
        jsMsg.header.stamp = ros2time(node, 'now');
        send(jsPub, jsMsg);
    catch ME
        warning('JointStatesToRviz:PublishFailed', '%s', ME.message);
        allOK = false;
    end

    % Manipulability ellipsoid (optional, with decimation; prefers precomputed)
    if opt.Ellipsoid
        try
            sendThis = (mod(i-1, opt.EllipsoidEvery) == 0);
            % Also ensure the very last state is sent at least once
            if (i == N) && ~sendThis
                sendThis = true;
            end
            if sendThis
                if ~isempty(ellPayload) && ~isempty(sendMask) && sendMask(i) && ~isempty(ellPayload{i})
                    publishPrebuiltCloud(ellPub, node, ellPayload{i}.xyz, ellPayload{i}.rgb_f32, char(opt.BaseFrame));
                else
                    % Fallback: compute & publish on-the-fly (your known-good sender)
                    J = geometricJacobian(model, q, char(opt.ToolFrame));  % 6x6
                    if mean(vecnorm(J(1:3,:),2,2)) > mean(vecnorm(J(4:6,:),2,2))
                        Jr = J(1:3,:); Jt = J(4:6,:);
                    else
                        Jt = J(1:3,:); Jr = J(4:6,:);
                    end
                    switch lower(opt.EllipsoidKind)
                        case {'trans','t','translation','translational'}, Jx = Jt;
                        case {'rot','r','rotation','rotational'},         Jx = Jr;
                        otherwise,                                        Jx = Jt;
                    end
                    [U,S,~] = svd(Jx,'econ');   % 3x3
                    T_ee = getTransform(model, q, char(opt.ToolFrame), model.BaseName);
                    p_ee = T_ee(1:3,4).';        % 1x3
                    publishEllipsoidPointCloud(ellPub, node, U, S, p_ee, opt.EllipsoidResolution, char(opt.BaseFrame));
                end
            end
        catch ME
            warning('Ellipsoid publish failed: %s', ME.message);
            allOK = false;
        end
    end

    if N ~= 1
        waitfor(r);
    end
end

success = allOK;

end % function

% ===================== Helpers =====================

function name = mapURTypeToRobotName(ur_type)
switch lower(string(ur_type))
    case "ur3e",  name = 'universalUR3e';
    case "ur5e",  name = 'universalUR5e';
    case "ur10e", name = 'universalUR10e';
    case "ur3",   name = 'universalUR3';
    case "ur5",   name = 'universalUR5';
    case "ur10",  name = 'universalUR10';
    case "ur16e", name = 'universalUR16e';
    otherwise
        error('Unsupported ur_type "%s". Add mapping in mapURTypeToRobotName.', ur_type);
end
end

function publishPathPointCloud(pub, node, xyz, frame_id)
% Publish Nx3 EE path as yellow sensor_msgs/PointCloud2
if isempty(xyz), publishEmptyPointCloud(pub,node,frame_id); return, end
if size(xyz,2) ~= 3, error('xyz must be Nx3.'); end

xyz = single(xyz);
good = all(isfinite(xyz),2);
xyz  = xyz(good,:);
N    = size(xyz,1);

% Yellow RGB (255,255,0)
R = uint8(255*ones(1,N));
G = uint8(255*ones(1,N));
B = uint8(0*ones(1,N));
rgb_u32 = uint32(R)*2^16 + uint32(G)*2^8 + uint32(B);
rgb_f32 = typecast(rgb_u32,'single');   % 1xN

msg = ros2message(pub);
msg.header.frame_id = frame_id;

% Define fields x,y,z,rgb (FLOAT32)
f = repmat(ros2message("sensor_msgs/PointField"),1,4);
names = {'x','y','z','rgb'}; offs = [0 4 8 12]; dtype = uint8(7); % FLOAT32
for i=1:4
    f(i).name = names{i};
    f(i).offset = uint32(offs(i));
    f(i).datatype = dtype;
    f(i).count = uint32(1);
end
msg.fields = f;
msg.is_bigendian = false;
msg.height = uint32(1);
msg.width  = uint32(N);
msg.point_step = uint32(16);
msg.row_step   = uint32(16 * N);
msg.is_dense   = true;

A = [xyz.'; rgb_f32];      % 4xN
msg.data = typecast(A(:),'uint8');
msg.header.stamp = ros2time(node,"now");

send(pub, msg);
end

function publishEmptyPointCloud(pub, node, frame_id)
% Send an "empty" PointCloud2 to clear RViz display
msg = ros2message(pub);
msg.header.frame_id = frame_id;
msg.header.stamp = ros2time(node,"now");

% Keep the same field schema RViz expects (x,y,z,rgb as FLOAT32)
f = repmat(ros2message("sensor_msgs/PointField"),1,4);
names = {'x','y','z','rgb'}; offs = [0 4 8 12]; dtype = uint8(7); % FLOAT32
for i=1:4
    f(i).name = names{i};
    f(i).offset = uint32(offs(i));
    f(i).datatype = dtype;
    f(i).count = uint32(1);
end
msg.fields = f;
msg.is_bigendian = false;
msg.height = uint32(1);
msg.width  = uint32(0);
msg.point_step = uint32(16);
msg.row_step   = uint32(0);
msg.is_dense   = false;
msg.data = uint8([]);

send(pub, msg);
end

function publishEllipsoidPointCloud(pub, node, U, S, p_ee, res, frame_id)
% Build & publish sensor_msgs/PointCloud2 with x,y,z,rgb (FLOAT32)
if ~(isequal(size(U),[3 3]) && isequal(size(S),[3 3]))
    error('U and S must be 3x3.');
end
if numel(p_ee) ~= 3
    error('p_ee must be 1x3 or 3x1.');
end
p_ee = reshape(p_ee,1,3);

% Unit sphere -> ellipsoid
[xs,ys,zs] = sphere(res);          % (res+1)x(res+1)
P  = [xs(:)'; ys(:)'; zs(:)']./2;  % 3xN (radius=0.5 for density)
SP = S * P;         % 3xN
E0 = U * SP;        % 3xN
E  = E0 + p_ee.';   % 3xN

% Color by local radius
r    = sqrt(sum(SP.^2,1));
rmin = min(r); rmax = max(r);
g    = (rmax>rmin) * ((r - rmin) / (rmax - rmin)) + (rmax==rmin) * ones(size(r));

xyz = single(E.');             % Nx3
good = all(isfinite(xyz),2);
xyz  = xyz(good,:);
g    = g(good);
N    = size(xyz,1);

R = uint8(255*(1 - g));
G = uint8(255*g);
B = uint8(0*g);
rgb_u32 = uint32(R)*2^16 + uint32(G)*2^8 + uint32(B);
rgb_f32 = typecast(rgb_u32,'single');

msg = ros2message(pub);
msg.header.frame_id = frame_id;

% Define fields x,y,z,rgb (FLOAT32)
f = repmat(ros2message("sensor_msgs/PointField"),1,4);
names = {'x','y','z','rgb'}; offs = [0 4 8 12]; dtype = uint8(7); % FLOAT32
for i=1:4
    f(i).name = names{i};
    f(i).offset = uint32(offs(i));
    f(i).datatype = dtype;
    f(i).count = uint32(1);
end
msg.fields = f;
msg.is_bigendian = false;
msg.height = uint32(1);
msg.width  = uint32(N);
msg.point_step = uint32(16);
msg.row_step   = uint32(16 * N);
msg.is_dense   = true;

A = [xyz.'; rgb_f32];                 % 4xN
msg.data = typecast(A(:),'uint8');
msg.header.stamp = ros2time(node,"now");

send(pub, msg);
end

function publishPrebuiltCloud(pub, node, xyz, rgb_f32, frame_id)
% Publish a precomputed cloud with the same schema as above.
% xyz: Nx3 single, rgb_f32: 1xN single (packed 0xRRGGBB as float32)
if isempty(xyz)
    publishEmptyPointCloud(pub,node,frame_id); return
end
if size(xyz,2) ~= 3
    error('xyz must be Nx3.');
end
N = size(xyz,1);

msg = ros2message(pub);
msg.header.frame_id = frame_id;

f = repmat(ros2message("sensor_msgs/PointField"),1,4);
names = {'x','y','z','rgb'}; offs = [0 4 8 12]; dtype = uint8(7);
for i=1:4
    f(i).name = names{i};
    f(i).offset = uint32(offs(i));
    f(i).datatype = dtype;
    f(i).count = uint32(1);
end
msg.fields = f;
msg.is_bigendian = false;
msg.height = uint32(1);
msg.width  = uint32(N);
msg.point_step = uint32(16);
msg.row_step   = uint32(16 * N);
msg.is_dense   = true;

A = [single(xyz).'; rgb_f32];  % both float32
msg.data = typecast(A(:),'uint8');
msg.header.stamp = ros2time(node,"now");
send(pub,msg);
end
