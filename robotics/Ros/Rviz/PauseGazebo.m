function success = PauseGazebo(pauseFlag, worldName)
%PAUSEGAZEBO Pause or unpause a Gazebo world.
%   success = PauseGazebo(true)       % pause  /world/empty
%   success = PauseGazebo(false)      % unpause /world/empty
%   success = PauseGazebo(true,"my_world")
%
% Strategy:
%   - If MATLAB has ros_gz_interfaces generated, call service natively.
%   - Otherwise, shell out to `ros2 service call` (no codegen needed).
%
% Notes:
%   - Keeps node/client persistent for speed when using native path.

    arguments
        pauseFlag (1,1) logical
        worldName (1,1) string = "empty"
    end

    srvType = "ros_gz_interfaces/ControlWorld";
    srvName = "/world/" + worldName + "/control";
    
    % if isempty(which("ros_gz_interfaces_msg_WorldControl"))
    %     ros2RegisterMessages("/home/constanin/Desktop/Work/GitIOC/robotics/Ros/interfaces/");
    % end

    % Detect whether MATLAB has ros_gz_interfaces generated
    hasGzIfaces = ~isempty(which("ros_gz_interfaces_msg_WorldControl")) || ...
                   any(contains(ros2("msg","list"), "ros_gz_interfaces/WorldControl"));

    if hasGzIfaces
        success = i_callNative(pauseFlag, srvName, srvType);
        if success, return; end
        % If native failed (e.g., no service present), fall through to CLI
    end
end

function success = i_callNative(pauseFlag, srvName, srvType)
    persistent pNode pClient pSrv
    try
        if isempty(pNode) || ~isvalid(pNode)
            pNode = ros2node('matlab_pausegazebo');
            pClient = []; pSrv = "";
        end
        if isempty(pClient) || ~isvalid(pClient) || pSrv ~= srvName
            pClient = ros2svcclient(pNode, srvName, srvType);
            pSrv = srvName;
        end

        req = ros2message(pClient);
        % Correct nested field per ros_gz_interfaces/ControlWorld.srv:
        % request has field 'world_control' (type WorldControl)
        req.world_control.pause = pauseFlag;

        call(pClient, req, "Timeout", 3.0);
        success = true;
    catch ME
        warning("PauseGazebo:NativeFailed","Native call failed: %s", ME.message);
        success = false;
    end
end

function success = i_callCLI(pauseFlag, worldName)
    pauseStr = lower(string(pauseFlag)); % "true"/"false"
    cmd = sprintf(['ros2 service call /world/%s/control ' ...
                   'ros_gz_interfaces/srv/ControlWorld ' ...
                   '"{world_control: {pause: %s}}"'], worldName, pauseStr);
    [status,out] = system(cmd);
    if status ~= 0
        warning("PauseGazebo:CLIFailed","CLI call failed (%d): %s", status, out);
        success = false;
    else
        success = true;
    end
end
