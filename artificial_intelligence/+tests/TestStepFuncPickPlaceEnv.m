classdef TestStepFuncPickPlaceEnv < matlab.unittest.TestCase
    properties
        StepFuncHandle
    end

    methods (Test)
        function testPickValid(testCase)
            env = createTestEnv();
            env.arm_pos = 1;
            env.arm_state = 0;
            env.objects_pos = [1];
            env.target_pos = [2];
            env.map_objects = zeros(env.num_locations,1);
            env.map_objects(1) = 1;
            env.State = [env.arm_pos; env.arm_state; env.objects_pos; env.target_pos];
            [env, obs, ~, ~, ~] = testCase.StepFuncHandle(env, 1); % Action pick

            testCase.assertEqual(env.arm_state, 1, 'The arm should be holding the object');
            testCase.assertEqual(env.objects_pos(1), 0, 'The object position should be 0 (being carried)');
        end

        function testPickInvalid_NoObject(testCase)
            env = createTestEnv();
            env.arm_pos = 1;
            env.arm_state = 0;
            env.objects_pos = [2];
            env.target_pos = [3];
            env.map_objects = zeros(env.num_locations,1);
            env.map_objects(2) = 1;
            env.State = [env.arm_pos; env.arm_state; env.objects_pos; env.target_pos];
            [env, obs, ~, ~, ~] = testCase.StepFuncHandle(env, 1); % Acción pick
            testCase.assertEqual(env.arm_state, 0, 'The arm should remain empty');
            testCase.assertEqual(env.objects_pos(1), 2, 'The object position should not change');
        end

        function testPickInvalid_ArmNotEmpty(testCase)
            env = createTestEnv();
            env.arm_pos = 1;
            env.arm_state = 1;
            env.objects_pos = [0];
            env.target_pos = [2];
            env.map_objects = zeros(env.num_locations,1);
            env.State = [env.arm_pos; env.arm_state; env.objects_pos; env.target_pos];
            [env, obs, ~, ~, ~] = testCase.StepFuncHandle(env, 1); % Acción pick
            testCase.assertEqual(env.arm_state, 1, 'The arm should still be holding the object');
            testCase.assertEqual(env.objects_pos(1), 0, 'The object position should not change');
        end

        function testPlaceValid(testCase)
            env = createTestEnv();
            env.arm_pos = 2;
            env.arm_state = 1;
            env.objects_pos = [0];
            env.target_pos = [2];
            env.map_objects = zeros(env.num_locations,1);
            env.State = [env.arm_pos; env.arm_state; env.objects_pos; env.target_pos];
            [env, obs, ~, ~, ~] = testCase.StepFuncHandle(env, 2); % Acción place
            testCase.assertEqual(env.arm_state, 0, 'The arm should be empty after placing');
            testCase.assertEqual(env.objects_pos(1), 2, 'The object position should be updated after placing');
        end

        function testPlaceInvalid_ArmEmpty(testCase)
            env = createTestEnv();
            env.arm_pos = 2;
            env.arm_state = 0;
            env.objects_pos = [1];
            env.target_pos = [2];
            env.map_objects = zeros(env.num_locations,1);
            env.map_objects(1) = 1;
            env.State = [env.arm_pos; env.arm_state; env.objects_pos; env.target_pos];
            [env, obs, ~, ~, ~] = testCase.StepFuncHandle(env, 2); % Acción place
            testCase.assertEqual(env.arm_state, 0, 'The arm should remain empty');
        end

        function testPlaceInvalid_LocationOccupied(testCase)
            env = createTestEnv();
            env.arm_pos = 2;
            env.arm_state = 1;
            env.num_objects = 2;
            env.objects_pos = [0; 2];
            env.target_pos = [2; 1];
            env.map_objects = zeros(env.num_locations,1);
            env.map_objects(2) = 2;
            env.State = [env.arm_pos; env.arm_state; env.objects_pos; env.target_pos];
            [env, obs, ~, ~, ~] = testCase.StepFuncHandle(env, 2);
            testCase.assertEqual(env.arm_state, 1, 'The arm should still be holding the object');
            testCase.assertEqual(env.objects_pos(1), 0, 'The object position should not change');
        end

        function testMoveToLocation(testCase)
            env = createTestEnv();
            env.arm_pos = 1;
            env.arm_state = 0;
            env.objects_pos = [2];
            env.target_pos = [3];
            env.map_objects = zeros(env.num_locations,1);
            env.map_objects(2) = 1;
            env.State = [env.arm_pos; env.arm_state; env.objects_pos; env.target_pos];
            [env, obs, ~, ~, ~] = testCase.StepFuncHandle(env, 4); % Acción 4 → move to location 2
            testCase.assertEqual(env.arm_pos, 2, 'The arm should move to location 2');
            testCase.assertEqual(env.arm_state, 0, 'The arm should be empty');
            testCase.assertEqual(env.objects_pos(1), 2, 'The object position should not change');
            testCase.assertEqual(env.target_pos(1), 3, 'The target position should not change');
        end

        function testMoveToLocationWithObject(testCase)
            env = createTestEnv();
            env.arm_pos = 1;
            env.arm_state = 1;
            env.objects_pos = [0];
            env.target_pos = [3];
            env.map_objects = zeros(env.num_locations,1);
            env.State = [env.arm_pos; env.arm_state; env.objects_pos; env.target_pos];
            [env, obs, ~, ~, ~] = testCase.StepFuncHandle(env, 5); % Acción 5 → move to location 3
            testCase.assertEqual(env.arm_pos, 3, 'The arm should move to location 3');
            testCase.assertEqual(env.arm_state, 1, 'The arm should still be holding the object');
            testCase.assertEqual(env.objects_pos(1), 0, 'The object position should not change');
            testCase.assertEqual(env.target_pos(1), 3, 'The target position should not change');
        end
    end

end

function env = createTestEnv()
% Crea un entorno mínimo de prueba con valores razonables
env = struct();
env.num_locations = 3;
env.num_objects = 1;
env.arm_pos = [];
env.arm_state = [];
env.objects_pos = [];
env.target_pos = [];
env.State = [];
env.map_objects = [];
end
