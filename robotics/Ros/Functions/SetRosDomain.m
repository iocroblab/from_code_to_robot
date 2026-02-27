function SetRosDomain(domainID)
% SetRosDomain  Set ROS 2 domain ID for MATLAB + persist to ~/.bashrc (Linux).
%
% Also clears selected MATLAB functions to reset persistent ROS nodes.

    if nargin < 1 || isempty(domainID)
        domainID = 0;
    end

    validateattributes(domainID, ...
        {'numeric'}, {'scalar','integer','nonnegative'}, ...
        mfilename, 'domainID');

    domainStr = num2str(domainID);

    % 1) Apply to MATLAB session
    setenv("ROS_DOMAIN_ID", domainStr);
    fprintf("ROS_DOMAIN_ID set to %s (MATLAB)\n", domainStr);

    % 2) Linux: persist to ~/.bashrc + restart ros2 daemon
    if isunix
        cmdBashrc = sprintf( ...
            'bash -lc ''sed -i "/ROS_DOMAIN_ID/d" ~/.bashrc; echo "export ROS_DOMAIN_ID=%s" >> ~/.bashrc''', ...
            domainStr);
        system(cmdBashrc);
        fprintf("Updated ~/.bashrc with ROS_DOMAIN_ID=%s\n", domainStr);

        % Best-effort: restart ros2 daemon to avoid stale caching
        system('bash -lc "ros2 daemon stop >/dev/null 2>&1 || true; ros2 daemon start >/dev/null 2>&1 || true"');
    end

    % 3) Clear ONLY the functions that keep persistent ROS state
    % NOTE: do NOT clear SetRosDomain until the end (we're inside it).
    funsToClear = { ...
        'GetJointEfforts'
        'GetJointSpeeds'
        'GetJointStates'
        'GetJointValues'
        'GetTeleoperation'
        'JointStatesToRviz'
        'SendJointPositions'
        'SendJointSpeeds'
        'SendJointTorques'
        'SendJointTrajectory'
        'SetSimulationSpeed'
        'StartTutorialApplication'
        'StaticFrameBroadcaster'
        'StopTutorialApplications'
        'SwitchControllers'
        'TargetFrameBroadcaster' ...
        };

    for k = 1:numel(funsToClear)
        f = funsToClear{k};
        try
            clear(f); %#ok<CLFUNC>
        catch ME
            % If a function doesn't exist on the path, ignore it
            warning("Could not clear %s: %s", f, ME.message);
        end
    end

    fprintf("Cleared persistent state in %d functions.\n", numel(funsToClear));
    fprintf("New ROS_DOMAIN_ID=%s should be used by subsequent calls.\n", domainStr);

    % 4) Finally clear this function too (applies after returning)
    clear SetRosDomain
end