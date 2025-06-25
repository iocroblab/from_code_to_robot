function S = harmonize_struct_fields(cellArray)
    % Collect all unique field names
    allFields = {};
    for i = 1:numel(cellArray)
        allFields = union(allFields, fieldnames(cellArray{i}));
    end

    % Pad missing fields with empty
    for i = 1:numel(cellArray)
        missing = setdiff(allFields, fieldnames(cellArray{i}));
        for j = 1:numel(missing)
            cellArray{i}.(missing{j}) = [];
        end
    end

    % Now all have same fields, convert to struct array
    S = vertcat(cellArray{:});
end
