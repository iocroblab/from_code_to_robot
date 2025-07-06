function status = StartScript(cmd, emulator)
% StartScript  Launch a Linux terminal, run a command, and return immediately
%
%   STATUS = StartScript(CMD)  
%   STATUS = StartScript(CMD, EMULATOR)
%
%   - CMD       : a single string, e.g.
%                 'cd ~/Desktop/Work/GitIOC/robotics/Ros/Repo; source install/setup.bash; ros2 launch ur_description view_ur.launch.py'
%   - EMULATOR  : (optional) 'gnome-terminal' (default) or 'xterm'
%
%   Returns the exit status of the shell launcher (0 = success).

    arguments
        cmd       (1,:) char
        emulator  (1,:) char = "gnome-terminal"
    end

    % Ensure your full sequence of commands is separated by semicolons
    % and that there are no stray quotes in cmd itself.
    % We'll wrap it in bash -lc "...; exec bash" so the window stays open
    wrapped = sprintf('%s; exec bash', cmd);

    switch char(emulator)
        case 'gnome-terminal'
            % -u LD_LIBRARY_PATH unsets MATLAB's path so gnome-terminal
            % picks up your system's libstdc++ (with GLIBCXX_3.4.31)
            launcher = sprintf(...
              'env -u LD_LIBRARY_PATH gnome-terminal -- bash -lc "%s" &', ...
              wrapped);

        case 'xterm'
            % xterm -hold also tends to use the system libraries by default
            launcher = sprintf(...
              'env -u LD_LIBRARY_PATH xterm -hold -e "bash -lc ''%s''" &', ...
              wrapped);

        otherwise
            error('Unsupported emulator "%s".', emulator);
    end

    status = system(launcher);
end
