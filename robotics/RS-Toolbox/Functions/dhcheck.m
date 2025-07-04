function region = dhcheck(T)
    % DHCHECK Function to extract a specific region from the input matrix T
    %
    % Input Arguments:
    %     T - Input matrix from which a region will be extracted
    %
    % Output Arguments:
    %     region - Extracted submatrix from T

    arguments (Input)
        T
    end
    arguments (Output)
        region
    end
    % Extract the submatrix consisting of the first three rows and columns 3 to 4
    region = T(1:3,3:4);
end