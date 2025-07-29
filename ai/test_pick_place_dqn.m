%% Test script for Pick_Place environment with DQN
% This script demonstrates how to set up and train a DQN agent with the corrected Pick_Place environment

%% Create environment
num_objects = 2;
num_locations = 4;
env = PickPlaceDiscreteEnv(num_objects, num_locations);

% Check environment is working
obs = reset(env);
fprintf('Initial observation: ');
disp(obs');

% Test a few actions
fprintf('\nTesting actions:\n');

% Test move action
[obs, reward, done, info] = step(env, 3); % Move to location 1
fprintf('Move to location 1 - Reward: %.2f, Done: %d\n', reward, done);

% Test pick action
[obs, reward, done, info] = step(env, 1); % Pick
fprintf('Pick action - Reward: %.2f, Done: %d\n', reward, done);

% Test place action
[obs, reward, done, info] = step(env, 2); % Place
fprintf('Place action - Reward: %.2f, Done: %d\n', reward, done);

%% Set up DQN Agent (commented out as it requires Deep Learning Toolbox)
%
% % Create DQN agent
% obsInfo = getObservationInfo(env);
% actInfo = getActionInfo(env);
%
% % Create deep neural network for Q-function approximation
% layers = [
%     featureInputLayer(obsInfo.Dimension(1))
%     fullyConnectedLayer(128)
%     reluLayer
%     fullyConnectedLayer(128)
%     reluLayer
%     fullyConnectedLayer(64)
%     reluLayer
%     fullyConnectedLayer(length(actInfo.Elements))
% ];
%
% % Set up DQN agent options
% agentOpts = rlDQNAgentOptions(...
%     'UseDoubleDQN', true, ...
%     'TargetSmoothFactor', 1e-3, ...
%     'ExperienceBufferLength', 100000, ...
%     'MiniBatchSize', 64);
%
% % Create DQN agent
% agent = rlDQNAgent(rlQValueRepresentation(layerGraph(layers), obsInfo, actInfo), agentOpts);
%
% % Training options
% trainOpts = rlTrainingOptions(...
%     'MaxEpisodes', 1000, ...
%     'MaxStepsPerEpisode', 200, ...
%     'Verbose', false, ...
%     'Plots', 'training-progress', ...
%     'StopTrainingCriteria', 'AverageReward', ...
%     'StopTrainingValue', 480);
%
% % Train the agent
% trainingStats = train(agent, env, trainOpts);

fprintf('\nEnvironment setup complete! Ready for DQN training.\n');
fprintf('Observation space: %d dimensions\n', obsInfo.Dimension(1));
fprintf('Action space: %d discrete actions\n', length(actInfo.Elements));