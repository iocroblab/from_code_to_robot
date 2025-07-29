%% Simple Pick & Place Visualization Test
% Quick test of the PickPlaceDiscreteEnv visualization

clear; clc; close all;

% Create environment with 1 object and 4 locations
env = PickPlaceDiscreteEnv(1, 4);

% Show initial visualization

% Display the environment
env.plot();

% Test a few actions
fprintf('\nTesting some actions...\n');

% Move to object location
target_location = env.objects_pos(1);
move_action = target_location + 2; % +2 because actions 3+ are move actions
[~, reward, ~, ~] = env.step(move_action);
fprintf('Moved to location %d, reward: %.2f\n', target_location, reward);
env.plot();
pause(1);

% Pick the object
[~, reward, ~, ~] = env.step(1); % Action 1 = pick
fprintf('Picked object, reward: %.2f\n', reward);
env.plot();
pause(1);

% Move to target location
target_location = env.target_pos(1);
move_action = target_location + 2;
[~, reward, ~, ~] = env.step(move_action);
fprintf('Moved to target location %d, reward: %.2f\n', target_location, reward);
env.plot();
pause(1);

% Place the object
[~, reward, done, ~] = env.step(2); % Action 2 = place
fprintf('Placed object, reward: %.2f\n', reward);
fprintf('Episode completed: %s\n', string(done));
env.plot();

fprintf('\nVisualization test completed!\n');