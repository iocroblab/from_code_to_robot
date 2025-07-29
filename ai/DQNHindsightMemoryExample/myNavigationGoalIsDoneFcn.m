function isdone = myNavigationGoalIsDoneFcn(State, Action, NextState)
    % myNavigationGoalIsDoneFcn

    % Copyright 2023 The MathWorks, Inc.

    isdone = NextState{1}(2) == NextState{1}(3);
end