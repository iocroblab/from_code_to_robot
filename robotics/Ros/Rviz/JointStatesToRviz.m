function success = JointStatesToRviz(JointConfiguration, ur_type, time, varargin)
%JOINTSTATESTORVIZ Publish joint states (ROS 2) and, optionally, manipulability ellipsoid to RViz.
%   success = JointStatesToRviz(JointConfiguration, ur_type, time, Name,Value)
%
%   Inputs
%     JointConfiguration : [N x 6] or [1 x 6] joint angles (rad).
%     ur_type            : char, e.g. 'ur3e', 'ur5e', ... (ROS 2 naming).
%     time               : total duration [s] to play the N states.
%
%   Name-Value options (all optional):
%     'PlotManipulabilityEllipsoid' : true|false   (default: true)
%     'EllipsoidKind'               : 'trans'|'rot' (default: 'trans')
%     'EllipsoidResolution'         : positive int (default: 25)
%     'BaseFrame'                   : char (default: 'base_link')
%     'ToolFrame'                   : char (default: 'tool0')
%     'JointStateTopic'             : char (default: '/joint_states')
%     'EllipsoidTopic'              : char (default: '/manip_ellipsoid')
%
%   Output
%     success : logical true if all publishes succeeded.
%
%   Notes
%     - Uses a single ROS 2 node (persistent) for both publishers.
%     - Automatically launches RViz/UR description as in your original code.
%     - Ellipsoid colors encode local radius (low=red → high=green).
%
%   Requires:
%     - Robotics System Toolbox (for loadrobot, geometricJacobian, getTransform)
%     - Your helper StartIfNotRunning(...)
%
%   (C) 2025

arguments
    JointConfiguration
    ur_type char = 'ur3e'
    time double = []          % allow []
end

% ---- This makes the function line and arguments block consistent ----
arguments (Repeating)
    varargin
end

% ---- Handle default time depending on trajectory length ----
if isempty(time)
    if size(JointConfiguration,1) <= 1
        time = 1;   % single pose → arbitrary (rate loop won't wait)
    else
        time = 5;   % default total time for a trajectory
    end
end

% ---- Parse Name-Value pairs (example set; keep your existing parser) ----
p = inputParser;
addParameter(p,'Ellipsoid',false,@(x)islogical(x)&&isscalar(x));
addParameter(p,'EllipsoidKind','trans',@(s)ischar(s)||isstring(s));
addParameter(p,'EllipsoidResolution',35,@(n)isnumeric(n)&&isscalar(n)&&n>2);
addParameter(p,'BaseFrame','base_link',@(s)ischar(s)||isstring(s));
addParameter(p,'ToolFrame','tool0',@(s)ischar(s)||isstring(s));
addParameter(p,'JointStateTopic','/joint_states',@(s)ischar(s)||isstring(s));
addParameter(p,'EllipsoidTopic','/manip_ellipsoid',@(s)ischar(s)||isstring(s));
parse(p, varargin{:});
opt = p.Results;

success = false;

% % ---------- Launch RViz/UR description if needed ----------
% if isunix % only auto-start on Ubuntu
%     promt = strcat(['cd Ros/Repo/; ' ...
%         'source install/setup.bash; ' ...
%         'ros2 launch ur_description view_ur.launch.py ur_type:=', ur_type]);
%     StartIfNotRunning('view_ur\.launch\.py', promt);
% elseif ispc
%     promt = strcat('wsl docker exec -dit gz-modified bash -c "cd Ros/Repo && source install/setup.bash && ros2 launch ur_description view_ur.launch.py ur_type:=', ur_type, '"');
%     StartIfNotRunning('view_ur\.launch\.py', promt, "windows");
% end

% ---------- Persistent ROS2 node & publishers ----------
persistent node jsPub pclPub jsMsg
try
    if isempty(node) || ~isvalid(node)
        node = ros2node("MatlabToRvizNode");
    end
    if isempty(jsPub) || ~isvalid(jsPub)
        jsPub = ros2publisher(node, char(opt.JointStateTopic), "sensor_msgs/JointState");
    end
    if isempty(pclPub) || ~isvalid(pclPub)
        pclPub = ros2publisher(node, char(opt.EllipsoidTopic), "sensor_msgs/PointCloud2");
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
        mdlName = mapURTypeToRobotName(ur_type);                 % 'universalUR3e', etc.
        model = loadrobot(mdlName, "DataFormat", "row", "Gravity", [0 0 -9.81]); %#ok<NASGU>
        % setappdata(model,'__ur_type__',ur_type);                 % tag cache with current ur_type
    
catch ME
    warning('Failed to load robot model for "%s": %s', ur_type, ME.message);
    return
end

% ---------- Normalize JointConfiguration to [N x 6] ----------
if size(JointConfiguration,2) ~= 6 && size(JointConfiguration,1) == 6
    JointConfiguration = JointConfiguration.'; % make row
end
if size(JointConfiguration,2) ~= 6
    error('JointConfiguration must have 6 columns.');
end
N = size(JointConfiguration,1);

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

    % Manipulability ellipsoid (optional)
    if opt.Ellipsoid
        try
            % Jacobian in BASE frame (6x6)
            J = geometricJacobian(model, q, char(opt.ToolFrame));  % w.r.t. model.BaseName
            % MATLAB order is [angular; linear] or [linear; angular]?
            % For RBT: geometricJacobian returns [angular; linear] -> check and adapt
            % We need translational J_t as rows 4:6 if using [linear; angular] format.
            % To be robust, infer by norm heuristic:
            if size(J,1) == 6
                % Heuristic: columns magnitudes of top vs bottom blocks near rotational vs translational
                if mean(vecnorm(J(1:3,:),2,2)) > mean(vecnorm(J(4:6,:),2,2))
                    Jr = J(1:3,:); Jt = J(4:6,:);
                else
                    % swap if toolbox returns [linear; angular]
                    Jt = J(1:3,:); Jr = J(4:6,:);
                end
            else
                error('Unexpected Jacobian size.');
            end

            switch lower(opt.EllipsoidKind)
                case {'trans','t','translation','translational'}
                    Jx = Jt;
                case {'rot','r','rotation','rotational'}
                    Jx = Jr;
                otherwise
                    Jx = Jt; % default
            end

            % SVD of selected block
            [U,S,~] = svd(Jx,'econ');   % 3x3
            % EE pose (base -> tool)
            T_ee = getTransform(model, q, char(opt.ToolFrame), model.BaseName);
            p_ee = T_ee(1:3,4).';        % 1x3

            % Publish PointCloud2
            publishEllipsoidPointCloud(pclPub, node, U, S, p_ee, opt.EllipsoidResolution, char(opt.BaseFrame));
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
% Map ROS 2 'ur_type' (e.g., 'ur3e') to Robotics System Toolbox model name.
switch lower(string(ur_type))
    case "ur3e",  name = 'universalUR3e';
    case "ur5e",  name = 'universalUR5e';
    case "ur10e", name = 'universalUR10e';
    case "ur3",  name = 'universalUR3';
    case "ur5",  name = 'universalUR5';
    case "ur10", name = 'universalUR10';
    case "ur16e", name = 'universalUR16e';
    otherwise
        error('Unsupported ur_type "%s". Add mapping in mapURTypeToRobotName.', ur_type);
end
end

function tf = isvalidRigidBodyTree(rbt)
tf = isa(rbt,'rigidBodyTree') && ~isempty(rbt.BodyNames) && isprop(rbt,'DataFormat');
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

% Unit sphere (columns are unit directions)
[xs,ys,zs] = sphere(res);          % (res+1)x(res+1)
P  = [xs(:)'; ys(:)'; zs(:)']./2;  % 3xN (radius=0.5 for density)

SP = S * P;         % 3xN
E0 = U * SP;        % 3xN
E  = E0 + p_ee.';   % 3xN

% Color by local radius
r    = sqrt(sum(SP.^2,1));
rmin = min(r); rmax = max(r);
if rmax > rmin
    g = (r - rmin) / (rmax - rmin);
else
    g = ones(size(r));
end

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
f = repmat(ros2message("sensor_msgs/PointField"),4,1);
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
msg.point_step = uint32(16);          % 4 fields * 4 bytes
msg.row_step   = uint32(16 * N);
msg.is_dense   = true;

A = [xyz.'; rgb_f32];                 % 4xN
msg.data = typecast(A(:),'uint8');
msg.header.stamp = ros2time(node,"now");

if msg.width == 0 || isempty(msg.data)
    warning('PointCloud2 is empty; not sending.');
    return
end
send(pub, msg);
end
