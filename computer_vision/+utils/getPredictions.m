function predictions = getPredictions(model, dataFolder, classNames)
    imageDir = fullfile(dataFolder, 'images');
    labelDir = fullfile(dataFolder, 'labels');
    imageFiles = dir(fullfile(imageDir, '*.jpg')); 

    n = length(imageFiles);
    % Initialize as empty array instead of preallocating with struct()
    predictions = [];

    for i = 1:n
        imgName = imageFiles(i).name;
        imgPath = fullfile(imageDir, imgName);
        labelPath = fullfile(labelDir, replace(imgName, '.jpg', '.txt'));
        I = imread(imgPath);
        if ~isfile(labelPath)
            bboxes_gt = [];
            labels_gt = {};
            disp("Label path not found");
        else
            [bboxes_gt, labels_gt] = utils.readYoloLabel(labelPath, size(I), classNames);
        end

        [bboxes_pred, scores_pred, labels_pred] = detect(model, I);


        predictions(i).bboxes_pred = bboxes_pred;
        predictions(i).scores_pred = scores_pred;
        predictions(i).labels_pred = labels_pred;
        predictions(i).bboxes_gt = bboxes_gt;
        predictions(i).labels_gt = labels_gt;
    end
    

    for i = 1:n
        if ~isempty(predictions(i).scores_pred)
            maxScores(i) = max(predictions(i).scores_pred);
        else
            maxScores(i) = 0; % Si no hay predicciones, asignar score 0
        end
    end
    
    [~, sortIdx] = sort(maxScores, 'descend');
    predictions = predictions(sortIdx);
end

