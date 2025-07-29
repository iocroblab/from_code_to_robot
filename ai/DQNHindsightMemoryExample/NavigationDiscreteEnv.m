classdef NavigationDiscreteEnv < rl.env.MATLABEnvironment
    % NavigationDiscreteEnv

    % Copyright 2023, The MathWorks, Inc.

    %% Properties
    properties
        Map = zeros([1, 5]);
        Robot
        Obj
        Goal
        State = zeros(4,1)
        Obstacles
        % Add property to enable automatic visualization during simulation
        EnableVisualization = false
    end

    properties(Access = protected)
        % Initialize internal flag to indicate episode termination
        IsDone = false
    end

    properties (Transient,Access = private)
        Visualizer = []
    end

    %% Methods
    methods
        function this = NavigationDiscreteEnv()
            % Initialize Observation settings
            observationInfo = rlNumericSpec([3 1]);
            observationInfo.Name = 'Observation';
            observationInfo.Description = 'Robot x, Object x, Goal x';

            % Initialize Action settings
            % 1 = pick
            % 2 = place
            % 3 = move left
            % 4 = move right
            actionInfo = rlFiniteSetSpec([1, 2, 3, 4]);
            actionInfo.Name = 'Action';

            % The following line implements built-in functions of RL env
            this = this@rl.env.MATLABEnvironment(observationInfo, actionInfo);

            createMap(this);
            reset(this);
        end

        function state = reset(this)
            % Reset robot position and goal position

            % Sample robot and goal positions from empty spaces.
            this.Robot.x = randi(5) - 1;
            this.Robot.y = 1;

            this.Robot.handle = 0;

            this.Obj.x = randi(5) - 1;
            this.Obj.y = 1;

            % Ensure goal x position is different from robot x position
            this.Goal.x = randi(5) - 1;
            while this.Goal.x == this.Obj.x
                this.Goal.x = randi(5) - 1;
            end
            this.Goal.y  = 1;
            state = [this.Robot.x, this.Obj.x, this.Goal.x]';
            this.State = state;
        end

        function createMap(this)
            % Create an empty map
            yLength = 1;
            xLength = 5;
            this.Map = zeros([yLength,xLength]);

        end

        function [nextobs,reward,isdone,loggedSignals] = step(this,action)
            arguments
                this
                action {mustBeMember(action,[1,2, 3, 4])}
            end
            % Step the environment to the next state, given the action
            %
            % actions:
            % 1 = pick
            % 2 = place
            % 3 = move left
            % 4 = move right

            x = this.Robot.x;
            xnew = x; % Initialize xnew to current position

            switch action
                case 1 % pick up
                    if this.Robot.x == this.Obj.x && this.Robot.handle == 0
                        this.Robot.handle = 1;
                        this.Obj.x = -1; % Move object off the map when picked
                        this.Obj.y = -1;
                    end
                case 2 % drop
                    if this.Robot.handle == 1 % Only drop if carrying something
                        this.Robot.handle = 0;
                        this.Obj.x = this.Robot.x;
                        this.Obj.y = this.Robot.y;
                    end
                case 3 % move left
                    xnew = x - 1;
                case 4 % move right
                    xnew = x + 1;
            end

            if xnew < 0 || xnew > size(this.Map,2) - 1
                xnew = x;
            end

            % Assign new position
            this.Robot.x = xnew;

            nextobs = [this.Robot.x this.Obj.x this.Goal.x]';
            reward = myNavigationGoalRewardFcn({this.State}, {action}, {nextobs});
            isdone = myNavigationGoalIsDoneFcn({this.State}, {action}, {nextobs});
            this.State = nextobs;
            this.IsDone = isdone;
            loggedSignals = [];

            % Automatically show visualization if enabled
            if this.EnableVisualization
                this.plot();
                pause(0.5); % Small pause to see the animation
            end
        end

        function enableVisualization(this)
            % Enable automatic visualization during simulation
            this.EnableVisualization = true;
            this.plot(); % Show initial state
        end

        function disableVisualization(this)
            % Disable automatic visualization
            this.EnableVisualization = false;
        end

        function varargout = plot(this)
            % Visualizes the environment
            if isempty(this.Visualizer) || ~isvalid(this.Visualizer)
                this.Visualizer = NavigationDiscreteEnvVisualizer(this);
            % else
            %     bringToFront(this.Visualizer);
            end
            if nargout
                varargout{1} = this.Visualizer;
            end
        end

        function set.State(this,state)
            this.State = state;
            notifyEnvUpdated(this);
        end
    end
end
