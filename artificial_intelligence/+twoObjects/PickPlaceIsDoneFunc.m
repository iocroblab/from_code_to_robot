function isdone = PickPlaceIsDoneFunc(State, Action, NextState)
    isdone = NextState{1}(3) == NextState{1}(5) && NextState{1}(4) == NextState{1}(6);
end