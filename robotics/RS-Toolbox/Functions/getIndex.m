function [output] = getIndex(expression, row, col)
    %GETINDEX Retrieve a specific element from a variable in the base workspace
    %
    % Input Arguments:
    %     expression - name/code of the variable in the base workspace
    %     row - row index of the desired element
    %     col - column index of the desired element
    %
    % Output Arguments:
    %     output - the value at the specified row and column of the variable

    arguments (Input)
        expression 
        row 
        col
    end
    arguments (Output)
        output
    end
    
    % Evaluate the variable from the base workspace
    Temp  = evalin("base", expression);
    % Retrieve the specified element from the evaluated variable
    output = Temp(row, col);
end