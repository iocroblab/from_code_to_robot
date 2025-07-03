function check_variables(vars)
    fprintf('\nChecking variables:\n \n');
    for i = 1:numel(vars)
        var  = vars(i);
        if isa(var, "cell")
            var = var{1};
        end
        name = var.name;
        fprintf('Checking Variable %s \n', name);

        % detect whether it's a simple var-name or a more complex expression
        if isempty(regexp(name, '[\.\{\}\(\)]', 'once'))
            % no dots or braces → a simple variable
            if evalin('base', sprintf('exist(''%s'', ''var'')', name)) ~= 1
                fprintf('[FAIL] %s not found in workspace\n\n', name);
                continue;
            end
        end
        % now try to pull the value (this will also work for structs, cells, etc)
        try
            val = evalin('base', name);
        catch
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

        % Determine if this variable is marked hidden
        hidden = isfield(var, 'hidden') && var.hidden;

        %–– value or tolerance check
        if isfield(var, 'expected')
            expected = var.expected;

            if isnumeric(val) || isa(val, 'sym')
                % Use tolerance (from JSON or default)
                tol = 1e-4;
                if isfield(var, 'tolerance') && ~isempty(var.tolerance)
                    tol = var.tolerance;
                end

                try
                    err = val(:) - expected(:);
                    errorcheck = (all(abs(err) <= tol) || all(abs(err) < 1e-12));
                    if errorcheck
                        fprintf('[OK]   %s correct \n', name);
                    else
                        if hidden
                            fprintf('[FAIL] %s mismatch\n', name);
                        else
                            fprintf('[FAIL] %s mismatch\nExpected: %s\nGot: %s\n', ...
                                    name, mat2str(expected, 4), mat2str(val, 4));
                        end
                    end
                catch e
                    fprintf('[ERROR] Comparison failed for %s: %s\n', name, e.message);
                end

            else
                % Not numeric/symbolic → isequal
                if isequal(val, expected)
                    fprintf('[OK]   %s matches expected value\n', name);
                else
                    if hidden
                        fprintf('[FAIL] %s mismatch\n', name);
                    else
                        fprintf('[FAIL] %s mismatch\nExpected: %s\nGot: %s\n', ...
                                name, mat2str(expected, 4), mat2str(val, 4));
                    end
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
