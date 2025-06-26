function check_exercise(exercise_id)
    % Main checking function (JSON-based)
    json_file = fullfile('exercises', sprintf('exercise-%s.json', exercise_id));
    % if ~isfile(json_file)
    %     error('JSON file %s not found.', json_file);
    % end

    data = jsondecode( fileread(json_file) );
    ex = data.exercise;
    fprintf('Checking exercise %s: %s\n', ex.id, ex.description);

    % %--- run exercise-level setup if provided (e.g. define robot) ---
    % if isfield(ex, 'setup')
    %     fprintf(' Running exercise setup...\n');
    %     eval(ex.setup);
    % end

    %--- static variable checks ---
    if isfield(ex, 'variables')
        check_variables(ex.variables);
    end

    %--- functional tests ---
    if isfield(ex, 'tests')&&~isempty(ex.tests)
        if isfield(ex, 'setup')&&~isempty(ex.setup)
            run_tests(ex.tests, ex.setup);
        else
            run_tests(ex.tests);
        end
    end
end
