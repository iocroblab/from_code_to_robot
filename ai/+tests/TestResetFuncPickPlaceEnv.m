classdef TestResetFuncPickPlaceEnv < matlab.unittest.TestCase
    properties
        ResetFuncHandle
    end

    methods (Test)

        % ResetFunc tests
        function testArmPosInRange(testCase)
            % Crea un entorno de prueba
            env = createTestEnv();
            [env, obs] = testCase.ResetFuncHandle(env);
            testCase.assertGreaterThanOrEqual(env.arm_pos, 1);
            testCase.assertLessThanOrEqual(env.arm_pos, env.num_locations);
        end

        function testArmStateStartsEmpty(testCase)
            env = createTestEnv();
            [env, obs] = testCase.ResetFuncHandle(env);
            testCase.assertEqual(env.arm_state, 0);
        end

        function testObjectsPosUniqueAndNotAtArm(testCase)
            env = createTestEnv();
            [env, obs] = testCase.ResetFuncHandle(env);
            % Todos los objetos en posiciones distintas
            testCase.assertEqual(length(unique(env.objects_pos)), env.num_objects);
            % Ningún objeto en la posición del brazo
            testCase.assertEmpty(intersect(env.objects_pos, env.arm_pos));
        end

        function testTargetPosUniqueAndNotAtObjectStart(testCase)
            env = createTestEnv();
            [env, obs] = testCase.ResetFuncHandle(env);
            % Todos los targets distintos
            testCase.assertEqual(length(unique(env.target_pos)), env.num_objects);
            % Ningún target igual a la posición inicial del objeto correspondiente
            for i = 1:env.num_objects
                testCase.assertNotEqual(env.target_pos(i), env.objects_pos(i));
            end
        end

        function testObservationMatchesState(testCase)
            env = createTestEnv();
            [env, obs] = testCase.ResetFuncHandle(env);
            expectedObs = [env.arm_pos; env.arm_state; env.objects_pos; env.target_pos];
            testCase.assertEqual(obs, expectedObs);
            testCase.assertEqual(env.State, expectedObs);
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
