function success = SetSimulationSpeed(speed, varargin)
% SetSimulationSpeed(speed, Name,Value,...)
%
% Change Gazebo real_time_factor via:
%   gz service -s /world/empty/set_physics ...
%
% Always opens a terminal and automatically closes it after ~0.001 second.
%
% Name–Value:
%   'Docker'     : logical (default true)
%   'DockerName' : char    (default 'gz-modified')

    % ---------- Defaults ----------
    opts.Docker     = true;
    opts.DockerName = 'gz-modified';

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
            otherwise
                error('Unknown option "%s".', name);
        end
    end

    % ---------- Validate speed ----------
    validateattributes(speed, {'numeric'}, {'scalar','real'}, mfilename, 'speed');

    % ---------- gz service command ----------
    gzCmd = sprintf([ ...
        'gz service -s /world/empty/set_physics ', ...
        '--reqtype gz.msgs.Physics --reptype gz.msgs.Boolean ', ...
        '--req real_time_factor:%.6f'], speed);

    % ---------- Common Script (prints + sleeps + exit) ----------
    script = sprintf([ ...
        'source /opt/ros/jazzy/setup.bash; ', ...
        '%s; ', ...
        'sleep 0.001; ', ...      % auto-close delay
        'exit 0' ], gzCmd);

    % ---------- Build launcher ----------
    if opts.Docker
        ensureDockerRunning(opts.DockerName);

        if ispc
            % Windows + Docker
            innerWSL = sprintf( ...
                'docker exec -it %s bash -lc ''%s''', opts.DockerName, script);

            launcher = sprintf( ...
                'cmd /c start "" wsl bash -lc "%s"', escapeForBashLC(innerWSL));

        else
            % Ubuntu + Docker
            inner = sprintf( ...
                'docker exec -it %s bash -lc ''%s''', opts.DockerName, script);

            launcher = sprintf( ...
                'env -u LD_LIBRARY_PATH gnome-terminal -- bash -lc "%s" &', ...
                escapeForBashLC(inner));
        end

    else
        % Native Ubuntu
        if ispc
            error('Windows without Docker is not supported.');
        end

        launcher = sprintf( ...
            'env -u LD_LIBRARY_PATH gnome-terminal -- bash -lc "%s" &', ...
            escapeForBashLC(script));
    end

    % ---------- Execute ----------
    [status,~] = system(launcher);
    success = (status == 0);

    if ~success
        warning('Launcher failed (status %d)\n%s', status, launcher);
    end
end

% ====================== Helpers ======================

function ensureDockerRunning(name)
    if ispc, cmd = sprintf('wsl docker start %s',name);
    else,    cmd = sprintf('docker start %s',name);
    end
    system(cmd); pause(0.3);
end

function s = escapeForBashLC(s)
    s = strrep(s, '"','\"');
end
