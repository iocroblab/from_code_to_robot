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
                'HandleVisibility','on', ...
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
            plot(ha, NaN, NaN, 'gs', 'MarkerSize', 10, 'MarkerFaceColor', 'green');
            plot(ha, NaN, NaN, 'rs', 'MarkerSize', 10, 'MarkerFaceColor', 'red');
            plot(ha, NaN, NaN, 'cs', 'MarkerSize', 10, 'MarkerFaceColor', 'cyan');
            legend(ha, {'Robot (empty)', 'Robot (carrying)', 'Object', 'Goal', 'Success'}, ...
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
            goalXIndex = this.Environment.Goal.x + 1;
            goalYIndex = this.Environment.Goal.y + 1;
            objXIndex = this.Environment.Obj.x + 1;
            objYIndex = this.Environment.Obj.y + 1;

            % Goal is red.
            mapWithRobotandGoal(goalYIndex, goalXIndex, 1) = 255;
            mapWithRobotandGoal(goalYIndex, goalXIndex, 2) = 0;
            mapWithRobotandGoal(goalYIndex, goalXIndex, 3) = 0;

            % Object visualization (only if not being carried by robot)
            if this.Environment.Robot.handle == 0 && ...
                    this.Environment.Obj.x >= 0 && this.Environment.Obj.x <= 9 && ...
                    this.Environment.Obj.y >= 0 && this.Environment.Obj.y <= 9
                % Object is green when in the world
                mapWithRobotandGoal(objYIndex, objXIndex, 1) = 0;
                mapWithRobotandGoal(objYIndex, objXIndex, 2) = 255;
                mapWithRobotandGoal(objYIndex, objXIndex, 3) = 0;
            end

            % Robot visualization depends on whether it's carrying the object
            if this.Environment.Robot.handle == 1
                % Robot carrying object is magenta (mix of red and blue)
                mapWithRobotandGoal(robotYIndex, robotXIndex, 1) = 255;
                mapWithRobotandGoal(robotYIndex, robotXIndex, 2) = 0;
                mapWithRobotandGoal(robotYIndex, robotXIndex, 3) = 255;
            else
                % Robot without object is blue
                mapWithRobotandGoal(robotYIndex, robotXIndex, 1) = 0;
                mapWithRobotandGoal(robotYIndex, robotXIndex, 2) = 0;
                mapWithRobotandGoal(robotYIndex, robotXIndex, 3) = 255;
            end

            % Check if task is completed (object at goal position)
            if this.Environment.Obj.x == this.Environment.Goal.x && ...
                    this.Environment.Obj.y == this.Environment.Goal.y && ...
                    this.Environment.Robot.handle == 0
                % Success state: object at goal is cyan
                mapWithRobotandGoal(goalYIndex, goalXIndex, 1) = 0;
                mapWithRobotandGoal(goalYIndex, goalXIndex, 2) = 255;
                mapWithRobotandGoal(goalYIndex, goalXIndex, 3) = 255;
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
                robotStatus = 'carrying object';
            else
                robotStatus = 'empty hands';
            end

            if this.Environment.Obj.x == this.Environment.Goal.x && ...
                    this.Environment.Obj.y == this.Environment.Goal.y && ...
                    this.Environment.Robot.handle == 0
                taskStatus = ' - TASK COMPLETED!';
            else
                taskStatus = '';
            end

            title(ha, sprintf('Pick & Place - Robot: (%d,%s), Object: (%d,%d), Goal: (%d,%d)%s', ...
                this.Environment.Robot.x, robotStatus, ...
                this.Environment.Obj.x, this.Environment.Obj.y, ...
                this.Environment.Goal.x, this.Environment.Goal.y, taskStatus));

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