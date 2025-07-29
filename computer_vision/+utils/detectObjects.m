function detection = detectObjects(detector, imageName, filter)
    % detectAndDisplayImage: Detects objects in an image using a YOLOv8 detector and displays them with colored annotations per label.
    %
    % Parameters:
    %   detector: YOLOv8 detector object (e.g., yolov8Det)
    %   imageName: image file name (e.g., 'pear.jpg')
    %   filter: (opcional) objeto Filter para postprocesar las detecciones

    % Path to the image folder
    imagePath = fullfile('data/fruits-test/train/images/', imageName);

    % Read the image
    I = imread(imagePath);

    if nargin < 3 || isempty(filter)
        % Detect objects normalmente
        [bbox, score, label] = detect(detector, I);
    else
        % Usar filtro para postprocesar
        results = filter.apply(I);
        % results es un struct array (puede ser vacío)
        if isempty(results)
            bbox = zeros(0,4);
            score = [];
            label = [];
        else
            bbox = vertcat(results.boxes);
            score = vertcat(results.conf);
            % Convertir índice de clase a nombre
            label = detector.ClassNames(vertcat(results.cls));
        end
    end

    annotation = string(label) + ': ' + string(score);

    % Define a color map for each label
    labelList = unique(label);
    colorMap = containers.Map;
    defaultColors = lines(numel(labelList)); % Use MATLAB's 'lines' colormap for distinct colors

    for i = 1:numel(labelList)
        colorMap(char(labelList(i))) = uint8(255 * defaultColors(i, :));
    end

    % Assign a color to each detection based on its label
    boxColors = zeros(numel(label), 3, 'uint8');
    for i = 1:numel(label)
        boxColors(i, :) = colorMap(char(label(i)));
    end
    
    % Insert annotations with custom colors
    if ~isempty(bbox)
        annotatedImage = insertObjectAnnotation(I, "rectangle", bbox, annotation, ...
            'LineWidth', 4, 'FontSize', 24, 'Color', boxColors);
    else
        annotatedImage = I;
    end

    detection = annotatedImage;
end
