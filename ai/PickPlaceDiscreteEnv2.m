

classdef PickPlaceDiscreteEnv2 < rl.env.MATLABEnvironment
    %PICK_PLACE: Template for defining custom environment in MATLAB.

    %% Properties (set properties' attributes accordingly)
    properties (Access = public)

        % num_locations: Number of discrete locations in the environment (1D line)
        num_locations = 4

        % num_objects: Number of objects to be moved by the robot
        num_objects = 2

        % State vector of the environment
        State

        % Target positions for each object: target_pos(object_index) = target_position
        target_pos

        % Current reward from last action (for visualization)
        CurrentReward = 0

        % Internal flag to indicate episode termination
        IsDone = false

        % Map of objects: map_objects(position) = object_index (0 if empty)
        map_objects

        % Array of object positions: objects_pos(object_index) = position
        objects_pos

        % Position of the arm (1 to num_locations)
        arm_pos

        % State of the arm: 0 = empty, >0 = holding object with that index
        arm_state

        StepFunc

        ResetFunc

    end


    properties(Access = protected)

        % Visualization properties (handles for figure and plot elements)
        VisualizationFigure
        VisualizationAxes
        ArmHandle
        ObjectHandles
        TargetHandles
        LocationHandles
        StatusTextHandle
        RewardTextHandle
    end

    %% Necessary Methods
    methods
        % Constructor method creates an instance of the environment
        function this = PickPlaceDiscreteEnv2(num_objects, num_locations, StepFunc, ResetFunc)
            % Set default values if not provided
            if nargin < 1 || isempty(num_objects)
                num_objects = 1;
            end
            if nargin < 2 || isempty(num_locations)
                num_locations = 3;
            end

            % Initialize Observation settings
            ObservationInfo = rlNumericSpec([2 + num_objects * 2, 1]);
            ObservationInfo.Name = 'Pick_Place States';
            ObservationInfo.Description = 'arm pos, arm state, objects position, target position';

            % Initialize Action settings
            % 1 = pick, 2 = place, 3+ = move to location
            ActionInfo = rlFiniteSetSpec([1, 2, 3:num_locations+2]);
            ActionInfo.Name = 'Action';

            % Call superclass constructor
            this = this@rl.env.MATLABEnvironment(ObservationInfo, ActionInfo);

            % Set environment properties
            this.num_objects = num_objects;
            this.num_locations = num_locations;

            this.StepFunc = StepFunc;
            this.ResetFunc = ResetFunc;

            % Initialize state
            this.State = reset(this);

            % Update action info (in case num_locations changed)
            updateActionInfo(this);

            % Initialize visualization
            initializeVisualization(this);
        end

        % Apply system dynamics and simulate the environment for one step
        function [Observation, Reward, IsDone, Info] = step(this,Action)
            arguments
                this
                Action
            end

            Info = [];

            [new_this, Observation, Reward, IsDone] = this.StepFunc(this, Action);
            
            this = new_this;

            notifyEnvUpdated(this);
        end

        % Reset environment to initial state and output initial observation
        function InitialObservation = reset(this)
            
            [new_this, InitialObservation] = this.ResetFunc(this);
                        this = new_this;
            % (optional) use notifyEnvUpdated to signal that the
            % environment has been updated (e.g. to update visualization)
            notifyEnvUpdated(this);
        end
    end
    %% Optional Methods (set methods' attributes accordingly)
    methods
        % Helper method to update the action info based on number of locations
        function updateActionInfo(this)
            this.ActionInfo.Elements = 1:this.num_locations+2;
        end


        % (optional) Visualization method to plot the environment
        function plot(this)
            % Initiate the visualization
            if isempty(this.VisualizationFigure) || ~isvalid(this.VisualizationFigure)
                initializeVisualization(this);
            end

            % Make sure the figure is visible and on top
            set(this.VisualizationFigure, 'Visible', 'on');
            figure(this.VisualizationFigure);

            % Update the visualization
            updateVisualization(this);
        end

        % Initialize the visualization window and axes
        function initializeVisualization(this)
            % Create visualization figure with proper properties for independent window
            this.VisualizationFigure = figure('Name', 'Pick & Place Environment', ...
                'NumberTitle', 'off', ...
                'Position', [100, 100, 800, 400], ...
                'Visible', 'on', ...
                'WindowStyle', 'normal', ...
                'DockControls', 'off', ...
                'MenuBar', 'none', ...
                'ToolBar', 'none', ...
                'Resize', 'on', ...
                'CloseRequestFcn', @(src,evt) set(src, 'Visible', 'off'));

            % Make sure the figure appears on top
            figure(this.VisualizationFigure);

            this.VisualizationAxes = axes(this.VisualizationFigure);
            hold(this.VisualizationAxes, 'on');

            % Set axis properties
            axis(this.VisualizationAxes, 'equal');
            xlim(this.VisualizationAxes, [0.5, this.num_locations + 0.5]);
            ylim(this.VisualizationAxes, [-0.5, 3]);

            % Draw location markers
            this.LocationHandles = [];
            for i = 1:this.num_locations
                h = plot(this.VisualizationAxes, i, 0, 'k-', 'LineWidth', 3, 'MarkerSize', 15);
                this.LocationHandles = [this.LocationHandles, h];
                text(this.VisualizationAxes, i, -0.3, sprintf('Loc %d', i), ...
                    'HorizontalAlignment', 'center', 'FontSize', 10);
            end

            % Draw base line
            plot(this.VisualizationAxes, [0.5, this.num_locations + 0.5], [0, 0], 'k-', 'LineWidth', 2);

            % Initialize handles for dynamic elements
            this.ArmHandle = [];
            this.ObjectHandles = [];
            this.TargetHandles = [];
            this.StatusTextHandle = [];
            this.RewardTextHandle = [];

            % Set labels and title
            xlabel(this.VisualizationAxes, 'Locations');
            ylabel(this.VisualizationAxes, '');
            title(this.VisualizationAxes, 'Pick & Place Environment');
            grid(this.VisualizationAxes, 'on');
        end

        % Update the visualization with the current state
        function updateVisualization(this)
            if isempty(this.VisualizationFigure) || ~isvalid(this.VisualizationFigure)
                return;
            end

            % Clear previous dynamic elements
            if ~isempty(this.ArmHandle) && isvalid(this.ArmHandle)
                delete(this.ArmHandle);
            end
            if ~isempty(this.ObjectHandles)
                for i = 1:length(this.ObjectHandles)
                    if isvalid(this.ObjectHandles(i))
                        delete(this.ObjectHandles(i));
                    end
                end
            end
            if ~isempty(this.TargetHandles)
                for i = 1:length(this.TargetHandles)
                    if isvalid(this.TargetHandles(i))
                        delete(this.TargetHandles(i));
                    end
                end
            end
            if ~isempty(this.StatusTextHandle) && isvalid(this.StatusTextHandle)
                delete(this.StatusTextHandle);
            end
            if ~isempty(this.RewardTextHandle) && isvalid(this.RewardTextHandle)
                delete(this.RewardTextHandle);
            end

            % Define colors for objects
            colors = {'red', 'blue', 'green', 'magenta', 'cyan', 'yellow'};

            % Draw arm
            this.ArmHandle = plot(this.VisualizationAxes, this.arm_pos, 1.5, 'ko', ...
                'MarkerSize', 20, 'MarkerFaceColor', 'black', 'DisplayName', 'Robot Arm');

            % Draw objects and targets
            this.ObjectHandles = [];
            this.TargetHandles = [];

            for i = 1:this.num_objects
                color = colors{mod(i-1, length(colors)) + 1};

                % Draw target position (cross)
                target_x = this.target_pos(i);
                h_target = plot(this.VisualizationAxes, target_x, 0.5, 'x', ...
                    'Color', color, 'MarkerSize', 15, 'LineWidth', 3, ...
                    'DisplayName', sprintf('Target %d', i));
                this.TargetHandles = [this.TargetHandles, h_target];

                % Draw object (if not being carried)
                if this.objects_pos(i) > 0  % Object is on the ground
                    obj_x = this.objects_pos(i);
                    h_obj = plot(this.VisualizationAxes, obj_x, 0.5, 'o', ...
                        'Color', color, 'MarkerSize', 12, 'MarkerFaceColor', color, ...
                        'DisplayName', sprintf('Object %d', i));
                    this.ObjectHandles = [this.ObjectHandles, h_obj];
                end
            end

            % Show what the arm is carrying
            arm_status = '';
            if this.arm_state > 0
                color = colors{mod(this.arm_state-1, length(colors)) + 1};
                % Draw carried object next to the arm
                h_carried = plot(this.VisualizationAxes, this.arm_pos, 2, 'o', ...
                    'Color', color, 'MarkerSize', 10, 'MarkerFaceColor', color, ...
                    'DisplayName', sprintf('Carrying Object %d', this.arm_state));
                this.ObjectHandles = [this.ObjectHandles, h_carried];
                arm_status = sprintf('Carrying Object %d', this.arm_state);
            else
                arm_status = 'Empty';
            end

            % Add status text
            status_text = sprintf('Arm at Location %d | Status: %s', this.arm_pos, arm_status);
            this.StatusTextHandle = text(this.VisualizationAxes, 0.5, 2.5, status_text, ...
                'FontSize', 12, 'FontWeight', 'bold');

            % Add reward text
            reward_text = sprintf('Current Reward: %.2f', this.CurrentReward);
            this.RewardTextHandle = text(this.VisualizationAxes, 0.5, 2.2, reward_text, ...
                'FontSize', 12, 'FontWeight', 'bold');

            % Check if episode is done
            if this.IsDone
                done_text = text(this.VisualizationAxes, this.num_locations/2 + 0.5, 2.7, ...
                    'EPISODE COMPLETED!', 'FontSize', 14, 'FontWeight', 'bold', ...
                    'Color', 'green', 'HorizontalAlignment', 'center');
            end

            % Add legend for plotted elements
            legend(this.VisualizationAxes, 'Location', 'eastoutside');

            drawnow;
        end


    end

    methods (Access = protected)
        % (optional) update visualization every time the environment is updated
        % (notifyEnvUpdated is called)
        function envUpdatedCallback(this)
            updateVisualization(this);
        end
    end

end
