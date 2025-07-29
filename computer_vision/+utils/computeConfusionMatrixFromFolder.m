function confusionMat = computeConfusionMatrixFromFolder(model, dataFolder, classNames, scoreThreshold, iouThreshold, iouFunc)
% model: detector (por ejemplo, yolov8ObjectDetector2)
% dataFolder: ruta a la carpeta que contiene 'images' y 'labels'
% classNames: cellstr con los nombres de las clases
% scoreThreshold, iouThreshold: umbrales
imageDir = fullfile(dataFolder, 'images');
labelDir = fullfile(dataFolder, 'labels');
imageFiles = dir(fullfile(imageDir, '*.jpg')); 

numClasses = numel(classNames);
confusionMat = zeros(numClasses + 1, numClasses + 1); % confusion matrix

for i = 1:length(imageFiles)
    imgName = imageFiles(i).name;
    imgPath = fullfile(imageDir, imgName);
    labelPath = fullfile(labelDir, replace(imgName, '.jpg', '.txt')); % Cambia a .png si es necesario
    I = imread(imgPath);
    if ~isfile(labelPath)
        bboxes_gt = [];
        labels_gt = {};
        disp("Label path not found");
    else
        [bboxes_gt, labels_gt] = utils.readYoloLabel(labelPath, size(I), classNames);
    end

    % Visualizar la imagen con las cajas y etiquetas ground truth
    I_gt = insertObjectAnnotation(I, 'rectangle', bboxes_gt, labels_gt, ...
        'LineWidth', 1, 'FontSize', 18, 'Color', 'green');
    %figure;
    %imshow(I_gt);
    %title(['Ground Truth: ', imgName], 'Interpreter', 'none');
    


    % Predicción
    [bboxes_pred, scores_pred, labels_pred] = detect(model, I);


    %utils.detectAndDisplayImage(model, imgName);

    %utils.detectAndDisplayImage(model, imgName)

    % Calcular matriz de confusión para esta imagen
    confMatImg = utils.computeConfusionMatrixObjectDetection(bboxes_pred, scores_pred, labels_pred, ...
        bboxes_gt, labels_gt, classNames, scoreThreshold, iouThreshold, iouFunc);

    confusionMat = confusionMat + confMatImg;
end


end

