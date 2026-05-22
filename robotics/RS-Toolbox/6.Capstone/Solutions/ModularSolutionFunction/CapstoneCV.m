function [centroid, BB_size, best_match_fruit, Iout] = CapstoneSV( ...
    cam, yolo_model, minConf, video_scale, showImage, outputImage, axHandle)
% CAPSTONE_VISION_DEMO Detects selected fruits in a webcam image using YOLO.
%
%   [centroid, BB_size, best_match_fruit, Iout] = Capstone_Vision_demo( ...
%       cam, yolo_model, minConf, video_scale, showImage, outputImage, axHandle)
%
%   This function captures one frame from a webcam, downsamples it, runs a
%   YOLO object detector, and searches for selected fruit classes:
%   "banana", "apple", and "orange".
%
%   The function returns the highest-confidence fruit detection above the
%   specified confidence threshold.
%
%   Inputs:
%       cam          - Webcam object created with webcam()
%       yolo_model   - Trained YOLO detector object
%       minConf      - Minimum confidence score for valid detections
%       video_scale  - Image scaling factor, for example 0.5
%       showImage    - If true, display detection result in the given axes
%       outputImage  - If true, return the annotated image as Iout
%       axHandle     - Optional axes handle where the image should be shown.
%                      Required if showImage is true.
%
%   Outputs:
%       centroid         - Normalized centroid [x y] of best detection.
%                          Empty if no valid fruit is detected.
%       BB_size          - Normalized bounding-box size [width height].
%                          Empty if no valid fruit is detected.
%       best_match_fruit - Label of the best detected fruit.
%                          Empty string if no valid fruit is detected.
%       Iout             - Annotated output image if showImage or outputImage
%                          is true. Otherwise empty.
%
%   Example:
%       fig = figure('Name','Capstone Vision Demo','NumberTitle','off');
%       ax = axes(fig);
%
%       [centroid, BB_size, fruit, Iout] = Capstone_Vision_demo( ...
%           cam, yolo_model, 0.5, 0.5, true, false, ax);

    % Optional input defaults
    if nargin < 5
        showImage = false;
    end

    if nargin < 6
        outputImage = false;
    end

    if nargin < 7
        axHandle = [];
    end

    if showImage && (isempty(axHandle) || ~isvalid(axHandle))
        error("If showImage is true, you must pass a valid axes handle as the 7th input.");
    end

    best_match_fruit = "";
    Iout = [];

    % Get frame
    I = snapshot(cam);

    % Downsample
    I_small = imresize(I, video_scale);

    % Image/window size
    imageHeight = size(I_small, 1);
    imageWidth  = size(I_small, 2);

    % Run detector
    [bboxes, scores, labels] = detect(yolo_model, I_small);

    wantedFruits = ["banana", "apple", "orange"];

    % Keep only confident fruit detections
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
        filteredLabels = labels(idx);

        % Pick highest-confidence detection
        [score, bestIdx] = max(filteredScores);

        bbox = filteredBboxes(bestIdx, :);   % pixel bbox: [x y width height]

        best_match_fruit = string(filteredLabels(bestIdx));

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

    % Optional visualization or output image generation
    if showImage || outputImage
        Iout = I_small;

        if ~isempty(bbox)
            annotation = best_match_fruit + ": " + string(round(score, 2));

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
            imshow(Iout, 'Parent', axHandle);

            if best_match_fruit ~= ""
                title(axHandle, "Detected " + best_match_fruit);
            else
                title(axHandle, "No fruit detected");
            end

            drawnow limitrate;
        end
    end

end