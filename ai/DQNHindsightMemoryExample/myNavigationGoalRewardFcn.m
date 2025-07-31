function reward = myNavigationGoalRewardFcn(State, Action, NextState)


isdone = myNavigationGoalIsDoneFcn(State, Action, NextState);
if isdone
    reward = 2;
else
    reward = -0.01;
    if State{1}(1) == NextState{1}(1) && State{1}(2) == NextState{1}(2) && State{1}(3) == NextState{1}(3) && State{1}(4) == NextState{1}(4) && State{1}(5) == NextState{1}(5) %|| ...
            % Action{1} == 1 && State{1}(1) ~= State{1}(2)  || ... % If the robot is not in object position, it can't pick it up
            % Action{1} == 2 && State{1}(2) ~= -1 % If the robot is not carrying the object, it can't place it
            reward = reward - 0.01;
    end
end
end