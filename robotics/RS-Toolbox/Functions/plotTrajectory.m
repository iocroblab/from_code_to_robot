function plotTrajectory(varargin)
% plotTrajectory dynamically plots joint states: position, velocity, acceleration over time.
%
% Usage:
%   plotTrajectory(q)
%   plotTrajectory(q, qd)
%   plotTrajectory(q, qd, qdd)
%   plotTrajectory(q, qd, qdd, t)
%   plotTrajectory(q, qd, t)
%   plotTrajectory(q, t)
%
% Inputs:
%   q   - Joint positions (vector or matrix)
%   qd  - Joint velocities (vector or matrix)
%   qdd - Joint accelerations (vector or matrix)
%   t   - (optional, last) time vector [nTime x 1 or 1 x nTime]
%
% If time vector t is provided as the last argument, it is used for the x-axis.
% Otherwise, time steps default to 1:nTime.
% Each state input can be a row or column vector, or a matrix where one dimension
% corresponds to time steps and the other to joints. The longer dimension is
% assumed to represent time steps.

% Validate inputs
if nargin < 1
    error('At least one state input (q) is required.');
end

% Check if last argument is time vector
if nargin > 1 && isvector(varargin{end})
    t = varargin{end}(:);             % make column vector
    stateInputs = varargin(1:end-1);
else
    t = [];
    stateInputs = varargin;
end

% Assign state variables
q   = stateInputs{1};
qd  = [];
qdd = [];
if numel(stateInputs) >= 2, qd  = stateInputs{2}; end
if numel(stateInputs) >= 3, qdd = stateInputs{3}; end

% Prepare labels and data list
labels = {'Position','Velocity','Acceleration'};
dataList = {q, qd, qdd};
isProvided = ~cellfun(@isempty, dataList);
providedIdx = find(isProvided);
nPlots = numel(providedIdx);
if nPlots == 0
    error('At least one of q, qd, or qdd must be provided.');
end

% Normalize each data input to [nTime x nJoints]
for k = 1:3
    if isProvided(k)
        D = dataList{k};
        if isvector(D)
            D = D(:);  % ensure column
        else
            [d1, d2] = size(D);
            if d1 < d2
                D = D';
            end
        end
        dataList{k} = D;
    end
end

% Determine time axis if not provided
if isempty(t)
    nTime = size(dataList{providedIdx(1)},1);
    t = (1:nTime)';
else
    nTime = numel(t);
end

% Validate time-data length match
firstData = dataList{providedIdx(1)};
if size(firstData,1) ~= nTime
    error('Provided time vector length does not match data samples.');
end

% Plotting
figure;
if exist('sgtitle','file')
    sgtitle('Joint States');
end
for i = 1:nPlots
    idx = providedIdx(i);
    Y = dataList{idx};
    [nT, nJ] = size(Y);
    if nT ~= nTime
        error('Data length for %s does not match time vector.', labels{idx});
    end
    colors = lines(nJ);
    subplot(nPlots,1,i);
    hold on;
    for j = 1:nJ
        plot(t, Y(:,j), 'Color', colors(j,:), 'LineWidth',1.5);
    end
    hold off;
    ylabel(labels{idx});
    if i == nPlots
        xlabel('Time');
    end
    legend(arrayfun(@(j) sprintf('Joint %d', j), 1:nJ, 'UniformOutput', false), 'Location', 'best');
    grid on;
end
end
