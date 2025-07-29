classdef PickPlaceDiscreteEnv < rl.env.MATLABEnvironment
    %PICK_PLACE: Template for defining custom environment in MATLAB.

    %% Properties (set properties' attributes accordingly)
    properties (Access = public)

        %num_locations: Length of the 1D line
        num_locations = 4

        %num_objects: Number of objects to be moved
        num_objects = 2

        penalty_invalid = -5

        penalty_random_move = -0.1

        reward_robot_move_to_obj = 0.5

        reward_correct_pick = 1

        reward_correct_place = 0 % Ya se le añade el reward de la posición correcta

        reward_robot_move_to_obj_targ = 1.5

        reward_incorrect_pick = -0.5

        reward_incorrect_place = -0.5


        State

        % Target positions for each object: target_pos(object_index) = target_position
        target_pos

        % Current reward from last action
        CurrentReward = 0

        % Initialize internal flag to indicate episode termination
        IsDone = false

        % Map of objects: map_objects(position) = object_index (0 if empty)
        map_objects

        % Array of object positions: objects_pos(object_index) = position
        objects_pos

        % Position of the arm (0 to num_locations)
        arm_pos

        % State of the arm: 0 = empty, >0 = holding object with that index
        arm_state

    end


    properties(Access = protected)

        % Visualization properties
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
        % Contructor method creates an instance of the environment
        % Change class name and constructor name accordingly
        function this = PickPlaceDiscreteEnv(num_objects, num_locations)
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
            % 1 = pick
            % 2 = place
            %3+ = move to location
            ActionInfo = rlFiniteSetSpec([1, 2, 3:num_locations+2]);
            ActionInfo.Name = 'Action';

            % The following line implements built-in functions of RL env
            this = this@rl.env.MATLABEnvironment(ObservationInfo, ActionInfo);

            % Now set the properties
            this.num_objects = num_objects;
            this.num_locations = num_locations;

            this.State = reset(this);

            % Initialize property values and pre-compute necessary values
            updateActionInfo(this);

            % Initialize visualization
            initializeVisualization(this);
        end

        % Apply system dynamics and simulates the environment with the
        % given action for one step.
        function [Observation, Reward, IsDone, Info] = step(this,Action)
            arguments
                this
                Action
            end

            Info = [];


            if Action == 1 % pick
                if this.arm_state == 0 && this.map_objects(this.arm_pos) > 0 % arm is empty && exists object in the arm position
                    obj_index = this.map_objects(this.arm_pos);
                    % if this.objects_pos(obj_index) == this.target_pos(obj_index)
                    %     Reward = this.reward_incorrect_pick;
                    % else
                    %     Reward = this.reward_correct_pick;
                    % end

                    this.arm_state = obj_index;
                    this.map_objects(this.arm_pos) = 0;
                    this.objects_pos(obj_index) = 0; % 0 means object is being carried
                % else
                %     Reward = this.penalty_invalid;
                end

            elseif Action == 2 % place
                if this.arm_state > 0 && this.map_objects(this.arm_pos) == 0 % arm is holding && no object in the arm position

                    obj_index = this.arm_state;
                    new_obj_pos = this.arm_pos;
                    current_target_pos = this.target_pos(obj_index);

                    % if new_obj_pos == current_target_pos
                    %     Reward = this.reward_correct_place;
                    % else
                    %     Reward = this.reward_incorrect_place;
                    % end
                    this.map_objects(new_obj_pos) = obj_index;
                    this.objects_pos(obj_index) = new_obj_pos;
                    this.arm_state = 0; % now arm is empty
                % else
                %     Reward = this.penalty_invalid;
                end
                
            elseif Action > 2 % move to location

                is_holding_obj = this.arm_state > 0;
                obj_index = this.arm_state;

                new_location = Action - 2; % Actions 3,4,5,... map to locations 1,2,3,...
                % if this.arm_pos == new_location || new_location < 1 || new_location > this.num_locations
                %     Reward = this.penalty_invalid;
                % elseif is_holding_obj && new_location == this.target_pos(obj_index)
                %     Reward = this.reward_robot_move_to_obj_targ;
                % elseif ~is_holding_obj && this.map_objects(new_location) > 0
                %     Reward = this.reward_robot_move_to_obj;
                % else
                %     Reward = this.penalty_random_move;
                % end
                this.arm_pos = new_location;

            end



            % penalty_not_in_target = 0;

            % for i = 1:this.num_objects
            %     if this.objects_pos(i) ~= this.target_pos(i)
            %         penalty_not_in_target = penalty_not_in_target - 2;
            %     end
            % end

            % Reward = Reward + penalty_not_in_target;


            Observation = [this.arm_pos;this.arm_state;this.objects_pos; this.target_pos];
            
            Reward = PickPlaceRewardFunc({this.State}, {Action}, {Observation});
            % Store the current reward for visualization
            this.CurrentReward = Reward;
            IsDone = PickPlaceIsDoneFunc({this.State}, {Action}, {Observation});
            % Update system states
            this.State = Observation;


            % Check if all objects are in their target positions
            this.IsDone = IsDone;

            % (optional) use notifyEnvUpdated to signal that the
            % environment has been updated (e.g. to update visualization)
            notifyEnvUpdated(this);
        end

        % Reset environment to initial state and output initial observation
        function InitialObservation = reset(this)
            this.arm_pos = randi([1,this.num_locations]); % Changed to 1-based indexing
            this.arm_state = 0; % 0 = empty, 1 = holding object 1, 2 = holding object 2, etc.

            % Generate valid positions for objects (excluding arm position)
            valid_positions = setdiff(1:this.num_locations, this.arm_pos); % Fixed arm_pos reference and indexing

            this.map_objects = zeros(this.num_locations, 1); % Index 1 to num_locations for physical locations

            % Ensure we have enough valid positions for all objects
            if length(valid_positions) >= this.num_objects
                % Select random positions from valid positions without replacement
                selected_indices = randperm(length(valid_positions), this.num_objects);
                this.objects_pos = valid_positions(selected_indices)';
                for i = 1:this.num_objects
                    this.map_objects(this.objects_pos(i)) = i;
                end
            else
                error('Not enough valid positions for objects');
            end


            % Generate target positions (each different from its corresponding object position)
            this.target_pos = zeros(this.num_objects, 1);
            assigned_targets = [];  % Keep track of already assigned targets

            for i = 1:this.num_objects
                % Valid target positions exclude the current object position and already assigned targets
                valid_targets = setdiff(1:this.num_locations, [this.objects_pos(i), assigned_targets]);
                % Select random target from valid positions
                selected_index = randperm(length(valid_targets), 1);
                this.target_pos(i) = valid_targets(selected_index);
                % Add this target to assigned targets
                assigned_targets = [assigned_targets, this.target_pos(i)];
            end

            InitialObservation = [this.arm_pos;this.arm_state;this.objects_pos; this.target_pos];
            this.State = InitialObservation;

            % (optional) use notifyEnvUpdated to signal that the
            % environment has been updated (e.g. to update visualization)
            notifyEnvUpdated(this);
        end
    end
    %% Optional Methods (set methods' attributes accordingly)
    methods
        % Helper methods to create the environment
        % Discrete force 1 or 2

        % update the action info based on max force
        function updateActionInfo(this)
            this.ActionInfo.Elements = 1:this.num_locations+2;
        end


        % (optional) Visualization method
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
        % (optional) update visualization everytime the environment is updated
        % (notifyEnvUpdated is called)
        function envUpdatedCallback(this)
            updateVisualization(this);
        end
    end

end
