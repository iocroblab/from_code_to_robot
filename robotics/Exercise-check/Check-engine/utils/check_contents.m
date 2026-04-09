function check_contents(contentcheck)
% CHECK_CONTENTS Function to check the contents of MATLAB code against specified criteria
%
% Input Arguments:
%     contentcheck - a structure array containing the criteria for checking code contents

    % ---------------------------------------------------------------------
    % 1) Convert active live script to a temporary .m file and read code
    % ---------------------------------------------------------------------
    tmpm = ['testStudentCode', '.m']; % Temporary filename for the student code
    activeFile = matlab.desktop.editor.getActiveFilename; % Get the currently active file in the MATLAB editor
    %activeFile ='C:\Users\Const\Desktop\Work\GitIoc\robotics\RS-Toolbox\Test\test_function.mlx';
    import matlab.internal.liveeditor.openAndConvert % Import function to convert live scripts
    openAndConvert(activeFile, tmpm); % Convert the active file to a standard .m file

    % Read and clean the code
    lines = readlines(tmpm, 'EmptyLineRule','skip'); % Read lines, skipping empty lines
    delete(tmpm); % Delete the temporary file immediately

    % Remove empty lines and comment lines, strip whitespace
    code = lines(strtrim(lines) ~= "" & ~startsWith(strtrim(lines), "%"));
    code = strip(code);

    % ---------------------------------------------------------------------
    % 2) Extract all functions present in the file and write temp .m files
    % ---------------------------------------------------------------------
    funcStruct = extractAllFunctions(code); % struct array with fields: name, block

    createdFiles = {};
    for k = 1:numel(funcStruct)
        fn = funcStruct(k).name;
        % Force plain char
        if ~ischar(fn)
            fn = char(fn);
        end
        if isempty(fn)
            warning('Encountered function with empty name. Skipping one block.');
            continue;
        end

        fname = [fn, '.m'];   % e.g. 'myfunc.m'
        createdFiles{end+1} = fname; %#ok<AGROW>

        fid = fopen(fname, 'w');
        if fid == -1
            warning('Could not create temporary file %s. Skipping this function.', fname);
            continue;
        end
        columnblock = reshape(funcStruct(k).block, 1, []); % Write block as a single row
        fprintf(fid, '%s\n', columnblock);
        fclose(fid);
    end

    % Failsafe: ensure that all created function files are deleted,
    % even if an error occurs later in this function.
    cleanupObj = onCleanup(@() deleteTempFiles(createdFiles)); %#ok<NASGU>

    % ---------------------------------------------------------------------
    % 3) Loop over contentcheck entries
    % ---------------------------------------------------------------------
    for i = 1:numel(contentcheck)
        content = contentcheck(i);
        failed  = false;

        if isa(content, "cell")
            content = content{1};
        end

        originalName = content.name; % 'main' or function name
        name         = originalName;

        % ---- Get the code block corresponding to this content ----
        if ~strcmp(originalName, "main")
            % Look up function in funcStruct
            idx = find(strcmp({funcStruct.name}, originalName), 1);
            if isempty(idx)
                disp(['[FAIL] Function "', originalName, '" not found.']);
                block = [];
                failed = true;
            else
                block = funcStruct(idx).block;
            end
        else
            % 'main' refers to the whole (script) code
            name  = 'Code'; % for messages only
            block = code;
        end

        if isempty(block)
            % Nothing to check for this entry
            continue;
        end

        % -----------------------------------------------------------------
        % 3a) Forbidden content checks
        % -----------------------------------------------------------------
        if isfield(content, "forbidden") && ~isempty(content.forbidden)
            forbidden = content.forbidden;
            for f = 1:size(forbidden, 1)
                if any(contains(block, forbidden(f)))
                    disp(['[FAIL] ', name, ' contains "', (forbidden{f}), '" which is not permitted for this exercise.']);
                    failed = true;
                end
            end
        end

        % -----------------------------------------------------------------
        % 3b) Input / Output checks (only for real functions, not "main")
        % -----------------------------------------------------------------
        if isfield(content, 'inputs') && ~failed && ~strcmp(originalName, 'main')
            outputs = content.outputs;
            inputs  = content.inputs;

            if ~isempty(inputs)
                % Tolerance
                tol = 1e-3;
                if isfield(content,'tolerance') && ~isempty(content.tolerance)
                    tol = content.tolerance;
                end

                % -------- Normalise inputs into a list of test cases -------
                % Each test case is a 1xN cell array "row" of arguments.
                if iscell(inputs)
                    % Case A: JSON like
                    % "inputs": [ [0,...,0], [-0.44,...], 8.0, 300, ... ]
                    % -> jsondecode: 1xN cell (one test)
                    if all(cellfun(@(c) ~iscell(c), inputs))
                        testRows = {inputs}; % single test case
                    else
                        % Case B: cell-of-cells: { {args test1}, {args test2}, ... }
                        testRows = inputs(:);
                    end
                else
                    % Case C: numeric matrix (legacy style)
                    testRows = cell(size(inputs,1), 1);
                    for j = 1:size(inputs,1)
                        testRows{j} = num2cell(inputs(j,:));
                    end
                end

                nTests = numel(testRows);

                % ---------------- Run all test cases -----------------------
                for j = 1:nTests
                    row       = testRows{j};      % 1xN cell of arguments
                    numinputs = numel(row);

                    % ---- Build a printable function call string ----
                    functioncall = strcat(originalName, '(');
                    for inp = 1:numinputs
                        val = row{inp};
                        if isnumeric(val)
                            if isscalar(val)
                                txt = num2str(val);
                            else
                                txt = mat2str(val);
                            end
                        elseif ischar(val) || (isstring(val) && isscalar(val))
                            txt = char(val);
                        else
                            txt = '<arg>';
                        end

                        if inp ~= numinputs
                            functioncall = strcat(functioncall, txt, ',');
                        else
                            functioncall = strcat(functioncall, txt);
                        end
                    end
                    functioncall = strcat(functioncall, ')');

                    % ---- Actual function evaluation using the temp .m file ---
                    args = row;
                    functionoutput = feval(originalName, args{:});

                    % ---- Compare with expected outputs ----
                    if isnumeric(functionoutput)
                        % numeric expected
                        expected = [];
                        if isnumeric(outputs)
                            if nTests == 1
                                expected = outputs;          % full numeric array
                            else
                                if size(outputs,1) == nTests
                                    expected = outputs(j,:); % row per test
                                else
                                    expected = outputs;      % fallback
                                end
                            end
                        end

                        if ~isempty(expected)
                            if all(abs(functionoutput - expected) <= tol, 'all')
                                disp(['[OK] Output for: ', functioncall, ' matched expectation within tolerance']);
                            elseif isfield(content,'hidden') && content.hidden
                                disp(['[FAIL] Output for: ', functioncall, ' does not match expected output']);
                            else
                                disp(['[FAIL] Output for: ', functioncall, ...
                                      ' is incorrect. Expected: ', mat2str(expected), ...
                                      ' but got: ', mat2str(functionoutput)]);
                            end
                        else
                            disp(['[FAIL] No numeric expected output specified properly for: ', functioncall]);
                        end

                    else
                        % non-numeric expected
                        if iscell(outputs)
                            if nTests == 1
                                expected = outputs{1};
                            else
                                expected = outputs{j};
                            end
                        else
                            expected = outputs;
                        end

                        if isequal(functionoutput, expected)
                            disp(['[OK] Output for: ', functioncall, ' matched expectation']);
                        elseif isfield(content,'hidden') && content.hidden
                            disp(['[FAIL] Output for: ', functioncall, ' does not match expected output']);
                        else
                            try
                                gotStr = strtrim(evalc('disp(functionoutput)'));
                                expStr = strtrim(evalc('disp(expected)'));
                            catch
                                gotStr = '<unprintable>';
                                expStr = '<unprintable>';
                            end
                            disp(['[FAIL] Output for: ', functioncall, ...
                                  ' is incorrect. Expected: ', expStr, ...
                                  ' but got: ', gotStr]);
                        end
                    end
                end
            end
        end
    end
end

% ========================================================================
% Helper: extract all function blocks from the code
% ========================================================================
function funcStruct = extractAllFunctions(code)
    % Returns struct array with fields:
    %   name  - function name (char)
    %   block - string array containing the function block (function .. end)

    funcStruct = struct('name', {}, 'block', {});
    n = numel(code);
    i = 1;

    while i <= n
        line = strtrim(code(i));
        if startsWith(line, 'function')
            funcStartIdx = i;
            endCount     = 0;
            idx          = i;

            % Count blocks until matching "end"
            while idx <= n
                l = strtrim(code(idx));
                if startsWith(l, 'function')
                    endCount = endCount + 1;
                elseif startsWith(l, 'if') || startsWith(l, 'for') || ...
                       startsWith(l, 'while') || startsWith(l, 'try') || ...
                       startsWith(l, 'switch')
                    endCount = endCount + 1;
                elseif strcmp(l, 'end')
                    endCount = endCount - 1;
                end

                if endCount == 0 && idx > funcStartIdx
                    break;
                end
                idx = idx + 1;
            end

            funcEndIdx = idx;
            block      = code(funcStartIdx:funcEndIdx);
            fname      = parseFunctionName(line);

            funcStruct(end+1) = struct('name', fname, 'block', block); %#ok<AGROW>

            i = funcEndIdx + 1;
        else
            i = i + 1;
        end
    end
end

% ========================================================================
% Helper: parse a function name from its header line
% ========================================================================
function name = parseFunctionName(header)
    header = strtrim(header);
    header = char(header); % ensure char for regexp

    % Handles:
    %   function y = foo(x)
    %   function [a,b] = bar(x)
    %   function foo(x)
    tokens = regexp(header, ...
        'function\s+(?:\[[^\]]*\]\s*=\s*|[^\s=]+\s*=\s*)?(?<name>[a-zA-Z]\w*)', ...
        'names');

    if ~isempty(tokens) && isfield(tokens, 'name') && ~isempty(tokens.name)
        name = char(tokens.name); % force char
    else
        error('Could not parse function name from header: %s', header);
    end
end

% ========================================================================
% Helper: delete all temporary files (used by onCleanup)
% ========================================================================
function deleteTempFiles(files)
    for k = 1:numel(files)
        if isempty(files{k})
            continue;
        end
        f = files{k};
        if ~ischar(f)
            f = char(f);
        end
        if exist(f, 'file')
            try
                delete(f);
            catch
                % ignore delete errors
            end
        end
    end
end
