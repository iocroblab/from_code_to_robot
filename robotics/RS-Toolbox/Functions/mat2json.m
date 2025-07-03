function jsonString = mat2json(matrix, symbolicvar, replacements)
%MAT2JSON Converts a matrix to a JSON formatted string.
%   This function takes a matrix as input and returns a string
%   representation of the matrix in JSON format. If the matrix is
%   symbolic, it also takes symbolic variables and their replacements.

arguments (Input)
    matrix
    symbolicvar = [] % Optional input for symbolic variables
    replacements {mustBeNumericOrLogical} = [] % Optional input for replacements
end

% Check if the matrix is symbolic
if ~isempty(symbolicvar) && ~isempty(replacements)
    matrix = double(round(subs(matrix, symbolicvar, replacements), 4));
end

% Always round the matrix to 4 decimals
matrix = round(matrix, 4);

% Convert the matrix to a cell array of strings
cellArray = arrayfun(@(x) num2str(x, '%.4f'), matrix, 'UniformOutput', false);

% Create a JSON formatted string
jsonString = '[';
for i = 1:size(matrix, 1)
    jsonString = [jsonString, '[', strjoin(cellArray(i, :), ','), ']'];
    if i < size(matrix, 1)
        jsonString = [jsonString, ','];
    end
end
jsonString = [jsonString, ']'];
end