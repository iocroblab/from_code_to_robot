function StartTutorialApplication(Application, varargin)
% StartTutorialApplication(Application, Name,Value, ...)
% Minimal, de-duplicated launcher for ROS 2 apps across:
%   • Windows + Docker (WSL)  → uses "wsl docker ..."
%   • Ubuntu + Docker         → uses "docker ..."
%   • Ubuntu native           → opens gnome-terminal (Docker=false)
%
% REQUIRED
%   Application  : 'Rviz' | 'Simulation' | 'Teleoperation' | <custom>
%
% OPTIONAL (Name–Value)
%   'Model'      : default 'ur3e' (accepts 'ur3e' or 'universalUR3e')
%   'Controller' : '' | 'Speed' | 'Torque' | 'Position'
%                  'Position' → adds initial_joint_controller:=forward_position_controller
%   'Docker'     : logical, default true
%   'DockerName' : char, default 'MatlabTutorialDocker'
%   'Detach" : logical, default true

% ---------- Defaults ----------
opts.Model      = 'ur3e';
opts.Controller = '';
opts.Docker     = true;
opts.DockerName = 'gz-modified';
if strcmp(Application, 'Rviz')
    opts.Detach = true; 
else
    opts.Detach = false; 
end

% ---------- Parse Name–Value ----------
if mod(numel(varargin),2)~=0
    error('Optional arguments must be Name–Value pairs.');
end
for k=1:2:numel(varargin)
    name = lower(string(varargin{k}));
    val  = varargin{k+1};
    switch name
        case "model",       opts.Model      = char(val);
        case "controller",  opts.Controller = char(val);
        case "docker",      opts.Docker     = logical(val);
        case "dockername",  opts.DockerName = char(val);
        case "detach",      opts.Detach    = logical(val);
        otherwise, error('Unknown option "%s".', name);
    end
end

% ---- Workspace settings (adjust if needed) ----
wsPath    = 'git_ws';
setupBash = 'install/setup.bash';

% Make workspace absolute for terminal working dir
if startsWith(wsPath, filesep)      % already absolute like '/git_ws'
    wsAbs = wsPath;
else
    home  = getenv('HOME'); if isempty(home), home = '~'; end
    wsAbs = fullfile(home, wsPath); % e.g. '/home/user/git_ws'
end
% -----------------------------------------------

% Platform prefix: Windows→'wsl ', Ubuntu→''
prefix = '';
if ispc, prefix = 'wsl '; end

% Normalize model to ROS ur_type
ur_type = toURType(opts.Model);

% Build controller arg
controllerArg = buildControllerArg(opts.Controller);

% Resolve Application → ROS command
appCmd = applicationRegistry(Application, ur_type, controllerArg);
if isempty(appCmd), error('Unknown Application "%s".', Application); end

% Command to run INSIDE the ROS environment
inner = strjoin({ ...
    sprintf('cd %s', wsPath), ...
    sprintf('source %s', setupBash), ...
    appCmd ...
    }, '; ');
innerQuoted = sprintf('bash -lc "%s; exec bash"', escapeForBashLC(inner));

% If Docker=true → try to start docker & container unconditionally (idempotent)
if opts.Docker
    ensureDockerRunning(opts.DockerName); 
end

% Build the final launcher
if opts.Docker
    if ispc
        if opts.Detach
            % headless: fine to use exec directly
            launcher = sprintf('wsl docker exec -dit %s %s', opts.DockerName, innerQuoted);
        else
            % interactive: open a new Windows console so a TTY exists
            % keep shell open via exec bash
            launcher = sprintf(['cmd /c start "" wsl bash -lc ', ...
                '"docker exec -it %s bash -lc ''%s; exec bash''"'], ...
                opts.DockerName, escapeForBashLC(inner));
        end
    else
        % Ubuntu host
        if opts.Detach
            launcher = sprintf('docker exec -dit %s %s', opts.DockerName, innerQuoted);
        else
            % interactive on Ubuntu: spawn a terminal to get a TTY
            launcher = sprintf('env -u LD_LIBRARY_PATH gnome-terminal -- %s &', innerQuoted);
        end
    end
else
    % Native Ubuntu (no Docker)
    if ispc
        error('Windows without Docker is not supported. Use ''Docker'', true.');
    end
  
    launcher = sprintf('env -u LD_LIBRARY_PATH gnome-terminal --working-directory="%s" -- %s &', wsAbs, innerQuoted);

end


status = system(launcher);
if status~=0
    warning('Launcher returned non-zero status: %d\nCommand:\n%s', status, launcher);
end

% ====================== NESTED HELPERS ======================
    function ur = toURType(modelOrName)
        m = lower(strrep(modelOrName,' ',''));
        switch m
            case {'ur3e','universalur3e'},    ur='ur3e';
            case {'ur5e','universalur5e'},    ur='ur5e';
            case {'ur10e','universalur10e'},  ur='ur10e';
            case {'ur16e','universalur16e'},  ur='ur16e';
            case {'ur3','universalur3'},      ur='ur3';
            case {'ur5','universalur5'},      ur='ur5';
            case {'ur10','universalur10'},    ur='ur10';
            otherwise, error('Unsupported model "%s".', modelOrName);
        end
    end

    function arg = buildControllerArg(ctrl)
        if isempty(ctrl), arg=''; return; end
        c = lower(strtrim(ctrl));
        switch c
            case 'position'
                arg = 'initial_joint_controller:=forward_position_controller';
            case {'speed','velocity'}
                arg = 'initial_joint_controller:=forward_velocity_controller';
            case {'torque', 'effort'}
                arg = 'initial_joint_controller:=forward_effort_controller';
            otherwise
                arg = strtrim(ctrl); % pass-through custom args
        end
    end

    function cmd = applicationRegistry(app, ur, carg)
        a = lower(strtrim(app));
        switch a
            case 'rviz'
                cmd = sprintf('ros2 launch ur_description view_ur.launch.py ur_type:=%s', ur);

            case 'simulation'
                % TODO: replace with your actual package/launch if different
                base = sprintf('ros2 launch ur_simulation_gz ur_sim_control.launch.py ur_type:=%s', ur);
                if ~isempty(carg), cmd = sprintf('%s %s', base, carg); else, cmd = base; end

            case 'teleoperation'
                % TODO: adjust to your package
                base = sprintf('ros2 run tutorialteleop tutorial_teleop');
                if ~isempty(carg), cmd = sprintf('%s %s', base, carg); else, cmd = base; end

            otherwise
                cmd = ''; % unknown → let caller error
        end
    end

    function ensureDockerRunning(dockerName)
        if ispc, cmd = sprintf('wsl docker start %s', dockerName);
        else,     cmd = sprintf('docker start %s', dockerName);
        end
        system(cmd); pause(0.3);
    end



    function s = escapeForBashLC(s)
        s = strrep(s, '"','\"');
    end
end
