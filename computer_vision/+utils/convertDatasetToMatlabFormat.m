% Define paths
folder = 'datasets/fruits_3_4998/val';
imageFolder = fullfile(folder, 'images');
labelFolder = fullfile(folder, 'labels');
imageFiles = dir(fullfile(imageFolder, '*.jpg'));

% Define class names (según tus clases en YOLO)
classNames = ["apple", "orange", "pear"];  % Añade más si hay otras clases

% Inicializa variables
imageFilenames = {};
bboxData = {};

for i = 1:length(imageFiles)
    imgName = imageFiles(i).name;
    imgPath = fullfile(imageFolder, imgName);
    txtPath = fullfile(labelFolder, replace(imgName, '.jpg', '.txt'));

    img = imread(imgPath);
    [imgH, imgW, ~] = size(img);

    if isfile(txtPath)
        yoloLabels = readmatrix(txtPath);  % cada fila: class_id cx cy w h (normalizado)
        if size(yoloLabels,2) == 5 && ~isempty(yoloLabels)
            classIds = yoloLabels(:,1);
            cx = yoloLabels(:,2) * imgW;
            cy = yoloLabels(:,3) * imgH;
            w = yoloLabels(:,4) * imgW;
            h = yoloLabels(:,5) * imgH;
            x = cx - w/2;
            y = cy - h/2;

            boxes = [x y w h];
            labels = classNames(classIds+1);
            labels = labels(:); % Asegura columna
            if size(boxes,1) ~= numel(labels)
                boxes = reshape(boxes, [], 4);
            end
            imageFilenames{end+1,1} = imgPath;
            bboxData{end+1,1} = table(boxes, labels, 'VariableNames', {'Boxes','Labels'});
        end
    end
    % Si no hay anotaciones, no se añade nada
end

% Combina la tabla final
allBBoxes = cell(height(bboxData),1);
allLabels = cell(height(bboxData),1);

for i = 1:height(bboxData)
    allBBoxes{i} = bboxData{i}.Boxes;
    allLabels{i} = bboxData{i}.Labels;
end

% Crear tabla final con una columna por clase (como espera boxLabelDatastore)
validationData = table(imageFilenames, 'VariableNames', {'imageFilename'});

for c = 1:numel(classNames)
    bboxes = cellfun(@(b,l) b(l==classNames(c),:), allBBoxes, allLabels, 'UniformOutput', false);
    validationData.(classNames(c)) = bboxes;
end

% Guardar en .mat
save('fruitsValidationData.mat', 'validationData');
