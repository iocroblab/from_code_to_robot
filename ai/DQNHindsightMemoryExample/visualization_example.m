%% Navigation Environment Visualization Example
% This script demonstrates how to enable visualization during simulation

clear; clc; close all;

% Create the navigation environment
env = NavigationDiscreteEnv();

% Enable automatic visualization during simulation
env.enableVisualization();

% Create a simple random agent for demonstration
agent = rlRandomAgent(getObservationInfo(env), getActionInfo(env));

% Set up simulation options
maxStepsPerEpisode = 50;
simOptions = rlSimulationOptions(...
    'NumSimulations', 1, ...
    'MaxSteps', maxStepsPerEpisode);

fprintf('Starting simulation with visualization...\n');
fprintf('Robot (blue) will try to reach Goal (red)\n');
fprintf('The window should show the robot moving step by step\n\n');

% Run simulation - now the visualization window should appear and update!
simResults = sim(env, agent, simOptions);

fprintf('Simulation completed!\n');
fprintf('Total steps: %d\n', length(simResults(1).Observation.NavigationData));
fprintf('Final reward: %.2f\n', sum([simResults(1).Reward.Data]));

% If you want to disable visualization later:
% env.disableVisualization();