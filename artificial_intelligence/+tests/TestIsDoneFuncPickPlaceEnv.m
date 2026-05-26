classdef TestIsDoneFuncPickPlaceEnv < matlab.unittest.TestCase
    properties
        IsDoneFuncHandle
    end

    methods (Test)

        function testIsDone(testCase)
            State = {[3, 1, 0, 3]};
            Action = {[2]};
            NextState = {[3, 0, 3, 3]};

            isdone = testCase.IsDoneFuncHandle(State, Action, NextState);
            testCase.assertEqual(isdone, true);


            NextState = {[3, 0, 2, 2]};

            isdone = testCase.IsDoneFuncHandle(State, Action, NextState);
            testCase.assertEqual(isdone, true);


            NextState = {[3, 0, 1, 1]};

            isdone = testCase.IsDoneFuncHandle(State, Action, NextState);
            testCase.assertEqual(isdone, true);

        end

        function testNotIsDone(testCase)
            State = {[3, 1, 0, 3]};
            Action = {[2]};
            NextState = {[3, 0, 1, 3]};

            isdone = testCase.IsDoneFuncHandle(State, Action, NextState);
            testCase.assertEqual(isdone, false);

            NextState = {[3, 0, 2, 3]};

            isdone = testCase.IsDoneFuncHandle(State, Action, NextState);
            testCase.assertEqual(isdone, false);


            NextState = {[3, 0, 0, 3]};

            isdone = testCase.IsDoneFuncHandle(State, Action, NextState);
            testCase.assertEqual(isdone, false);

        end

    end

end


