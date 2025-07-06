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

    % 1) Check for an existing process
    checkCmd = sprintf('pgrep -f "%s"', procPattern);
    [checkStatus, ~] = system(checkCmd);

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
