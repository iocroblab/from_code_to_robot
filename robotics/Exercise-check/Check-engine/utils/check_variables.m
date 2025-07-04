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

        %–– detect hidden flag
        hidden = isfield(var, 'hidden') && var.hidden;

        %–– detect whether simple var-name
        if isempty(regexp(name, '[\.\{\}\(\)]', 'once'))
            if evalin('base', sprintf('exist(''%s'', ''var'')', name)) ~= 1
                if hidden || (isfield(var, 'output_fail') && ~isempty(var.output_fail))
                    output = get_output(var, 'fail', sprintf('%s not found in workspace', name));
                    fprintf('[FAIL] %s\n\n', output);
                else
                    fprintf('[FAIL] mismatch in expected output for variable %s;\nExpected: <undefined>\nGot: <undefined>\n\n', name);
                end
                continue;
            end
        end

        %–– try to retrieve the value
        try
            val = evalin('base', name);
        catch
            if hidden || (isfield(var, 'output_fail') && ~isempty(var.output_fail))
                output = get_output(var, 'fail', sprintf('%s not found in workspace', name));
                fprintf('[FAIL] %s\n\n', output);
            else
                fprintf('[FAIL] mismatch in expected output for variable %s;\nExpected: <undefined>\nGot: <undefined>\n\n', name);
            end
            continue;
        end

        %–– type check
        if isfield(var, 'type')
            if ~isa(val, var.type)
                if hidden || (isfield(var, 'output_fail') && ~isempty(var.output_fail))
                    output = get_output(var, 'fail', sprintf('%s should be %s, but is %s', name, var.type, class(val)));
                    fprintf('[FAIL] %s\n\n', output);
                else
                    fprintf('[FAIL] mismatch in expected output for variable %s;\nExpected type: %s\nGot type: %s\n\n', name, var.type, class(val));
                end
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
                        % mismatch case
                        if hidden || (isfield(var, 'output_fail') && ~isempty(var.output_fail))
                            output = get_output(var, 'fail', sprintf('%s mismatch', name));
                            fprintf('[FAIL] %s\n', output);
                        else
                            fprintf('[FAIL] mismatch in expected output for variable %s;\nExpected: %s\nGot: %s\n', ...
                                    name, mat2str(expected, 4), mat2str(val, 4));
                        end
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
                    % mismatch case
                    if hidden || (isfield(var, 'output_fail') && ~isempty(var.output_fail))
                        output = get_output(var, 'fail', sprintf('%s mismatch', name));
                        fprintf('[FAIL] %s\n', output);
                    else
                        fprintf('[FAIL] mismatch in expected output for variable %s;\nExpected: %s\nGot: %s\n', ...
                                name, mat2str(expected, 4), mat2str(val, 4));
                    end
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
