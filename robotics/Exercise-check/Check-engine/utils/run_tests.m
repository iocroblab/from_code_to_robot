function run_tests(tests)
    % If we got a cell array of structs, convert it to a struct array
    if iscell(tests)
        tests = vertcat(tests{:});
    end

    if ~isstruct(tests)
        error('run_tests: expected a struct array or cell array of structs.');
    end

    fprintf('\n Running %d functional test(s):\n', numel(tests));
    for i = 1:numel(tests)
        t = tests(i);
        fprintf('\nTest %d: %s\n', i, t.description);
        try
            % per-test setup
            if isfield(t, 'setup') && ~isempty(t.setup)
                evalin('base', t.setup);
            end

            % run the code under test
            evalin('base', t.code);

            % extract the result variable
            tokens  = regexp(t.code, '(\w+)\s*=', 'tokens', 'once');
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
