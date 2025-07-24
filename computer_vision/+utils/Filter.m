classdef Filter
    % Filter  Class to post-process detection results:
    %         - remove same-class overlapping boxes
    %         - remove low-confidence detections
    %
    % Properties:
    %   model            Function handle returning a struct array:
    %                      .boxes  (Nx4) [x1 y1 x2 y2]
    %                      .conf   (Nx1) confidence scores
    %                      .cls    (Nx1) class labels
    %   filters          Cell array of functions to apply to the detections

    properties
        model           % function_handle
        filters         % cell array of function handles
        iouThreshold    % double
        scoreThreshold  % double
        activeFilters   % vector of ints
    end
    
    methods
        function obj = Filter(model,filters)

            modelFunction = @(img) yoloStruct(model, img);

            % Constructor
            if nargin>0
                obj.model          = modelFunction;
                obj.filters        = filters;
            end
        end

        function results = apply(obj, image)
            % APPLY  Runs the model and applies configured filters.
            results = obj.model(image);
            for f = 1:numel(obj.filters)
                filterFunc = obj.filters{f};
                results = filterFunc(results);
            end
        end
    end     
end




function S = yoloStruct(detObj, img)
    [bboxes, scores, labels] = detect(detObj, img);
    N = size(bboxes,1);
    S = struct("boxes",cell(N,1), "conf",cell(N,1), "cls",cell(N,1));
    for i = 1:N
        S(i).boxes = bboxes(i,:);
        S(i).conf  = scores(i);
        % Convert label string to numeric index
        S(i).cls   = find(strcmp(detObj.ClassNames, string(labels(i))), 1);
    end
end 

