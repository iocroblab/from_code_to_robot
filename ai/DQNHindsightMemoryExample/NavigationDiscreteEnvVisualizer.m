classdef NavigationDiscreteEnvVisualizer < rl.env.viz.AbstractFigureVisualizer
    % NavigationDiscreteEnvVisualizer - Adapted for Pick and Place

    % Copyright 2023 The MathWorks, Inc.

    properties (Access = private)
        VisualizationSpeed = 1.0; % Speed multiplier (1.0 = normal, 0.5 = half speed, 2.0 = double speed)
        MaxFPS = 30; % Maximum frames per second
        LastUpdateTime = 0; % Time of last update
    end

    methods
        function this = NavigationDiscreteEnvVisualizer(env)
            this = this@rl.env.viz.AbstractFigureVisualizer(env);
            this.LastUpdateTime = tic;
        end

        function setSpeed(this, speed)
            % Set visualization speed
            % speed: Speed multiplier (0.1 = very slow, 1.0 = normal, 5.0 = very fast)
            if speed > 0
                this.VisualizationSpeed = speed;
                fprintf('Visualization speed set to %.2fx\n', speed);
            else
                error('Speed must be positive');
            end
        end

        function speed = getSpeed(this)
            % Get current visualization speed
            speed = this.VisualizationSpeed;
        end

        function addSpeedControls(this)
            % Add UI controls for speed adjustment
            f = this.Figure;
            if isempty(f) || ~isvalid(f)
                return;
            end

            % Create speed control panel
            uicontrol('Parent', f, 'Style', 'text', 'String', 'Speed:', ...
                'Position', [10, 60, 50, 20], 'BackgroundColor', 'white');

            uicontrol('Parent', f, 'Style', 'pushbutton', 'String', '0.1x', ...
                'Position', [70, 60, 30, 20], 'Callback', @(~,~) this.setSpeed(0.1));

            uicontrol('Parent', f, 'Style', 'pushbutton', 'String', '0.5x', ...
                'Position', [105, 60, 30, 20], 'Callback', @(~,~) this.setSpeed(0.5));

            uicontrol('Parent', f, 'Style', 'pushbutton', 'String', '1x', ...
                'Position', [140, 60, 30, 20], 'Callback', @(~,~) this.setSpeed(1.0));

            uicontrol('Parent', f, 'Style', 'pushbutton', 'String', '2x', ...
                'Position', [175, 60, 30, 20], 'Callback', @(~,~) this.setSpeed(2.0));

            uicontrol('Parent', f, 'Style', 'pushbutton', 'String', '5x', ...
                'Position', [210, 60, 30, 20], 'Callback', @(~,~) this.setSpeed(5.0));
        end
    end
    methods (Access = protected)
        function f = buildFigure(this)
            f = figure(...
                'Toolbar','none',...
                'Visible','on',...
                'HandleVisibility','off', ...
                'NumberTitle','off',...
                'Name','Pick and Place 1D Environment',...
                'MenuBar','none',...
                'WindowStyle','normal',...
                'DockControls','off',...
                'CloseRequestFcn',@(~,~)delete(this));
            if ~strcmp(f.WindowStyle,'docked')
                f.Position = [200 100 1000 500]; % Increased width for better visibility
            end

            % Bring figure to front
            figure(f);

            ha = gca(f);
            ha.Tag = 'ha';
            ha.XLimMode = 'manual';
            ha.YLimMode = 'manual';
            ha.ZLimMode = 'manual';
            ha.DataAspectRatioMode = 'manual';
            ha.PlotBoxAspectRatioMode = 'manual';

            ha.XLim = [0 5];
            ha.YLim = [0 1];
            set(ha, 'DataAspectRatio',[1,1,1])

            % Add title and labels
            title(ha, 'Pick and Place Robot Environment');
            xlabel(ha, 'X Position');
            ylabel(ha, 'Y Position');
            grid(ha, 'on');

            % Add legend
            hold(ha, 'on');
            % Create invisible plots for legend
            plot(ha, NaN, NaN, 'bs', 'MarkerSize', 10, 'MarkerFaceColor', 'blue');
            plot(ha, NaN, NaN, 'ms', 'MarkerSize', 10, 'MarkerFaceColor', 'magenta');
            plot(ha, NaN, NaN, 'cs', 'MarkerSize', 10, 'MarkerFaceColor', 'cyan');
            plot(ha, NaN, NaN, 'gs', 'MarkerSize', 10, 'MarkerFaceColor', 'green');
            plot(ha, NaN, NaN, 'ys', 'MarkerSize', 10, 'MarkerFaceColor', 'yellow');
            plot(ha, NaN, NaN, 'rs', 'MarkerSize', 10, 'MarkerFaceColor', 'red');
            plot(ha, NaN, NaN, 'ko', 'MarkerSize', 10, 'MarkerFaceColor', 'black');
            legend(ha, {'Robot (empty)', 'Robot (carrying Obj1)', 'Robot (carrying Obj2)', 'Object1', 'Object2', 'Goal1', 'Goal2'}, ...
                'Location', 'eastoutside');
            hold(ha, 'off');

            % Add speed control buttons
            this.addSpeedControls();
        end

        function updatePlot(this)
            % Check if figure exists and is valid
            if isempty(this.Figure) || ~isvalid(this.Figure)
                return;
            end

            % Control visualization speed
            if this.VisualizationSpeed < 1.0
                % Calculate required delay for slower speeds
                elapsedTime = toc(this.LastUpdateTime);
                requiredDelay = (1.0 / this.VisualizationSpeed) / this.MaxFPS;

                if elapsedTime < requiredDelay
                    pause(requiredDelay - elapsedTime);
                end
            end
            this.LastUpdateTime = tic;

            % Empty cells are white.
            mapWithRobotandGoal = 255*ones([size(this.Environment.Map),3]);

            % Obstacles are black.
            mapWithRobotandGoal = mapWithRobotandGoal.* (~(this.Environment.Map == 1));

            robotXIndex = this.Environment.Robot.x + 1;
            robotYIndex = this.Environment.Robot.y + 1;
            goal1XIndex = this.Environment.Goal1.x + 1;
            goal1YIndex = this.Environment.Goal1.y + 1;
            goal2XIndex = this.Environment.Goal2.x + 1;
            goal2YIndex = this.Environment.Goal2.y + 1;
            obj1XIndex = this.Environment.Obj1.x + 1;
            obj1YIndex = this.Environment.Obj1.y + 1;
            obj2XIndex = this.Environment.Obj2.x + 1;
            obj2YIndex = this.Environment.Obj2.y + 1;

            % Goal1 is red.
            mapWithRobotandGoal(goal1YIndex, goal1XIndex, 1) = 255;
            mapWithRobotandGoal(goal1YIndex, goal1XIndex, 2) = 0;
            mapWithRobotandGoal(goal1YIndex, goal1XIndex, 3) = 0;

            % Goal2 is black.
            mapWithRobotandGoal(goal2YIndex, goal2XIndex, 1) = 0;
            mapWithRobotandGoal(goal2YIndex, goal2XIndex, 2) = 0;
            mapWithRobotandGoal(goal2YIndex, goal2XIndex, 3) = 0;

            % Object1 visualization (only if not being carried by robot and in valid position)
            if this.Environment.Robot.handle ~= 1 && ...
                    this.Environment.Obj1.x >= 0 && this.Environment.Obj1.x <= 4
                % Object1 is green when in the world
                mapWithRobotandGoal(obj1YIndex, obj1XIndex, 1) = 0;
                mapWithRobotandGoal(obj1YIndex, obj1XIndex, 2) = 255;
                mapWithRobotandGoal(obj1YIndex, obj1XIndex, 3) = 0;
            end

            % Object2 visualization (only if not being carried by robot and in valid position)
            if this.Environment.Robot.handle ~= 2 && ...
                    this.Environment.Obj2.x >= 0 && this.Environment.Obj2.x <= 4
                % Object2 is yellow when in the world
                mapWithRobotandGoal(obj2YIndex, obj2XIndex, 1) = 255;
                mapWithRobotandGoal(obj2YIndex, obj2XIndex, 2) = 255;
                mapWithRobotandGoal(obj2YIndex, obj2XIndex, 3) = 0;
            end

            % Robot visualization depends on whether it's carrying an object
            if this.Environment.Robot.handle == 1
                % Robot carrying object1 is magenta (mix of red and blue)
                mapWithRobotandGoal(robotYIndex, robotXIndex, 1) = 255;
                mapWithRobotandGoal(robotYIndex, robotXIndex, 2) = 0;
                mapWithRobotandGoal(robotYIndex, robotXIndex, 3) = 255;
            elseif this.Environment.Robot.handle == 2
                % Robot carrying object2 is cyan (mix of green and blue)
                mapWithRobotandGoal(robotYIndex, robotXIndex, 1) = 0;
                mapWithRobotandGoal(robotYIndex, robotXIndex, 2) = 255;
                mapWithRobotandGoal(robotYIndex, robotXIndex, 3) = 255;
            else
                % Robot without object is blue
                mapWithRobotandGoal(robotYIndex, robotXIndex, 1) = 0;
                mapWithRobotandGoal(robotYIndex, robotXIndex, 2) = 0;
                mapWithRobotandGoal(robotYIndex, robotXIndex, 3) = 255;
            end

            % Check if tasks are completed (objects at goal positions)
            % Object1 at Goal1
            if this.Environment.Obj1.x == this.Environment.Goal1.x && ...
                    this.Environment.Obj1.y == this.Environment.Goal1.y && ...
                    this.Environment.Robot.handle ~= 1
                % Success state: object1 at goal1 - keep red but add green component
                mapWithRobotandGoal(goal1YIndex, goal1XIndex, 1) = 255;
                mapWithRobotandGoal(goal1YIndex, goal1XIndex, 2) = 128;
                mapWithRobotandGoal(goal1YIndex, goal1XIndex, 3) = 0;
            end

            % Object2 at Goal2
            if this.Environment.Obj2.x == this.Environment.Goal2.x && ...
                    this.Environment.Obj2.y == this.Environment.Goal2.y && ...
                    this.Environment.Robot.handle ~= 2
                % Success state: object2 at goal2 - keep black but add green component
                mapWithRobotandGoal(goal2YIndex, goal2XIndex, 1) = 0;
                mapWithRobotandGoal(goal2YIndex, goal2XIndex, 2) = 128;
                mapWithRobotandGoal(goal2YIndex, goal2XIndex, 3) = 0;
            end

            f = this.Figure;
            ha = findobj(f,'Tag','ha');
            img  = findobj(f ,'Tag','img' );
            if isempty(img)
                img = image(0,0,mapWithRobotandGoal, 'Parent',ha);
                img.Tag = 'img';
                set(ha, 'DataAspectRatio',[1,1,1])
                set(ha, 'ydir', 'normal' )
            else
                img.CData = mapWithRobotandGoal;
            end

            % Update title with current state information
            if this.Environment.Robot.handle == 1
                robotStatus = 'carrying object1';
            elseif this.Environment.Robot.handle == 2
                robotStatus = 'carrying object2';
            else
                robotStatus = 'empty hands';
            end

            if this.Environment.Obj1.x == this.Environment.Goal1.x && ...
                    this.Environment.Obj1.y == this.Environment.Goal1.y && ...
                    this.Environment.Robot.handle ~= 1
                taskStatus = ' - TASK COMPLETED!';
            elseif this.Environment.Obj2.x == this.Environment.Goal2.x && ...
                    this.Environment.Obj2.y == this.Environment.Goal2.y && ...
                    this.Environment.Robot.handle ~= 2
                taskStatus = ' - TASK COMPLETED!';
            else
                taskStatus = '';
            end

            title(ha, sprintf('Pick & Place - Robot: (%d,%s), Object1: (%d,%d), Object2: (%d,%d), Goal1: (%d,%d), Goal2: (%d,%d)%s', ...
                this.Environment.Robot.x, robotStatus, ...
                this.Environment.Obj1.x, this.Environment.Obj1.y, ...
                this.Environment.Obj2.x, this.Environment.Obj2.y, ...
                this.Environment.Goal1.x, this.Environment.Goal1.y, ...
                this.Environment.Goal2.x, this.Environment.Goal2.y, taskStatus));

            % Force figure to front and refresh
            figure(f);

            % Apply speed control for refresh rate
            if this.VisualizationSpeed >= 1.0
                % For faster speeds, use limitrate to control max refresh rate
                drawnow limitrate;
            else
                drawnow();
            end
        end
    end
end