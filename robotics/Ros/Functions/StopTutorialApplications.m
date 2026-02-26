function StopTutorialApplications(varargin)
% StopTutorialApplications([Name,Value]...)
% Stop all running tutorial-related processes.
%
% DEFAULT (Docker=true):
%   • Windows + Docker (WSL backend):
%       - Stops all running containers
%       - Shuts down WSL (which fully stops Docker engine)
%   • Ubuntu + Docker:
%       - Kills all running containers
%       - Tries to stop Docker service (no password prompt; ignored if not allowed)
%
% NATIVE UBUNTU (Docker=false):
%   • Kills common ROS 2 / Gazebo / RViz / Ignition processes via pkill -f
%
% OPTIONAL (Name–Value):
%   'Docker' : logical, default true
%
% RETURNS:
%   status : 0 on best-effort success (non-zero if any critical stop command failed)

% ---------- Defaults ----------
opts.Docker = true;

% ---------- Parse Name–Value ----------
if mod(numel(varargin),2)~=0
    error('Optional arguments must be Name–Value pairs.');
end
for k=1:2:numel(varargin)
    name = lower(string(varargin{k}));
    val  = varargin{k+1};
    switch name
        case "docker",  opts.Docker = logical(val);
        otherwise, error('Unknown option "%s". Valid: Docker.', name);
    end
end

% ---- Run helpers ----
if opts.Docker
    status = stopDockerEverywhere();
else
    status = stopNativeRosUbuntu();
end

end

% ====================== Helpers ======================
function st = stopDockerEverywhere()
% Stop all containers; then stop the engine where possible.

if ispc
    % WINDOWS (Docker Desktop with WSL backend)
    % 1) Stop all running containers (ignore errors if none)
    runCmd('wsl bash -lc "docker ps -q | xargs -r docker kill"');
    % 2) Shut down WSL to fully stop Docker's Linux backend
    %    (This will kill all WSL instances; harmless if already stopped)
    st = runCmd('wsl --shutdown');

else
    % UBUNTU (Docker on host)
    % 1) Kill all running containers (ignore if none)
    runCmd('bash -lc "docker ps -q | xargs -r docker kill"');
    % 2) Attempt to stop Docker service without prompting for password
    %    (ignored if systemd not present / permission denied)
    runCmd('bash -lc "sudo -n systemctl stop docker 2>/dev/null"');
    % 3) Best-effort return code (0 if the previous commands didn't hard-fail)
    st = 0;
end
end

function st = stopNativeRosUbuntu()
% Kill typical ROS 2 / Gazebo / RViz / Ignition processes on native Ubuntu.
if ispc
    error('Native Ubuntu stop is not supported on Windows. Use ''Docker'', true.');
end

patterns = [ ...
    "ros", ...
    "roscore", ...
    "rviz", ...
    "gazebo", ...
    "gz", ...
    "ign", ...
    "ignition", ...
    "ros2 launch", ...
    "python.*ros2", ...
    "gazebo_ros", ...
    "gzserver", ...
    "gzclient" ...
];

% pkill -f each pattern; ignore failures if a process isn't found
for i = 1:numel(patterns)
    cmd = sprintf('bash -lc "pkill -f -e %s 2>/dev/null || true"', shellQuote(patterns(i)));
    runCmd(cmd);
end

st = 0; % best-effort
end

function st = runCmd(cmd)
% Wrapper that executes a system command and returns status (never throws).
st = system(cmd);
end

function q = shellQuote(s)
% Safely single-quote a string for bash -lc "...".
% Implements:  'abc'def'  ->  'abc'\''def'
% Works without forbidden string literals.

s  = char(s);
sq = char(39);           % single quote character: '

% Split on single quotes, then re-join inserting '\'' between parts.
parts = strsplit(s, sq);

% Start with an opening single quote
q = sq;

% First chunk
q = [q, parts{1}];

% For each subsequent chunk, insert '\'' then the chunk
for i = 2:numel(parts)
    q = [q, sq, '\', sq, parts{i}];   % appends: '\'' (i.e., ' \ ' ) then text
end

% Close with a single quote
q = [q, sq];
end

