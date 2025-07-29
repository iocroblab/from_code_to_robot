classdef NavigationDiscreteEnv < rl.env.MATLABEnvironment
    % NavigationDiscreteEnv

    % Copyright 2023, The MathWorks, Inc.

    %% Properties
    properties
        Map = zeros([1, 10]);
        Robot
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
            observationInfo = rlNumericSpec([4 1]);
            observationInfo.Name = 'Observation';
            observationInfo.Description = 'Robot x, Robot y, Goal x, Goal y';

            % Initialize Action settings
            % 1 = move up
            % 2 = move down
            % 3 = move left
            % 4 = move right
            actionInfo = rlFiniteSetSpec([1, 2]);
            actionInfo.Name = 'Action';

            % The following line implements built-in functions of RL env
            this = this@rl.env.MATLABEnvironment(observationInfo, actionInfo);

            createMap(this);
            reset(this);
        end

        function state = reset(this)
            % Reset robot position and goal position

            % Sample robot and goal positions from empty spaces.
            this.Robot.x = randi(10) - 1;
            this.Robot.y = 1;

            % Ensure goal x position is different from robot x position
            this.Goal.x = randi(10) - 1;
            while this.Goal.x == this.Robot.x
                this.Goal.x = randi(10) - 1;
            end
            this.Goal.y  = 1;
            state = [this.Robot.x, this.Robot.y, this.Goal.x, this.Goal.y]';
            this.State = state;
        end

        function createMap(this)
            % Create an empty map
            yLength = 1;
            xLength = 10;
            this.Map = zeros([yLength,xLength]);

        end

        function [nextobs,reward,isdone,loggedSignals] = step(this,action)
            arguments
                this
                action {mustBeMember(action,[1,2])}
            end
            % Step the environment to the next state, given the action
            %
            % actions:
            % 1 = move up
            % 2 = move down
            % 3 = move left
            % 4 = move right

            x = this.Robot.x;
            y = this.Robot.y;
            switch action
                case 1 % move left
                    xnew = x - 1;
                    ynew = y ;
                case 2 % move right
                    xnew = x + 1;
                    ynew = y;
            end

            % The robot doesn't move if the robot is outside of the map's boundary.
            if ynew < 0 || ynew > size(this.Map,1) - 1
                ynew = y;
            end

            if xnew < 0 || xnew > size(this.Map,2) - 1
                xnew = x;
            end


            % Assign new position
            this.Robot.y = ynew;
            this.Robot.x = xnew;

            nextobs = [this.Robot.x, this.Robot.y,this.Goal.x, this.Goal.y]';
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
            else
                bringToFront(this.Visualizer);
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
