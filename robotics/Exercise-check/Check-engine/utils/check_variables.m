function check_variables(vars)
    fprintf('\nChecking variables:\n \n');
    for i = 1:numel(vars)
        var  = vars(i);
        name = var.name;
        fprintf('Checking Variable %s \n', name);

        %–– does it exist?
        if evalin('base', sprintf('exist(''%s'',''var'')', name)) ~= 1
            fprintf('[FAIL] %s not found in workspace\n\n', name);
            continue;
        end

        %–– grab it
        try
            val = evalin('base', name);
        catch e
            fprintf('[ERROR] Could not evaluate %s: %s\n\n', name, e.message);
            continue;
        end

        %–– type check
        if isfield(var, 'type')
            if ~isa(val, var.type)
                fprintf('[FAIL] %s should be %s, but is %s\n\n', ...
                        name, var.type, class(val));
                continue;
            else
                fprintf('[OK]   %s is of type %s\n', name, var.type);
            end
        end

        %–– value or tolerance check
        if isfield(var, 'expected')
            expected = var.expected;

            if isnumeric(val) || isa(val, 'sym')
                % Use tolerance (from JSON or default)
                tol = 1e-12;
                if isfield(var, 'tolerance') && ~isempty(var.tolerance)
                    tol = var.tolerance;
                end

                try
                    err = val(:) - expected(:);
                    errorcheck = (all(err <= tol) || all(abs(err) < 1e-12));
                    if errorcheck
                        fprintf('[OK]   %s correct \n', name);
                    else
                        fprintf('[FAIL] %s mismatch\nExpected: %s\nGot: %s\n', ...
                                name, mat2str(expected, 4), mat2str(val, 4));
                    end
                catch e
                    fprintf('[ERROR] Tolerance comparison failed for %s: %s\n', name, e.message);
                end
            else
                % Not numeric/symbolic → isequal
                if isequal(val, expected)
                    fprintf('[OK]   %s matches expected value\n');
                else
                    fprintf('[FAIL] %s mismatch\nExpected: %s\nGot: %s\n', ...
                            name, mat2str(expected, 4), mat2str(val, 4));
                end
            end
        end

        %–– property checks (optional extra)
        if isfield(var, 'properties')
            props = fieldnames(var.properties);
            for p = 1:numel(props)
                prop     = props{p};
                expected = var.properties.(prop);
                try
                    actual = val.(prop);
                    if isequal(actual, expected)
                        fprintf('[OK]   %s.%s = %s\n', name, prop, mat2str(actual));
                    else
                        fprintf('[FAIL] %s.%s: expected %s, got %s\n', ...
                                name, prop, mat2str(expected), mat2str(actual));
                    end
                catch e
                    fprintf('[ERROR] %s.%s inaccessible: %s\n', name, prop, e.message);
                end
            end
        end

        fprintf('\n');
    end
end
