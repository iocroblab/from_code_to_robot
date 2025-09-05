function ok = SetJointStates(q, pauseFlag)
%SETJOINTSTATES Move robot to joint vector q via a trajectory controller, then restore original controller.
%   ok = SetJointStates(q)          % pauses Gazebo afterwards (default true)
%   ok = SetJointStates(q, false)   % do NOT pause Gazebo afterwards
%
% Requires:
%   - controller_manager_msgs (services), control_msgs (actions), trajectory_msgs
%   - Your PauseGazebo.m available on MATLAB path (uses /world/empty/control or your bridge)
%
% Notes:
%   - Joint order in q must match the trajectory controller's joints.
%   - Trajectory controller preference: scaled_joint_trajectory_controller → joint_trajectory_controller.

if nargin < 2 || isempty(pauseFlag), pauseFlag = true; end
ok = false;

% ---- Adjust if you use a namespace or different world name ----
ns             = "";       % e.g. "/ur"
worldName      = "empty";
trajCandidates = ["scaled_joint_trajectory_controller","joint_trajectory_controller"];
goalTime       = 2.0;      % seconds for the single point
% ---------------------------------------------------------------

persistent NODE S_LIST L_LOAD C_CONFIG S_SWITCH A_FJT FJT_GOAL
try
    if isempty(NODE) || ~isvalid(NODE)
        NODE = ros2node("/matlab_set_joint_states");
    end
    fq = @(name) ( (strlength(ns)>0 && ns(1)~='/') * "/" + ns ) + "/" + erase(name,"/");

    % --- controller_manager clients ---
    if isempty(S_LIST)   || ~isvalid(S_LIST),   S_LIST   = ros2svcclient(NODE, fq("controller_manager/list_controllers"), "controller_manager_msgs/ListControllers"); end
    if isempty(L_LOAD)   || ~isvalid(L_LOAD),   L_LOAD   = ros2svcclient(NODE, fq("controller_manager/load_controller"),   "controller_manager_msgs/LoadController"); end
    if isempty(C_CONFIG) || ~isvalid(C_CONFIG), C_CONFIG = ros2svcclient(NODE, fq("controller_manager/configure_controller"), "controller_manager_msgs/ConfigureController"); end
    if isempty(S_SWITCH) || ~isvalid(S_SWITCH), S_SWITCH = ros2svcclient(NODE, fq("controller_manager/switch_controller"), "controller_manager_msgs/SwitchController"); end

    % --- 1) Detect current ACTIVE non-broadcaster controller (original) ---
    lc = call(S_LIST, ros2message(S_LIST), "Timeout", 3.0);
    if isempty(lc.controller), error("No controllers reported by controller_manager."); end
    states = lc.controller;

    isActive = arrayfun(@(s) strcmp(char(s.state),'active'), states);
    notBroad = arrayfun(@(s) ~contains(lower(char(s.type)), 'broadcaster'), states);
    candidates = states(isActive & notBroad);
    if isempty(candidates), error("No ACTIVE non-broadcaster controller found."); end

    % Prefer a non-trajectory controller as 'original'
    isTraj = arrayfun(@(s) contains(lower(char(s.type)), 'trajectory'), candidates);
    if any(~isTraj), orig = candidates(find(~isTraj,1,'first'));
    else,            orig = candidates(1);
    end
    origName = string(orig.name);

    % --- 2) Ensure a trajectory controller is loaded/configured ---
    loadedNames = string(arrayfun(@(s) s.name, states, 'UniformOutput', false));
    pick = trajCandidates(ismember(trajCandidates, loadedNames));
    if isempty(pick), pick = trajCandidates(1); end
    trajName = pick(1);

    % If not loaded, load it
    if ~any(loadedNames == trajName)
        reqL = ros2message(L_LOAD); reqL.name = trajName;
        rL = call(L_LOAD, reqL, "Timeout", 5.0);
        if ~rL.ok, error("Failed to load trajectory controller '%s'.", trajName); end
    end
    % Configure (best-effort; ok if already configured/active)
    reqC = ros2message(C_CONFIG); reqC.name = trajName;
    try, call(C_CONFIG, reqC, "Timeout", 5.0); catch, end

    % --- 3) Switch: start trajectory, stop original ---
    if ~doSwitch(S_SWITCH, trajName, origName, 2, 5.0)
        error("Switch failed (start '%s', stop '%s').", trajName, origName);
    end
    cleanupRevert = onCleanup(@() doSwitch(S_SWITCH, origName, trajName, 2, 5.0)); %#ok<NASGU>

    % --- 4) Send FollowJointTrajectory goal to q ---
    actName = fq(trajName + "/follow_joint_trajectory");
    if isempty(A_FJT) || ~isvalid(A_FJT) || ~strcmp(A_FJT.ActionName, actName)
        A_FJT = ros2actionclient(NODE, actName, "control_msgs/FollowJointTrajectory");
        waitForServer(A_FJT, 5.0);
    end
    if isempty(FJT_GOAL), FJT_GOAL = ros2message(A_FJT); end

    % Try to pull joint list from controller state; fallback to common UR names
    trajIdx = find(loadedNames == trajName, 1, 'first');
    if isempty(trajIdx)
        jointNames = defaultURJoints();
    else
        st = states(trajIdx);
        if isfield(st, 'joints') && ~isempty(st.joints)
            jointNames = string(st.joints);
        else
            jointNames = defaultURJoints();
        end
    end

    q = reshape(q,1,[]);
    if numel(q) ~= numel(jointNames)
        error("q has %d elements but controller expects %d joints.", numel(q), numel(jointNames));
    end

    % Fill single point trajectory
    FJT_GOAL.trajectory.joint_names = jointNames;
    FJT_GOAL.trajectory.points = repmat(FJT_GOAL.trajectory.points, 0); % clear
    pt = FJT_GOAL.trajectory.points;
    pt.positions  = double(q);
    pt.velocities = []; pt.accelerations = []; pt.effort = [];
    pt.time_from_start.sec     = int32(floor(goalTime));
    pt.time_from_start.nanosec = uint32(round((goalTime - floor(goalTime))*1e9));
    FJT_GOAL.trajectory.points = pt;

    [~, result, ~] = sendGoal(A_FJT, FJT_GOAL, "Timeout", max(5.0, goalTime+5.0), "Sync", true);
    if isfield(result,'error_code') && double(result.error_code) ~= 0
        error("Trajectory controller returned error_code=%d.", double(result.error_code));
    end

    % --- 5) Pause Gazebo if requested ---
    if pauseFlag
        PauseGazebo(true);  % ← uses your existing function
    end

    % --- 6) Switch back to original & ensure it's active (load/configure if needed) ---
    % Switch back is handled by onCleanup (best-effort). Now ensure original is loaded/configured/active.
    ensureLoadedConfiguredActive(origName, S_LIST, L_LOAD, C_CONFIG, S_SWITCH);

    ok = true;

catch ME
    warning("SetJointStates: %s", ME.message);
    ok = false;
end
end

% ===== helpers =====
function ok = doSwitch(S_SWITCH, startName, stopName, strictness, timeoutSec)
req = ros2message(S_SWITCH);
req.start_controllers = string(startName);
req.stop_controllers  = string(stopName);
req.strictness        = uint32(strictness);  % 2 = STRICT
req.start_asap        = true;
req.timeout.sec       = int32(floor(timeoutSec));
req.timeout.nanosec   = uint32(round((timeoutSec - floor(timeoutSec))*1e9));
resp = call(S_SWITCH, req, "Timeout", timeoutSec + 2.0);
ok = logical(resp.ok);
end

function ensureLoadedConfiguredActive(name, S_LIST, L_LOAD, C_CONFIG, S_SWITCH)
% Load if missing, configure if needed, then switch to activate (best-effort).
lc = call(S_LIST, ros2message(S_LIST), "Timeout", 3.0);
names = string(arrayfun(@(s) s.name, lc.controller, 'UniformOutput', false));
stateOf = @(n) string(lc.controller(find(names==n,1,'first')).state);

if ~any(names == name)
    rL = ros2message(L_LOAD); rL.name = name; rL = call(L_LOAD, rL, "Timeout", 5.0);
    if ~rL.ok, warning("ensureLoadedConfiguredActive: load('%s') failed.", name); return; end
    lc = call(S_LIST, ros2message(S_LIST), "Timeout", 3.0);
    names = string(arrayfun(@(s) s.name, lc.controller, 'UniformOutput', false));
end

% Configure if not active
st = stateOf(name);
if st ~= "active"
    rC = ros2message(C_CONFIG); rC.name = name;
    try, call(C_CONFIG, rC, "Timeout", 5.0); catch, end
    % Activate by switching it alone to start (no stops)
    req = ros2message(S_SWITCH);
    req.start_controllers = string(name);
    req.stop_controllers  = strings(0,1);
    req.strictness        = uint32(2);
    req.start_asap        = true;
    req.timeout.sec       = int32(2); req.timeout.nanosec = uint32(0);
    try, call(S_SWITCH, req, "Timeout", 4.0); catch, end
end
end

function jn = defaultURJoints()
jn = ["shoulder_pan_joint","shoulder_lift_joint","elbow_joint", ...
      "wrist_1_joint","wrist_2_joint","wrist_3_joint"];
end
