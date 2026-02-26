function success = SwitchControllers(mode, varargin)
% SwitchControllers(mode, Name,Value,...)
%
% Switch ros2_control controllers using the ros2 CLI:
%   ros2 control switch_controllers --activate <TARGET> --deactivate <OTHERS>
%
% MODE mapping:
%   "position"                 -> forward_position_controller
%   "velocity" / "speed"       -> forward_velocity_controller
%   "trajectory" / "scaled"    -> scaled_joint_trajectory_controller
%   "effort" / "torque"        -> forward_effort_controller
%   or pass the full controller name directly (e.g. "forward_velocity_controller")
%
% Name–Value:
%   'Docker'     : logical (default true)
%   'DockerName' : char    (default 'gz-modified')
%
% 

    % ---------- Defaults ----------
    opts.Docker     = true;
    opts.DockerName = 'gz-modified';
    opts.Strict     = true;
    opts.Debug      = false;   % NEW (default false)

    % ---------- Parse Name–Value ----------
    if mod(numel(varargin),2) ~= 0
        error('Optional arguments must be Name–Value pairs.');
    end
    for k = 1:2:numel(varargin)
        name = lower(string(varargin{k}));
        val  = varargin{k+1};
        switch name
            case "docker"
                opts.Docker = logical(val);
            case "dockername"
                opts.DockerName = char(val);
            case "strict"
                opts.Strict = logical(val);
            case "debug"                % NEW
                opts.Debug = logical(val);
            otherwise
                error('Unknown option "%s".', name);
        end
    end

    % ---------- Controller list (control controllers only) ----------
    controllers = { ...
        'forward_position_controller', ...
        'forward_velocity_controller', ...
        'scaled_joint_trajectory_controller', ...
        'forward_effort_controller' ...
    };

    % ---------- Mapping ----------
    target = mapModeToController(mode);
    deactivate = controllers(~strcmp(controllers, target));

    % ---------- Build ros2 command ----------
    ros2Cmd = sprintf('ros2 control switch_controllers --activate %s --deactivate %s ', ...
        target, strjoin(deactivate, ' '));

    % ---------- Script ----------
    if opts.Debug
        % Keep terminal open
        script = sprintf([ ...
            'source /opt/ros/jazzy/setup.bash; ' ...
            '%s; ' ...
            'echo ""; echo "[DEBUG] Press ENTER to close..."; read dummy' ], ros2Cmd);
    else
        % Original behavior
        script = sprintf([ ...
            'source /opt/ros/jazzy/setup.bash; ' ...
            '%s; ' ...
            'sleep 1; ' ...
            'exit 0' ], ros2Cmd);
    end

    % ---------- Build launcher ----------
    if opts.Docker
        ensureDockerRunning(opts.DockerName);

        if ispc
            innerWSL = sprintf('docker exec -it %s bash -lc ''%s''', ...
                opts.DockerName, script);

            launcher = sprintf('cmd /c start "" wsl bash -lc "%s"', ...
                escapeForBashLC(innerWSL));
        else
            inner = sprintf('docker exec -it %s bash -lc ''%s''', ...
                opts.DockerName, script);

            launcher = sprintf('env -u LD_LIBRARY_PATH gnome-terminal -- bash -lc "%s" &', ...
                escapeForBashLC(inner));
        end
    else
        if ispc
            error('Windows without Docker is not supported.');
        end

        launcher = sprintf('env -u LD_LIBRARY_PATH gnome-terminal -- bash -lc "%s" &', ...
            escapeForBashLC(script));
    end

    % ---------- Execute ----------
    clear SendJointSpeeds SendJointTrajectory SendJointTorques SendJointPositions

    [status,~] = system(launcher);
    success = (status == 0);

    if ~success
        warning('Launcher failed (status %d)\n%s', status, launcher);
    end
end

% ====================== Helpers ======================

function target = mapModeToController(mode)
    if ~(ischar(mode) || isStringScalar(mode) || isstring(mode))
        error('mode must be char or string.');
    end
    m = lower(strtrim(string(mode)));

    % If user already passed full name, accept it directly
    if contains(m, "_controller")
        target = char(m);
        return;
    end

    switch m
        case "position"
            target = 'forward_position_controller';
        case {"velocity","speed"}
            target = 'forward_velocity_controller';
        case {"trajectory","scaled"}
            target = 'scaled_joint_trajectory_controller';
        case {"effort","torque"}
            target = 'forward_effort_controller';
        otherwise
            disp('Unknown mode "%s". Use position/velocity/speed/trajectory/scaled/effort/torque. Trying "%s" as a controller', m,m);
            target = m; 

    end
end

function ensureDockerRunning(name)
    if ispc
        cmd = sprintf('wsl docker start %s', name);
    else
        cmd = sprintf('docker start %s', name);
    end
    system(cmd); pause(0.3);
end

function s = escapeForBashLC(s)
    s = strrep(s, '"','\"');
end
