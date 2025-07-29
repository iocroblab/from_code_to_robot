function reward = myNavigationGoalRewardFcn(State, Action, NextState)
    % myNavigationGoalRewardFcn

    % Copyright 2023 The MathWorks, Inc.

    isdone = myNavigationGoalIsDoneFcn(State, Action, NextState);
    if isdone
        reward = 2;
    else
        reward = -0.01;
        if State{1}(1) == NextState{1}(1) && State{1}(2) == NextState{1}(2)
            reward = reward - 0.01;
        end
    end
end