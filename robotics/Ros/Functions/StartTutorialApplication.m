function status = StartTutorialApplication(Application, varargin)
% StartTutorialApplication(Application, Name,Value, ...)
%
% Launch common ROS 2 applications in one of three environments:
%   1) Windows + Docker (via WSL)  -> uses "wsl docker ..."
%   2) Ubuntu + Docker            -> uses "docker ..."
%   3) Ubuntu native (Docker=false) -> opens gnome-terminal
%
% REQUIRED
%   Application : 'Rviz' | 'Simulation' | 'Teleoperation' | 'Trajectory' | ...
%                 'safety_nodes' | 'Hardware' | 'Terminal'
%
% OPTIONAL Name–Value inputs (case-insensitive names)
%   Robot selection:
%     'Model' | 'model' | 'ur_type' : default 'ur3e'
%       Accepts 'ur3e','ur5e','ur10e','ur16e','ur3','ur5','ur10'
%       Also accepts 'universalUR3e', 'UR5e', etc.
%       Special passthrough supported: 'threelink'
%
%   Workspace selection:
%     'workspace' | 'Workspace' | 'ws' | 'WS' : default 'fctr_ws'
%       Path can be absolute or relative to HOME. Used as terminal CWD (native)
%       and as the "cd" target inside the environment.
%
%   Controller selection (applies to Simulation and Hardware):
%     'controller' :
%          'Trajectory' (default) | 'Position' | 'Speed' | 'Torque' |
%         'scaled_joint_trajectory_controller' (or other ros native
%         controller name forward_..._controller)
%
%   Hardware driver inputs (Application == 'Hardware'):
%     'robot_ip'    : default '192.168.56.101' (always included)
%     'computer_ip' : default '' (mapped to reverse_ip; required only if Docker==true)
%     Alias accepted: 'reverse_ip'
%
%   Environment / terminal behavior:
%     'Docker'     : logical, default true
%     'DockerName' : char, default 'FCTR-container'
%     'Detach'     : logical
%
% RETURNS
%   status : system() return code of the launcher command (0 is success)

% ---------- Defaults ----------
opts.Model      = 'ur3e';
opts.Controller = 'Trajectory';
opts.Docker     = true;
opts.DockerName = 'FCTR-container';
opts.Workspace  = 'fctr_ws';
opts.RobotIP    = '192.168.56.101';
opts.ComputerIP = '';
opts.Detach     = false;

% ---------- Parse Name–Value ----------
if mod(numel(varargin),2)~=0
    error('Optional arguments must be Name–Value pairs.');
end

for k = 1:2:numel(varargin)
    name = lower(strtrim(string(varargin{k})));
    val  = varargin{k+1};

    switch name
        case {"model","ur_type"}
            opts.Model = char(val);

        case {"workspace","ws"}
            opts.Workspace = char(val);

        case "robot_ip"
            opts.RobotIP = char(val);

        case {"computer_ip","reverse_ip"}
            opts.ComputerIP = char(val);

        case {"trajectory","controller"}
            opts.Controller = char(val);

        case "docker"
            opts.Docker = logical(val);

        case "dockername"
            opts.DockerName = char(val);

        case "detach"
            opts.Detach = logical(val);

        otherwise
            error('Unknown option "%s".', name);
    end
end


wsPath    = opts.Workspace;
setupBash = 'install/setup.bash';

if startsWith(wsPath, filesep)
    wsAbs = wsPath;
else
    home = getenv('HOME'); if isempty(home), home = '~'; end
    wsAbs = fullfile(home, wsPath);
end

isWin = ispc;

ur_type = toURType(opts.Model);
controllerArg = buildControllerArg(opts.Controller);

[appCmd, appKind] = applicationRegistry(Application, ur_type, controllerArg);

if strcmp(appKind,'hardware')
    base = sprintf(['ros2 launch ur_robot_driver ur_control.launch.py ', ...
        'ur_type:=%s robot_ip:=%s'], ur_type, opts.RobotIP);

    if opts.Docker
        if isempty(strtrim(opts.ComputerIP))
            error('Hardware with Docker requires Name–Value: computer_ip (reverse_ip).');
        end
        base = sprintf('%s reverse_ip:=%s', base, opts.ComputerIP);
    end

    if ~isempty(strtrim(controllerArg))
        appCmd = sprintf('%s %s', base, controllerArg);
    else
        appCmd = base;
    end
end

innerParts = {
    sprintf('cd ~/%s', wsPath)
    'source /opt/ros/jazzy/setup.bash'
    sprintf('source %s', setupBash)
};

if ~isempty(strtrim(appCmd))
    innerParts{end+1} = appCmd; %#ok<AGROW>
end

inner = strjoin(innerParts, '; ');
innerQuoted = sprintf('bash -lc "%s; exec bash"', escapeForBashLC(inner));

if opts.Docker
    ensureDockerRunning(opts.DockerName, isWin);
end

launcher = buildLauncher(opts, isWin, wsAbs, inner, innerQuoted);

status = system(launcher);
if status ~= 0
    warning('Launcher returned non-zero status: %d\nCommand:\n%s', status, launcher);
end

% ====================== HELPERS ======================
    function ur = toURType(modelOrName)
        m = lower(strrep(strtrim(string(modelOrName)),' ',''));
        switch m
            case {'ur3e','universalur3e'},    ur = 'ur3e';
            case {'ur5e','universalur5e'},    ur = 'ur5e';
            case {'ur10e','universalur10e'},  ur = 'ur10e';
            case {'ur16e','universalur16e'},  ur = 'ur16e';
            case {'ur3','universalur3'},      ur = 'ur3';
            case {'ur5','universalur5'},      ur = 'ur5';
            case {'ur10','universalur10'},    ur = 'ur10';
            case {'threelink'},               ur = 'threelink';
            otherwise
                if startsWith(m,"ur")
                    ur = char(m);
                else
                    error('Unsupported model or ur_type "%s".', modelOrName);
                end
        end
    end

    function arg = buildControllerArg(ctrl)
        c = lower(strtrim(string(ctrl)));
        if c == ""
            arg = '';
            return;
        end

        switch c
            case {"position","forward_position_controller"}
                arg = 'initial_joint_controller:=forward_position_controller';
            case {"speed","velocity","forward_velocity_controller"}
                arg = 'initial_joint_controller:=forward_velocity_controller';
            case {"torque","effort","forward_effort_controller"}
                arg = 'initial_joint_controller:=forward_effort_controller';
            case {"trajectory","scaled","scaled_joint_trajectory_controller"}
                arg = 'initial_joint_controller:=scaled_joint_trajectory_controller';
            otherwise
                error('Unknown Trajectory/controller value "%s".', ctrl);
        end
    end

    function [cmd, kind] = applicationRegistry(app, ur, carg)
        a = lower(strtrim(string(app)));
        kind = 'normal';

        switch a
            case "rviz"
                cmd = sprintf('ros2 launch ur_description view_ur.launch.py ur_type:=%s', ur);

            case "simulation"
                if strcmpi(ur,'threelink')
                    base = 'ros2 launch threelink_manipulator spawn_robot.launch.py';
                else
                    base = sprintf('ros2 launch ur_simulation_gz ur_sim_control.launch.py ur_type:=%s', ur);
                end
                cmd = base;
                if ~isempty(strtrim(carg))
                    cmd = sprintf('%s %s', base, carg);
                end

            case "hardware"
                cmd  = '';
                kind = 'hardware';

            case "teleoperation"
                cmd = 'ros2 run tutorialteleop tutorial_teleop';

            case "trajectory"
                cmd = 'ros2 run trajectory_tracker track_trajectory';

            case "safety_nodes"
                if strcmpi(ur,'threelink')
                    cmd = 'ros2 run safety_nodes safety_nullifier num_joints:=3';
                else
                    cmd = 'ros2 run safety_nodes safety_nullifier';
                end

            case "terminal"
                cmd = '';
                kind = 'terminal';

            otherwise
                error('Unknown Application "%s".', app);
        end
    end

    function ensureDockerRunning(dockerName, isWinLocal)
        if isWinLocal
            system(sprintf('wsl docker start %s', dockerName));
        else
            system(sprintf('docker start %s', dockerName));
        end
        pause(0.2);
    end

    function s = escapeForBashLC(s)
        s = strrep(s, '"', '\"');
    end

    function launcher = buildLauncher(o, isWinLocal, wsAbsLocal, innerLocal, innerQuotedLocal)
        if o.Docker
            if isWinLocal
                if o.Detach
                    launcher = sprintf('wsl docker exec -dit %s %s', o.DockerName, innerQuotedLocal);
                else
                    launcher = sprintf(['cmd /c start "" wsl bash -lc ', ...
                        '"docker exec -it %s bash -lc ''%s; exec bash''"'], ...
                        o.DockerName, escapeForBashLC(innerLocal));
                end
            else
                if o.Detach
                    launcher = sprintf('docker exec -d %s bash -lc %s', o.DockerName, innerQuotedLocal);
                else
                    innerUnwrapped = regexprep(innerQuotedLocal, '^bash -lc\s+"(.*)"$', '$1');
                    launcher = sprintf(['env -u LD_LIBRARY_PATH gnome-terminal -- bash -lc ', ...
                        '"xhost +local:docker; docker exec -it %s bash -lc ''%s''; exec bash" &'], ...
                        o.DockerName, innerUnwrapped);
                end
            end
        else
            if isWinLocal
                error('Windows without Docker is not supported. Use ''Docker'', true.');
            end
            launcher = sprintf( ...
                'env -u LD_LIBRARY_PATH gnome-terminal --working-directory="%s" -- %s &', ...
                wsAbsLocal, innerQuotedLocal);
        end
    end
end