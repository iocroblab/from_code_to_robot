function VisualizeWorkspace(radius, resolution)
% VisualizeWorkspace(radius, resolution)
% Publishes a colored sensor_msgs/PointCloud2 to RViz2 (frame: shoulder_link) showing:
%   - Sphere of radius       (RED, alpha=0.25)
%   - Sphere of radius/2     (GREEN, alpha=0.25)
%
% Inputs
%   radius      (double)   Workspace radius [m]
%   resolution  (optional) Density knob (higher => denser). Default: 20
%                          Interpreted as number of samples along theta.
%
% RViz2:
%   Fixed Frame: shoulder_link
%   Add display: PointCloud2
%   Topic: /workspace_cloud

    arguments
        radius (1,1) double {mustBeFinite}
        resolution (1,1) double {mustBeFinite} = 20
    end

    % Allow zeros but reject negatives
    if radius < 0 || resolution < 0
        error('radius and resolution must be >= 0');
    end

            % ---------- Persistent ROS 2 node + publisher ----------
    persistent node pub
    topic = "/workspace_cloud";

    if isempty(node) || ~isvalid(node)
        node = ros2node("/matlab_workspace_viz");
    end
    if isempty(pub) || ~isvalid(pub)
        pub = ros2publisher(node, topic, "sensor_msgs/PointCloud2");
    end

    % If either input is zero -> publish empty cloud to clear RViz
    if radius == 0 || resolution == 0
        msg = ros2message("sensor_msgs/PointCloud2");
        msg.header.frame_id = 'shoulder_link';
        msg.height       = uint32(1);
        msg.width        = uint32(0);
        msg.is_bigendian = false;
        msg.is_dense     = true;
        msg.fields       = makeFieldsXYZRGBA_charNames();
        msg.point_step   = uint32(16);
        msg.row_step     = uint32(0);
        msg.data         = uint8([]);
        send(pub, msg);
        return;
    end

    % Higher number => denser
    nTheta = max(8,  round(resolution));
    nPhi   = max(16, 2*nTheta);
    nLine  = max(2,  2*nTheta + 1);

    % ---------- Colors ----------
    RED   = uint8([255, 0,   0]);
    GREEN = uint8([0,   255, 0]);

    % ---------- Geometry ----------
    [pR, cR] = spherePointsCount(radius,   nTheta, nPhi, RED);
    [pG, cG] = spherePointsCount(radius/2, nTheta, nPhi, GREEN);

    P = [pR; pG];
    C = [cR; cG];

    % ---------- Build PointCloud2 ----------
    msg = ros2message("sensor_msgs/PointCloud2");

    % In your MATLAB version, this must be char
    msg.header.frame_id = 'shoulder_link';

    msg.height       = uint32(1);
    msg.width        = uint32(size(P,1));
    msg.is_bigendian = false;
    msg.is_dense     = true;

    msg.fields = makeFieldsXYZRGBA_charNames();

    msg.point_step = uint32(16); % 4 float32 fields
    msg.row_step   = uint32(msg.point_step) * msg.width;

    % Data layout: [x y z rgba] as float32 (with alpha)
    xyz  = single(P);
    rgba = packRGBAtoFloat32(C, 0.25);      % Nx1 single, alpha=0.25
    data = [xyz, rgba];               % Nx4 single

    % Pack into uint8 row vector
    bytes    = typecast(reshape(data.', 1, []), 'uint8');
    msg.data = bytes(:).';

    send(pub, msg);
end

% ======================================================================
function [P, C] = spherePointsCount(R, nTheta, nPhi, colorRGBu8)
% Generate points on sphere surface using count-based angular sampling.

    if R <= 0
        P = zeros(0,3);
        C = zeros(0,3,'uint8');
        return;
    end

    theta = linspace(0, pi,  nTheta);   % polar
    phi   = linspace(0, 2*pi, nPhi);    % azimuth

    [PHI, THETA] = meshgrid(phi, theta);

    x = R .* sin(THETA) .* cos(PHI);
    y = R .* sin(THETA) .* sin(PHI);
    z = R .* cos(THETA);

    P = [x(:), y(:), z(:)];
    C = repmat(uint8(colorRGBu8), size(P,1), 1);
end

% ======================================================================
function fields = makeFieldsXYZRGBA_charNames()
% Create sensor_msgs/PointField[] for x,y,z,rgba as FLOAT32.
% sensor_msgs/PointField datatype constants: FLOAT32 = 7

    FLOAT32 = uint8(7);

    fields(1) = ros2message('sensor_msgs/PointField');
    fields(2) = ros2message('sensor_msgs/PointField');
    fields(3) = ros2message('sensor_msgs/PointField');
    fields(4) = ros2message('sensor_msgs/PointField');

    fields(1).name     = 'x';
    fields(1).offset   = uint32(0);
    fields(1).datatype = FLOAT32;
    fields(1).count    = uint32(1);

    fields(2).name     = 'y';
    fields(2).offset   = uint32(4);
    fields(2).datatype = FLOAT32;
    fields(2).count    = uint32(1);

    fields(3).name     = 'z';
    fields(3).offset   = uint32(8);
    fields(3).datatype = FLOAT32;
    fields(3).count    = uint32(1);

    fields(4).name     = 'rgba';
    fields(4).offset   = uint32(12);
    fields(4).datatype = FLOAT32;
    fields(4).count    = uint32(1);
end

% ======================================================================
function rgbaFloat = packRGBAtoFloat32(C, alpha)
% Pack Nx3 uint8 RGB + alpha into PCL-style float32 rgba field.
% Stores uint32 0xAARRGGBB reinterpreted as float32.

    if nargin < 2, alpha = 1; end
    a = uint32(max(0, min(255, round(alpha*255))));

    C = uint32(C);
    rgbaU32 = bitshift(a,24) + bitshift(C(:,1),16) + bitshift(C(:,2),8) + C(:,3);
    rgbaFloat = typecast(rgbaU32, 'single');
end
