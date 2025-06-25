function run_tests(tests)
    fprintf('\n Running %d functional test(s):\n', numel(tests));
    for i = 1:numel(tests)
        t = tests(i);
        fprintf('\nTest %d: %s\n', i, t.description);
        try
            % per-test setup (e.g. compute config)
            if isfield(t, 'setup')
                evalin('base', t.setup);
            end

            % run the code under test
            evalin('base', t.code);

            % extract result variable name
            tokens = regexp(t.code, '(\w+)\s*=', 'tokens', 'once');
            varName = strtrim(tokens{1});
            result  = evalin('base', varName);

            % compare
            if isfield(t, 'tolerance')
                err = norm(result - t.expected);
                if err <= t.tolerance
                    fprintf('[OK]   Result within tolerance %.2g (err = %.2g)\n', ...
                            t.tolerance, err);
                else
                    fprintf('[FAIL] Result off by %.2g: expected %s, got %s\n', ...
                            err, mat2str(t.expected), mat2str(result));
                end
            else
                if isequal(result, t.expected)
                    fprintf('[OK]   Result matches expected value\n');
                else
                    fprintf('[FAIL] Expected %s but got %s\n', ...
                            mat2str(t.expected), mat2str(result));
                end
            end

        catch e
            fprintf('[ERROR] %s\n', e.message);
        end
    end
end
