function run_tests(tests, globalSetup)
    % If tests are a cell array of structs, ensure consistent fields before concatenating
    if iscell(tests)
        tests = harmonize_struct_fields(tests);
    end

    if ~isstruct(tests)
        error('run_tests: expected a struct array or cell array of structs.');
    end

    % Global setup for all tests
    if nargin >= 2 && ~isempty(globalSetup)
        try
            eval(globalSetup);
            %fprintf(' Executed global setup.\n');
        catch e
            fprintf('[ERROR] Global setup failed: %s\n', e.message);
            return;
        end
    end

    fprintf('Checking Solutions: \n');
    for i = 1:numel(tests)
        t = tests(i);
        fprintf('\nTest %d: %s\n', i, t.description);
        try
            % Per-test setup (optional)
            if  isfield(t, 'setup') 
                if~isempty(t.setup)
                    eval( t.setup);
                end
            end

            % Run the code under test
            eval(t.code);

            % Determine the result variable
            if isfield(t, 'resultVar') && ~isempty(t.resultVar)
                if ~isempty(t.resultVar)
                    varName = t.resultVar;
                end
            else
                tokens = regexp(t.code, '(\w+)\s*=', 'tokens', 'once');
                varName = strtrim(tokens{1});
            end

            % Evaluate result
            result = eval( varName);

            % Use tolerance comparison if provided
            if isfield(t, 'tolerance')&& ~isempty(t.tolerance)
                tol = t.tolerance;

                try
                    err = result(:) - t.expected(:);
                    if ~isnumeric(err)
                        fprintf('[ERROR] norm() returned non-scalar value.\n');
                        continue;
                    end
                catch normErr
                    fprintf('[ERROR] Could not compute norm(): %s\n', normErr.message);
                    continue;
                end

                % Safe scalar logical test
                %if err(:) <= tol || abs(err(:)) < 1e-12
                errorcheck = (all(err(:) <= tol) || all(abs(err(:)) < 1e-12));
                if errorcheck
                    if size(err,1)<=6
                        fprintf('[OK]   Result within tolerance %.2g (err = %.2g)\n', tol, err);
                    else 
                        fprintf('[OK]   Result within tolerance');
                    end
                else
                    fprintf('[FAIL] Result off by %.2g\nExpected:\n%s\nGot:\n%s\n', ...
                        err, mat2str(t.expected, 4), mat2str(result, 4));
                end
            else
                % Exact match
                if isequal(result, t.expected)
                    fprintf('[OK]   Result matches expected value\n');
                else
                    fprintf('[FAIL] Expected:\n%s\nGot:\n%s\n', ...
                        mat2str(t.expected, 4), mat2str(result, 4));
                end
            end

        catch e
            % fprintf('[ERROR] %s\n', e.message);
        end
    end
end 
