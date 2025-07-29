classdef NavigationDiscreteEnvVisualizer < rl.env.viz.AbstractFigureVisualizer
    % NavigationDiscreteEnvVisualizer

    % Copyright 2023 The MathWorks, Inc.

    methods
        function this = NavigationDiscreteEnvVisualizer(env)
            this = this@rl.env.viz.AbstractFigureVisualizer(env);
        end
    end
    methods (Access = protected)
        function f = buildFigure(this)
            f = figure(...
                'Toolbar','none',...
                'Visible','on',...
                'HandleVisibility','on', ...
                'NumberTitle','off',...
                'Name','Navigation 2D',...
                'MenuBar','none',...
                'WindowStyle','normal',...
                'DockControls','off',...
                'CloseRequestFcn',@(~,~)delete(this));
            if ~strcmp(f.WindowStyle,'docked')
                f.Position = [200 100 800 500];
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

            ha.XLim = [0 10];
            ha.YLim = [0 1];
            set(ha, 'DataAspectRatio',[1,1,1])

            % Add title and labels
            title(ha, 'Robot Navigation Environment');
            xlabel(ha, 'X Position');
            ylabel(ha, 'Y Position');
            grid(ha, 'on');
        end

        function updatePlot(this)
            % Check if figure exists and is valid
            if isempty(this.Figure) || ~isvalid(this.Figure)
                return;
            end

            % Empty cells are white.
            mapWithRobotandGoal = 255*ones([size(this.Environment.Map),3]);

            % Obstacles are black.
            mapWithRobotandGoal = mapWithRobotandGoal.* (~(this.Environment.Map == 1));


            robotXIndex = this.Environment.Robot.x + 1;
            robotYIndex = this.Environment.Robot.y + 1;
            goalXIndex = this.Environment.Goal.x + 1;
            goalYIndex = this.Environment.Goal.y + 1;


            % Robot is blue.
            mapWithRobotandGoal(robotYIndex, robotXIndex, 1) = 0;
            mapWithRobotandGoal(robotYIndex, robotXIndex, 2) = 0;
            mapWithRobotandGoal(robotYIndex, robotXIndex, 3) = 255;

            % Goal is red.
            mapWithRobotandGoal(goalYIndex, goalXIndex, 1) = 255;
            mapWithRobotandGoal(goalYIndex, goalXIndex, 2) = 0;
            mapWithRobotandGoal(goalYIndex, goalXIndex, 3) = 0;

            % If robot reached goal, make it magenta (mix of red and blue)
            if this.Environment.Robot.x == this.Environment.Goal.x && this.Environment.Robot.y == this.Environment.Goal.y
                mapWithRobotandGoal(goalYIndex, goalXIndex, 1) = 255;
                mapWithRobotandGoal(goalYIndex, goalXIndex, 2) = 0;
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
            title(ha, sprintf('Robot Navigation - Robot: (%d,%d), Goal: (%d,%d)', ...
                this.Environment.Robot.x, this.Environment.Robot.y, ...
                this.Environment.Goal.x, this.Environment.Goal.y));

            % Force figure to front and refresh
            figure(f);
            drawnow();
        end
    end
end