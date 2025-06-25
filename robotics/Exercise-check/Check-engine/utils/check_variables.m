function check_variables(vars)
    fprintf('\nChecking variable structure:\n');
    for i = 1:numel(vars)
        var = vars(i);
        name = var.name;

        % first, does it exist?
        exists = evalin('base', sprintf('exist(''%s'',''var'')', name));
        if exists ~= 1
            fprintf('[FAIL] %s not found in workspace\n', name);
            continue;
        end

        % now grab it
        try
            val = evalin('base', name);
        catch e
            fprintf('[ERROR] Could not evaluate %s: %s\n', name, e.message);
            continue;
        end

        % type check
        if isfield(var, 'type')
            if ~isa(val, var.type)
                fprintf('[FAIL] %s should be of type "%s", but is "%s"\n', ...
                        name, var.type, class(val));
                continue;
            else
                fprintf('[OK]   %s is of type %s\n', name, var.type);
            end
        end

        % property checks
        if isfield(var, 'properties')
            props = fieldnames(var.properties);
            for p = 1:numel(props)
                prop     = props{p};
                expected = var.properties.(prop);
                actual   = val.(prop);
                if isequal(actual, expected)
                    fprintf('[OK]   %s.%s = %s\n', name, prop, mat2str(actual));
                else
                    fprintf('[FAIL] %s.%s: expected %s, got %s\n', ...
                            name, prop, mat2str(expected), mat2str(actual));
                end
            end
        end
    end
end
