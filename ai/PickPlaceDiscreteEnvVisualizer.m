classdef PickPlaceDiscreteEnvVisualizer < rl.env.viz.AbstractFigureVisualizer


    methods
        function this = PickPlaceDiscreteEnvVisualizer(env)
            this = this@rl.env.viz.AbstractFigureVisualizer(env);
        end
    end
    methods (Access = protected)
        function f = buildFigure(this)
            f = figure(...
                'Toolbar','none',...
                'Visible','on',...
                'HandleVisibility','off', ...
                'NumberTitle','off',...
                'Name','Pick and Place Environment',...
                'MenuBar','none',...
                'CloseRequestFcn',@(~,~)delete(this));
            if ~strcmp(f.WindowStyle,'docked')
                f.Position = [200 100 1000 500]; % Increased width to accommodate legend
            end
            ha = gca(f);
            ha.Tag = 'ha';
            ha.XLimMode = 'manual';
            ha.YLimMode = 'manual';
            ha.ZLimMode = 'manual';
            ha.DataAspectRatioMode = 'manual';
            ha.PlotBoxAspectRatioMode = 'manual';

            ha.XLim = [0 21];
            ha.YLim = [0 21];
            set(ha, 'DataAspectRatio',[1,1,1])
        end

        function updatePlot(this)
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
            drawnow();
        end
    end
end