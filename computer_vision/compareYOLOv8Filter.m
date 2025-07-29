%% compareYOLOv8Filter.m
% COMPARAR FILTRO YOLOv8
% Compare raw vs filtered YOLOv8 detections in MATLAB.

% Ajusta estas rutas a tu caso
modelPath = fullfile(pwd, 'runs', 'detect', 'train3', 'weights');

configFile = fullfile(pwd, "data.yaml")
baseModel = "yolov8s.pt";
testImageFile = fullfile('data/fruits-test/train/images/', "apple2.jpg");

disp("Rutas cargadas!!");

% 1) Initialize Python wrapper and load class names
pythonObject = py.trainYOLOv8Wrapper.yolov8TrainerClass(py.str(baseModel), [640 640 3]); 
dictValues = pythonObject.getClassNames(configFile);

classDict = dictValues{"names"};
matlabDict = dictionary(classDict);

classNames = ["apple", "banana", "bowl"];
disp("Wrapper inicializado!!");

% 2) Import ONNX and create yolov8ObjectDetector
net = importYOLOv8Model(fullfile(modelPath,"best.onnx"));
detector = yolov8ObjectDetector(net, classNames);

disp("Modelo cargado!!");

% 3) Read test image
I = imread(testImageFile);
disp("Imagen leída");

% 4) Define inference function for Filter
inferenceFcn = @(img) yoloStruct(detector, img);
disp("Función de inferencia definida");

numClasses = numel(classNames);
% Usamos hsv para generar un color único (valores en [0,1])
cmap = hsv(numClasses);       
% Convertimos a valores enteros [0,255]
colors = uint8(255 * cmap);  

rawResults  = inferenceFcn(I);
rawBboxes   = vertcat(rawResults.boxes);
rawScores   = vertcat(rawResults.conf);
rawClasses  = vertcat(rawResults.cls);
rawLabels   = arrayfun(@(c,s) sprintf('%s: %.2f', classNames(c), s), ...
                       rawClasses, rawScores, 'UniformOutput', false);

% Empezamos con la imagen original
Iraw = I;
for i = 1:size(rawBboxes,1)
    clsIdx = rawClasses(i);
    box    = rawBboxes(i,:);
    label  = rawLabels{i};
    color  = colors(clsIdx, :);  % [R G B]
    % Dibujar caja
    Iraw = insertShape(Iraw, ...
        "Rectangle", box, ...
        "Color",     color, ...
        "LineWidth", 10);
    % Dibujar texto
    Iraw = insertText(Iraw, ...
        box(1:2), label, ...
        "FontSize",    72, ...
        "Font",        "Arial Bold", ...
        "TextColor",   "white", ...
        "BoxColor",    color, ...
        "BoxOpacity",  0.7, ...
        "AnchorPoint", "LeftBottom");
end
%figure, imshow(Iraw), title("Raw Detections / Detecciones sin filtrar");

filt        = Filter(inferenceFcn, 0.5, 0.8, [1,2]);
filtResults = filt.apply(I);
fBboxes     = vertcat(filtResults.boxes);
fScores     = vertcat(filtResults.conf);
fClasses    = vertcat(filtResults.cls);
fLabels     = arrayfun(@(c,s) sprintf('%s: %.2f', classNames(c), s), ...
                       fClasses, fScores, 'UniformOutput', false);

Ifilt = I;
for i = 1:size(fBboxes,1)
    clsIdx = fClasses(i);
    box    = fBboxes(i,:);
    label  = fLabels{i};
    color  = colors(clsIdx, :);
    Ifilt = insertShape(Ifilt, ...
        "Rectangle", box, ...
        "Color",     color, ...
        "LineWidth", 10);
    Ifilt = insertText(Ifilt, ...
        box(1:2), label, ...
        "FontSize",    72, ...
        "Font",        "Arial Bold", ...
        "TextColor",   "white", ...
        "BoxColor",    color, ...
        "BoxOpacity",  0.7, ...
        "AnchorPoint", "LeftBottom");
end
%figure, imshow(Ifilt), title("Filtered Detections / Detecciones filtradas");

figure('Name','Comparación detecciones','NumberTitle','off');
tiledlayout(1,2,'Padding','tight','TileSpacing','compact');

% 7.1) Raw Detections
nexttile;
imshow(Iraw);
title("Raw Detections / Detecciones sin filtrar");

% 7.2) Filtered Detections
nexttile;
imshow(Ifilt);
title("Filtered Detections / Detecciones filtradas");

% Auxiliar: convert detect() output to struct array for Filter
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
