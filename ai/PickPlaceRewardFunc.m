function reward = PickPlaceRewardFunc(State, Action, NextState)
isdone = PickPlaceIsDoneFunc(State, Action, NextState);
if isdone
    reward = 2;
else

    reward = -0.01;

    arm_pos = State{1}(1);
    arm_state = State{1}(2);
    objects_pos = State{1}(3:4);

    Action = Action{1};


    if Action == 1 % pick
        % arm is empty || not exists object in the arm position
        if arm_state ~= 0 || ~hasObjectAtPosition(objects_pos, arm_pos)
            reward = reward - 0.01;
            % disp("Invalid pick");
        end

    elseif Action == 2 % place
        if arm_state == 0 || hasObjectAtPosition(objects_pos, arm_pos)
            reward = reward - 0.01;
            % disp("Invalid place");
        end
    elseif Action > 2 % move to location

        new_location = Action - 2; % Actions 3,4,5,... map to locations 1,2,3,...
        if arm_pos == new_location
            reward = reward - 0.01;
            % disp("Invalid move");
        end
    end

end
end

function hasObject = hasObjectAtPosition(objects_pos, position)
% Check if there's any object at the specified position
% objects_pos: array containing object positions [obj1_pos, obj2_pos, ...]
% position: position to check
% Returns: true if there's an object at the position, false otherwise

    hasObject = any(objects_pos == position);
end