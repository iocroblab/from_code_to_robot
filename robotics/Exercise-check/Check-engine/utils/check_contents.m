function check_contents(contentcheck)
% CHECK_CONTENTS Function to check the contents of MATLAB code against specified criteria
%
% Input Arguments:
%     contentcheck - a structure array containing the criteria for checking code contents

tmpm = ['testStudentCode', '.m']; % Temporary filename for the student code
activeFile= matlab.desktop.editor.getActiveFilename; % Get the currently active file in the MATLAB editor
%activeFile ='C:\Users\Const\Desktop\Work\GitIoc\robotics\RS-Toolbox\Test\test_function.mlx';
import matlab.internal.liveeditor.openAndConvert % Import function to convert live scripts
openAndConvert(activeFile, tmpm); % Convert the active file to a standard .m file

% 2. Read and clean the code
lines = readlines(tmpm, 'EmptyLineRule','skip'); % Read lines from the temporary file, skipping empty lines
delete(tmpm); % Delete the temporary file
code = lines(strtrim(lines) ~= "" & ~startsWith(strtrim(lines), "%")); % Remove empty lines and comments
code = strip(code); % Strip whitespace from the code lines

for i=1:numel(contentcheck) % Loop through each content check criteria
    content  = contentcheck(i); % Get the current content check criteria
    failed=false; % Initialize failure flag
    if isa(content, "cell") % Check if content is a cell array
        content = content{1}; % Extract the first element if it is a cell
    end
    name=content.name; % Get the name of the content to check
    if ~strcmp(name, "main") % If the name is not "main"
        block=extractFunctionBlock(code, name); % Extract the function block from the code
    else
        name='Code'; % Set name to 'Code' for the main block
        block = code; % Use the entire code as the block
    end
    if ~isempty(block) % If the block is not empty
        if isfield(content,"forbidden")&&~isempty(content.forbidden) % Check for forbidden content
            forbidden=content.forbidden; % Get the forbidden content
            for f=1:size(forbidden,1) % Loop through each forbidden item
                if any(contains(block, forbidden(f))) % Check if the forbidden item is in the block
                    disp(['[FAIL] ', name ,' contains "',(forbidden{f}),'" which is not permitted for this exercise.']); % Display failure message
                    failed=true;  % Set failure flag to true
                end
            end
        end
        if isfield(content,'inputs')&&~failed % If there are inputs and no failure
            outputs = content.outputs; % Get expected outputs
            inputs=content.inputs; % Get inputs
            if ~isempty(inputs) % If inputs are not empty
                tempfilename=[name, '.m']; % Create a temporary filename for the function
                fid=fopen(tempfilename,'w'); % Open the temporary file for writing
                columnblock= reshape(block,1,[]); % Reshape the block for writing
                fprintf(fid,'%s\n', columnblock); % Write the block to the file
                fclose(fid); % Close the file
                tol = 1e-3; % Default tolerance for output comparison
                if isfield(content,'tolerance')&&~isempty(content.tolerance) % Check for custom tolerance
                    tol = content.tolerance; % Update tolerance if specified
                end
                for j=1:size(inputs,1) % Loop through each input set
                    numinputs=numel(inputs(j,:)); % Get the number of inputs
                    functioncall=strcat(name,'('); % Initialize the function call string
                    for inp=1:numinputs % Loop through each input
                        if(isnumeric(inputs(j,inp))) % Check if the input is numeric
                            if inp~=numinputs
                                functioncall = strcat(functioncall, num2str(inputs(j,inp)),','); % Append numeric input to function call
                            else
                                functioncall = strcat(functioncall, num2str(inputs(j,inp))); % Append last numeric input without comma
                            end
                        else
                            if inp~=numinputs
                                functioncall = strcat(functioncall, inputs(j,inp),','); % Append non-numeric input to function call
                            else
                                functioncall = strcat(functioncall, inputs(j,inp)); % Append last non-numeric input without comma
                            end
                        end
                    end
                    functioncall = strcat(functioncall, ')');
                    %disp(functioncall); % Uncomment to display the function call
                    args = num2cell(inputs(j, :));    % Convert inputs to cell array for function call
                    functionoutput = feval(name, args{:}); % Call the function with the current inputs

                    if isnumeric(functionoutput)
                        if abs(functionoutput-outputs(j,:))<=tol % Check if output is within tolerance
                            disp(['[OK] Output for: ',functioncall,' matched expectation within tolerance']) % Display success message
                        elseif isfield(content,'hidden')&&content.hidden % Check if the content is hidden
                            disp(['[FAIL] Output for: ',functioncall,'does not match expected output']); % Display failure message for hidden content
                        else
                            disp(['[FAIL] Output for: ', functioncall, ' is incorrect. Expected:', num2str(outputs(j)),' but got: ', num2str(functionoutput)]); % Display failure message with expected and actual output
                        end
                    else
                        if isequal(functionoutput, outputs{j})
                            disp(['[OK] Output for: ',functioncall,' matched expectation']) % Display success message
                        elseif isfield(content,'hidden')&&content.hidden % Check if the content is hidden
                            disp(['[FAIL] Output for: ',functioncall,'does not match expected output']); % Display failure message for hidden content
                        else
                            disp(['[FAIL] Output for: ', functioncall, ' is incorrect. Expected:', outputs{j},' but got: ', functionoutput]); % Display failure message with expected and actual output
                        end
                    end
                end
                delete(tempfilename); % Delete the temporary file
            end
        end

        
    end
end
end

function functionBlock = extractFunctionBlock(code,name)
% EXTRACTFUNCTIONBLOCK Extracts the function block from the code based on the function name
%
% Input Arguments:
%     code - the code lines to search through
%     name - the name of the function to extract
%
% Output Arguments:
%     functionBlock - the extracted function block

flag = false; % Initialize flag for loop control
while ~flag
    funcStartIdx = find(startsWith(code, 'function'), 1); % Find the start index of the function
    if contains(code(funcStartIdx), name) % Check if the function name matches
        flag = true; % Set flag to true if found
    else
        code(funcStartIdx)=[]; % Remove the line if it does not match
    end
    if isempty(funcStartIdx) % If no function start index is found
        flag = true; % Set flag to true to exit loop
    end
end
if ~isempty(funcStartIdx) % If a function start index was found
    endCount = 0; % Initialize end count
    funcEndIdx = funcStartIdx; % Set end index to start index
    while funcEndIdx <= numel(code) % Loop until the end of the code
        line = strtrim(code(funcEndIdx)); % Get the current line
        if startsWith(line, 'function') % Check for nested functions
            endCount = endCount + 1; % Increment for function
        elseif startsWith(line, 'if') || startsWith(line, 'for') || ...
                startsWith(line, 'while') || startsWith(line, 'try') || ...
                startsWith(line, 'switch') % Check for control structures
            endCount = endCount + 1; % Increment for control structures
        elseif strcmp(line, 'end') % Check for end statements
            endCount = endCount - 1; % Decrement for end
        end
        % Break if we reach the matching end for the current function
        if endCount == 0
            break; % Exit loop if matching end is found
        end
        funcEndIdx = funcEndIdx + 1; % Move to the next line
    end
    % Extract the function block
    functionBlock = code(funcStartIdx:funcEndIdx); % Include the end statement
    %disp(strjoin(functionBlock, newline)); % Uncomment to display the function block
else
    functionBlock =[]; % Return empty if no function block is found
    disp(['[FAIL] Function "', name, '" not found.']); % Display failure message
end
end