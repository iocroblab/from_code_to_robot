function check_variables(vars)
    fprintf('\nChecking variables:\n \n');
    for i = 1:numel(vars)
        var  = vars(i);
        if isa(var, "cell")
            var = var{1};
        end
        name = var.name;

        %–– determine header text (description or default)
        if isfield(var, 'description') && ~isempty(var.description)
            header = var.description;
        else
            header = sprintf('Checking Variable %s', name);
        end
        fprintf('%s\n', header);

        % detect whether it's a simple var-name or a more complex expression
        if isempty(regexp(name, '[\.\{\}\(\)]', 'once'))
            % no dots or braces → a simple variable
            if evalin('base', sprintf('exist(''%s'', ''var'')', name)) ~= 1
                output = get_output(var, 'fail', sprintf('%s not found in workspace', name));
                fprintf('[FAIL] %s\n\n', output);
                continue;
            end
        end
        % try to retrieve the value
        try
            val = evalin('base', name);
        catch
            output = get_output(var, 'fail', sprintf('%s not found in workspace', name));
            fprintf('[FAIL] %s\n\n', output);
            continue;
        end

        %–– type check
        if isfield(var, 'type')
            if ~isa(val, var.type)
                output = get_output(var, 'fail', sprintf('%s should be %s, but is %s', name, var.type, class(val)));
                fprintf('[FAIL] %s\n\n', output);
                continue;
            else
                output = get_output(var, 'ok', sprintf('%s is of type %s', name, var.type));
                fprintf('[OK] %s\n', output);
            end
        end

        %–– value or tolerance check
        if isfield(var, 'expected')
            expected = var.expected;
            is_numeric = isnumeric(val) || isa(val, 'sym');
            if is_numeric
                tol = 1e-4;
                if isfield(var, 'tolerance') && ~isempty(var.tolerance)
                    tol = var.tolerance;
                end
                try
                    err = val(:) - expected(:);
                    match = all(abs(err) <= tol) || all(abs(err) < 1e-12);
                    if match
                        output = get_output(var, 'ok', sprintf('%s correct', name));
                        fprintf('[OK] %s\n', output);
                    else
                        output = get_output(var, 'fail', sprintf('%s mismatch', name));
                        fprintf('[FAIL] %s\n', output);
                    end
                catch e
                    fprintf('[ERROR] Comparison failed for %s: %s\n', name, e.message);
                end
            else
                % Non-numeric comparison
                if isequal(val, expected)
                    output = get_output(var, 'ok', sprintf('%s matches expected value', name));
                    fprintf('[OK] %s\n', output);
                else
                    output = get_output(var, 'fail', sprintf('%s mismatch', name));
                    fprintf('[FAIL] %s\n', output);
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
                        fprintf('[FAIL] %s.%s: expected %s, got %s\n', name, prop, mat2str(expected), mat2str(actual));
                    end
                catch e
                    fprintf('[ERROR] %s.%s inaccessible: %s\n', name, prop, e.message);
                end
            end
        end

        fprintf('\n');
    end
end

function msg = get_output(var, status, default_msg)
    switch status
        case 'ok'
            if isfield(var, 'output_ok') && ~isempty(var.output_ok)
                msg = var.output_ok;
            else
                msg = default_msg;
            end
        case 'fail'
            if isfield(var, 'output_fail') && ~isempty(var.output_fail)
                msg = var.output_fail;
            else
                msg = default_msg;
            end
        otherwise
            msg = default_msg;
    end
end
