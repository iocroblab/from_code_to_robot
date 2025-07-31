function reward = PickPlaceRewardFunc(State, Action, NextState)
isdone = PickPlaceIsDoneFunc(State, Action, NextState);
if isdone
    reward = 2;
else

    reward = 0;

    arm_pos = State{1}(1);
    arm_state = State{1}(2);
    objects_pos = State{1}(3:4);
    target_pos = State{1}(5:6);

    Action = Action{1};


    if Action == 1 % pick
        % arm is empty || not exists object in the arm position
        [hasObject, idx] = hasObjectAtPosition(objects_pos, arm_pos);
        if arm_state == 0 && hasObject
    
            if target_pos(idx) ~= arm_pos 
                reward = reward + 1;
            else
                % picking the object in target position
                reward = reward - 5;
            end

        else % invalid pick
            reward = reward - 5;
        end

    elseif Action == 2 % place

        [hasObject, idx] = hasObjectAtPosition(objects_pos, arm_pos);
        if arm_state > 0 && ~hasObject
            obj_index = arm_state;

            % if target_pos(obj_index) ~= arm_pos 
            %     reward = reward - 5;
            % end
        else % invalid place
            reward = reward - 5;
        end

    elseif Action > 2 % move to location
        is_holding_obj = arm_state > 0;
        obj_index = arm_state;
        new_location = Action - 2; % Actions 3,4,5,... map to locations 1,2,3,...
        
        disp("new_location")
        disp(new_location)

        [hasObject, idx] = hasObjectAtPosition(objects_pos, new_location);

        if arm_pos == new_location
            reward = reward - 0.01;
            % disp("Invalid move");

        elseif is_holding_obj && new_location == target_pos(obj_index)
            reward = reward + 1.5;
        
        elseif ~is_holding_obj && hasObject && target_pos(idx) ~= new_location
            reward = reward + 0.5;
        else
            reward = reward - 0.01;
        end

        


    end

    objects_pos = NextState{1}(3:4);
    target_pos = NextState{1}(5:6);

    for i = 1:2
        if objects_pos(i) ~= target_pos(i)
            reward = reward - 2;
        end
    end

end
end

function [hasObject, idx] = hasObjectAtPosition(objects_pos, position)
% Check if there's any object at the specified position
% objects_pos: array containing object positions [obj1_pos, obj2_pos, ...]
% position: position to check
% Returns: hasObject (true if there's an object at the position, false otherwise)
%          idx (index of the object if found, -1 otherwise)

idx = find(objects_pos == position, 1); % Encuentra el primer índice
    if ~isempty(idx)
        hasObject = true;
    else
        hasObject = false;
        idx = -1;
    end
end