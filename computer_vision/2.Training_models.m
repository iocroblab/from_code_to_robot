% Load pretrained model

addpath('installation-module');
det = yolov8ObjectDetector2('yolov8s');

%% 
I = imread(fullfile('data','indoorTest.jpg'));

% Perform detection using pretrained model.
%[bboxes, scores, labels] = detect(det, I);
[bboxes, scores, labels] = detect(det, I, 'SelectStrongest', true, 'NMSThreshold', 0.01, 'Threshold', 0.002);
% Visualize detection results.
annotations = string(labels) + ': ' + string(scores);
Iout = insertObjectAnnotation(I, 'rectangle', bboxes, annotations);
figure, imshow(Iout);



%% Training
% Train a YOLOv8 object detector with a custom image size and number of epochs
%yolov8Det = trainYOLOv8ObjectDetector('data.yaml','yolov8n.pt', ImageSize=[64 64 3], MaxEpochs=1);


configFile = 'data.yaml';
baseModel = 'yolov8n.pt';
options.MaxEpochs = 1;
options.ImageSize = [256 256 3];

% Llamada con parámetros adicionales para YOLO
yolov8Det = trainYOLOv8ObjectDetector( ...
    configFile, ...
    baseModel, ...
    options, ...
    'lr0', 0.01, ...              % Tasa de aprendizaje inicial
    'weight_decay', 0.0005, ...   % Decaimiento de pesos
    'patience', 10 ...            % Early stopping patience
);

%% Testing

utils.detectAndDisplayImage(yolov8Det, 'pear2.jpg');
%% 

%utils.detectAndDisplayImage(yolov8Det, 'banana.jpg');

%utils.detectAndDisplayImage(yolov8Det, 'lemon.jpg');

utils.detectAndDisplayImage(yolov8Det, 'apple9.jpg');
%%
utils.detectAndDisplayImage(yolov8Det, 'orange2.jpg');


%% 

