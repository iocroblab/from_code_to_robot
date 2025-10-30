
```matlab

% Joint-space torque control tracking a Cartesian circular path via IK.
% Circle lies in base XY at fixed Z and fixed orientation (initial EE pose).

    %================== Logging ==================%
    qstorage = []; qdstorage = []; tau_storage = [];

    %================== Gains & limits ==================%
    Kp = diag([90 90 70 45 30 18]);
    Kd = diag([18 18 12  8  6  3.6]);
    tau_lim = [150,150,150,28,28,28]';

    %================== Timing & gravity ==================%
    dt = 0.01;                      % 100 Hz
    g  = [0 0 -9.81];
    r  = rateControl(1/dt);

    %================== Robot model ==================%
    model = 'ur5e';
    robot = importrobot("robotics/Ros/src/ur5e.urdf", DataFormat="column");
    robot.Gravity = g;

    % End-effector body name (robust fallback to last body)
    eeName = "tool0";
    if ~any(strcmp(robot.BodyNames, eeName))
        eeName = robot.BodyNames{end};
    end

    %================== Circle parameters ==================%
    T_total = 12.0;                  % seconds for one full circle
    n_cycles = 1;                    % how many circles to run
    T_sim   = n_cycles * T_total;    % total duration
    radius  = 0.06;                  % meters
    % Center & Z/orientation are taken from the initial EE pose

    %================== IK solver ==================%
    ik = inverseKinematics('RigidBodyTree', robot);
    % Weights: [xyz  rpy] — keep orientation relatively stiff
    ikWeights = [1 1 1 2 2 2];
    ikMaxIter = 50;

    %================== Initialize ==================%
    [q_meas, qd_meas, ~] = GetJointValues('All');
```

```matlabTextOutput
Error using GetJointValues (line 41)
No /joint_states message received within 5.0 s.
```

```matlab
    q_meas = q_meas(:); qd_meas = qd_meas(:);

    T_init = getTransform(robot, q_meas, eeName);     % 4x4 SE(3)
    p0     = tform2trvec(T_init);                     % [x y z]
    q0quat = tform2quat(T_init);                      % orientation frozen

    % Circle center = initial XY, keep initial Z
    centerXY = p0(1:2);
    zFixed   = p0(3);

    % Desired joint history for finite-difference velocities/accels
    qd_prev2 = q_meas;    % two steps back
    qd_prev1 = q_meas;    % one step back

    t0 = tic; count = 0;

    try
        while toc(t0) < T_sim
            t = toc(t0);

            % 1) Measure current state
            [q, q_dot, ~] = GetJointValues('All');
            q = q(:); q_dot = q_dot(:);

            % 2) Desired Cartesian pose on the circle
            theta = 2*pi * (t / T_total);             % uniform speed
            pd_xy = centerXY + radius * [cos(theta), sin(theta)];
            pd    = [pd_xy, zFixed];                   % desired position
            Td    = trvec2tform(pd) * quat2tform(q0quat);   % fixed orientation

            % 3) IK (use previous desired q as initial guess for continuity)
            if count == 0
                q_seed = q;   % first iteration: start from measured q
            else
                q_seed = qd_prev1;
            end
            [qd, ~] = ik(eeName, Td, ikWeights, q_seed, ...
                         'MaxIterations', ikMaxIter);

            % 4) Numerical derivatives for feed-forward
            if count < 2
                qd_dot  = zeros(6,1);
                qd_ddot = zeros(6,1);
            else
                qd_dot  = (qd - qd_prev1) / dt;
                qd_ddot = (qd - 2*qd_prev1 + qd_prev2) / dt^2;
            end

            % 5) Dynamics at current state
            M = massMatrix(robot, q);
            h = velocityProduct(robot, q, q_dot);
            G = gravityTorque(robot, q);

            % 6) Errors
            e  = qd - q;
            ed = qd_dot - q_dot;

            % 7) Computed-torque control
            v   = qd_ddot + Kd*ed + Kp*e;
            tau = M*v + h + G;

            % 8) Saturation
            tau_sat = min(max(tau, -tau_lim), tau_lim);

            % 9) Send torques
            SendJointTorques(tau_sat);

            % 10) Viz every ~0.2 s
            if mod(count, 20) == 0
                JointStatesToRviz(q, model, [], ...
                    'Ellipsoid', true, ...
                    'EllipsoidResolution', 15, ...
                    'EllipsoidDuality', 'Force', ...
                    'SendJointStates', false);
            end

            % 11) Log & shift history
            qstorage    = [qstorage, q];
            qdstorage   = [qdstorage, q_dot];
            tau_storage = [tau_storage, tau_sat];

            qd_prev2 = qd_prev1;
            qd_prev1 = qd;

            count = count + 1;
            waitfor(r);
        end
    catch ME
        warning('[TrackUR_CartesianCircle_PDplus] Error: %s', ME.message);
    end

    % Safe stop
    try, SendJointTorques(zeros(6,1)); end

    % Plot
    try, plotTrajectory(qstorage, qdstorage, tau_storage); end

```
