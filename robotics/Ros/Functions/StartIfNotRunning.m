function status = StartIfNotRunning(procPattern, launchCmd, emulator)
% StartIfNotRunning  Launch a terminal only if a matching process isn't already running
%
%   STATUS = StartIfNotRunning(PROCPATTERN, LAUNCHCMD)
%   STATUS = StartIfNotRunning(PROCPATTERN, LAUNCHCMD, EMULATOR)
%
%   • PROCPATTERN is a string or regex snippet to match your running process
%     (e.g. 'view_ur\.launch\.py' or 'ros2 launch ur_description')
%   • LAUNCHCMD   is the exact same command‐sequence you'd pass to StartScript
%   • EMULATOR    is optional: 'gnome-terminal' (default) or 'xterm'
%
%   Returns the exit status of either the check (if already running, returns 0)
%   or of the launcher (0 on success).

arguments
    procPattern  (1,:) char
    launchCmd    (1,:) char
    emulator     (1,:) char = "gnome-terminal"
end
if isunix
    % 1) Check for an existing process
    checkCmd = sprintf('pgrep -f "%s"', procPattern);
    [checkStatus, ~] = system(checkCmd);
    
elseif ispc
    %start a wsl shell if not running
    [wslstatus, wslrunning]= system('tasklist /FI "IMAGENAME eq wsl.exe"'); 
    if wslstatus==0 && strcmp(wslrunning(1:11), 'INFORMATION')
        system('start cmd /k wsl');
    end
    
    %start the docker if not running
    [status, result] = system('wsl docker ps -a --filter name=gz-modified --filter status=running');
    if ~(status == 0 && ~isempty(result(103:end)))
        
        system('wsl docker start gz-modified');
    end

    checkCmd = sprintf('wsl pgrep -f "%s"', procPattern);
    [checkStatus, ~] = system(checkCmd);
end

if checkStatus == 0
    %fprintf('Process matching "%s" is already running – nothing to do.\n', procPattern);
    status = 0;
    return
else


    % 2) Not running yet → spawn it
    status = StartScript(launchCmd, emulator);
    pause(4)
end
end
