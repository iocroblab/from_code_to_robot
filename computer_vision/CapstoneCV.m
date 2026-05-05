function [centroid, BB_size, best_match_fruit, Iout] = Capstone_Vision_demo(cam, yolo_model, minConf, video_scale, showImage, outputImage)

    % Optional input default
    if nargin < 5
        showImage = false;
        outputImage = false;
    elseif nargin < 6
        outputImage = false; 
    end
    best_match_fruit =""; 

    % Get frame
    I = snapshot(cam);
    Iout = []; 

    % Downsample
    I_small = imresize(I, video_scale);

    % Image/window size
    imageHeight = size(I_small, 1);
    imageWidth  = size(I_small, 2);

    % Run detector
    [bboxes, scores, labels] = detect(yolo_model, I_small);

    wantedFruits = ["banana", "apple", "orange"];
    
    %keep only confident fruit idx
    idx = scores >= minConf & ismember(string(labels), wantedFruits);

    % Default outputs if nothing is found
    centroid = [];
    BB_size = [];
    bbox = [];
    score = [];

    if any(idx)
        % Filter detections
        filteredBboxes = bboxes(idx, :);
        filteredScores = scores(idx);
        filterdLabels = labels(idx); 

        % Pick highest-confidence detection
        [score, bestIdx] = max(filteredScores);

        bbox = filteredBboxes(bestIdx, :);   % pixel bbox: [x y width height]
        
        best_match_fruit = filterdLabels(bestIdx);

        % Pixel centroid
        centroid_px = [bbox(1) + bbox(3)/2, ...
                       bbox(2) + bbox(4)/2];

        % Pixel bounding box size
        BB_size_px = bbox(3:4);              % [width height]

        % Normalized centroid
        centroid = [centroid_px(1) / imageWidth, ...
                    centroid_px(2) / imageHeight];

        % Normalized BB size relative to window/image size
        BB_size = [BB_size_px(1) / imageWidth, ...
                   BB_size_px(2) / imageHeight];
    end
    % Optional visualization
    if showImage||outputImage
        Iout = I_small;

        if ~isempty(bbox)
            annotation = string(best_match_fruit) + ": " + string(round(score, 2));

            Iout = insertObjectAnnotation(Iout, ...
                "rectangle", ...
                bbox, ...
                annotation);

            % For drawing, use pixel coordinates, not normalized coordinates
            centroid_px = [bbox(1) + bbox(3)/2, ...
                           bbox(2) + bbox(4)/2];

            Iout = insertMarker(Iout, ...
                centroid_px, ...
                "x", ...
                "Size", 10);

            Iout = insertText(Iout, ...
                centroid_px + [8 8], ...
                "c = [" + string(round(centroid(1), 2)) + ", " + ...
                         string(round(centroid(2), 2)) + "]", ...
                "FontSize", 12, ...
                "BoxOpacity", 0.6);
        end
        if showImage
            imshow(Iout);
            title("Detected " + string(best_match_fruit));
            drawnow;
        end
    end

end