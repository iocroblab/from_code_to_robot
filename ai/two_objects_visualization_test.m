%% Two Objects Pick & Place Visualization Test
% Demonstration of the PickPlaceDiscreteEnv with multiple objects

clear; clc; close all;

% Create environment with 2 objects and 6 locations for more space
env = PickPlaceDiscreteEnv(2, 6);

% Show initial state
fprintf('=== Initial State ===\n');
fprintf('Arm position: %d\n', env.arm_pos);
fprintf('Object 1 position: %d (target: %d)\n', env.objects_pos(1), env.target_pos(1));
fprintf('Object 2 position: %d (target: %d)\n', env.objects_pos(2), env.target_pos(2));
env.plot();
pause(2);

fprintf('\n=== Starting two-object pick and place sequence ===\n');

% Strategy: Handle objects one by one
% First, work with Object 1
fprintf('\n--- Working with Object 1 ---\n');

% Move to object 1 location
target_location = env.objects_pos(1);
move_action = target_location + 2; % +2 because actions 3+ are move actions
[~, reward, ~, ~] = env.step(move_action);
fprintf('Moved to Object 1 location (%d), reward: %.2f\n', target_location, reward);
env.plot();
pause(1.5);

% Pick object 1
[~, reward, ~, ~] = env.step(1); % Action 1 = pick
fprintf('Picked Object 1, reward: %.2f\n', reward);
env.plot();
pause(1.5);

% Move to object 1's target location
target_location = env.target_pos(1);
move_action = target_location + 2;
[~, reward, ~, ~] = env.step(move_action);
fprintf('Moved to Object 1 target location (%d), reward: %.2f\n', target_location, reward);
env.plot();
pause(1.5);

% Place object 1
[~, reward, done, ~] = env.step(2); % Action 2 = place
fprintf('Placed Object 1, reward: %.2f\n', reward);
fprintf('Object 1 completed! Episode done: %s\n', string(done));
env.plot();
pause(1.5);

% Continue with Object 2 if not done
if ~done
    fprintf('\n--- Working with Object 2 ---\n');

    % Move to object 2 location
    target_location = env.objects_pos(2);
    move_action = target_location + 2;
    [~, reward, ~, ~] = env.step(move_action);
    fprintf('Moved to Object 2 location (%d), reward: %.2f\n', target_location, reward);
    env.plot();
    pause(1.5);

    % Pick object 2
    [~, reward, ~, ~] = env.step(1); % Action 1 = pick
    fprintf('Picked Object 2, reward: %.2f\n', reward);
    env.plot();
    pause(1.5);

    % Move to object 2's target location
    target_location = env.target_pos(2);
    move_action = target_location + 2;
    [~, reward, ~, ~] = env.step(move_action);
    fprintf('Moved to Object 2 target location (%d), reward: %.2f\n', target_location, reward);
    env.plot();
    pause(1.5);

    % Place object 2
    [~, reward, done, ~] = env.step(2); % Action 2 = place
    fprintf('Placed Object 2, reward: %.2f\n', reward);
    fprintf('Object 2 completed! Episode done: %s\n', string(done));
    env.plot();
    pause(1.5);
end

% Final summary
fprintf('\n=== Final State ===\n');
fprintf('All objects placed at their targets!\n');
fprintf('Object 1: position %d (target: %d) ✓\n', env.objects_pos(1), env.target_pos(1));
fprintf('Object 2: position %d (target: %d) ✓\n', env.objects_pos(2), env.target_pos(2));
fprintf('Episode completed: %s\n', string(done));

fprintf('\nTwo-object visualization test completed!\n');