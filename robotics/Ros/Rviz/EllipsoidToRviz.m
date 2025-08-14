function success = EllipsoidToRviz(U, S, p_ee, res)
% Publish SVD-based manipulability ellipsoid to RViz (ROS 2) as PointCloud2.
%   success = PublishManipulabilityEllipsoid(U, S, p_ee, res)
% Inputs:
%   U,S   : from [U,S,~] = svd(J_t,'econ'), with J_t = J(4:6,:) (BASE frame)
%   p_ee  : 3x1 or 1x3 end-effector position in BASE frame (center of ellipsoid)
%   res   : sphere resolution (optional, default 50)
% Output:
%   success : true iff the PointCloud2 was constructed and sent

    if nargin < 4 || isempty(res), res = 25; end
    success = false;

    % ---- Validate inputs
    if ~isequal(size(U),[3 3]) || ~isequal(size(S),[3 3])
        error('U and S must be 3x3 from svd(J_t).');
    end
    if numel(p_ee) ~= 3
        error('p_ee must be 3x1 or 1x3 in base_link coordinates.');
    end
    p_ee = reshape(p_ee,1,3);   % 1x3

    % ---- Unit sphere (columns are unit directions)
    [xs,ys,zs] = sphere(res);             % (res+1)x(res+1)
    P  = [xs(:)'; ys(:)'; zs(:)']./2;        % 3xN

    % ---- Ellipsoid in base frame: E0 = U*S*P; shift by p_ee
    SP = S * P;                           % 3xN
    E0 = U * SP;                          % 3xN
    E  = E0 + p_ee.';                     % 3xN (centered at EE)

    % ---- Directional "radius" per vertex r = ||S*s||
    r    = sqrt(sum(SP.^2,1));            % 1xN
    rmin = min(r); rmax = max(r);
    if rmax > rmin
        g = (r - rmin) / (rmax - rmin);   % 0..1  (low->0 red, high->1 green)
    else
        g = ones(size(r));
    end

    % ---- Pack XYZ and packed RGB for PointCloud2
    xyz = single(E.');                    % Nx3
    good = all(isfinite(xyz),2);
    xyz  = xyz(good,:);
    g    = g(good);
    N    = size(xyz,1);

    R = uint8(255*(1 - g)); G = uint8(255*g); B = uint8(0*g);
    rgb_u32 = uint32(R)*2^16 + uint32(G)*2^8 + uint32(B);
    rgb_f32 = typecast(rgb_u32,'single');     % 1xN float32

    % ---- Optional sanity check: estimated center ≈ p_ee
    center_est = mean(xyz,1);
    center_err = norm(center_est - p_ee);
    if center_err > 1e-6
        warning('Ellipsoid center check: |mean - p_ee| = %.3g (frames correct?)', center_err);
    end

    % ---- ROS 2 node & publisher
    persistent node pub
    try
        if isempty(node) || ~isvalid(node)
            node = ros2node("/matlab_pcl_node");
        end
        if isempty(pub) || ~isvalid(pub)
            pub  = ros2publisher(node, "/pointcloud2", "sensor_msgs/PointCloud2");
        end
    catch ME
        warning("ROS 2 setup failed: %s", ME.message);
        return;
    end

    % ---- Build sensor_msgs/PointCloud2 (x,y,z,rgb as FLOAT32)
    try
        msg = ros2message(pub);
        msg.header.frame_id = 'base_link';

        % Define fields explicitly
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

        % Interleave and pack to uint8
        A = [xyz.'; rgb_f32];                 % 4xN
        msg.data = typecast(A(:),'uint8');

        % Timestamp
        msg.header.stamp = ros2time(node,"now");

        % Send
        if msg.width == 0 || isempty(msg.data)
            warning('PointCloud2 message is empty; not sending.');
            return;
        end
        send(pub, msg);
        success = true;

    catch ME
        warning("Failed to publish PointCloud2: %s", ME.message);
        success = false;
    end
end