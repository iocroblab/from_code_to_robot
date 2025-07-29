function yolov8Det = trainYOLOv8ObjectDetector(configFile, baseModel, varargin)
%trainYOLOv8ObjectDetector Train a YOLO v8 deep learning object detector.
%
% trainedDetector = trainYOLOv8ObjectDetector(configFile, baseModel) trains a
% YOLOv8 object detector using the specified configuration file. The
% configFile is the path to the configuration file in YAML format. The
% options structure can be used to specify the maximum number of epochs and
% the mini-batch size for training. A YOLO v8 object detector can be
% trained to detect multiple object classes.
%
% % Inputs
% --------
%   configFile      Includes the locations of relative path, train, val,
%                   test data specified as string array along with the
%                   class names information along with indices.
%                   Following is the default yaml format and its contents:
%                       path: ''
%                       train: images/train
%                       val: images/val
%                       test: null
%                       names:
%                           0: exit
%                           1: fireextinguisher
%                           2: chair
%                           3: clock
%                           4: trashbin
%                           5: screen
%                           6: printer
%                   Note: null can be used in absence of either val, test data.
%
% % Additional input arguments
% ----------------------------
% [...] = trainYOLOv8ObjectDetector(..., Name = Value) specifies additional
% name-value pair arguments described below:
%
%    'MaxEpochs'        The maximum number of epochs that will be used for
%                       training.
%                  
%                       Default: 10
%
%   'ImageSize'         Specify the image size used for training the
%                       detector. The input size must be H-by-W or
%                       H-by-W-by-C.
%
%                       Default: [680 680 3]
%
% % Example: Train YOLO v8 network
% --------------------------------
% % Create a yolov8Trainer object
%  yolov8Obj = yolov8ObjectDetector("yolov8m.pt")
%
% % Train YOLO v8 detector
% yolov8Obj = trainYOLOv8ObjectDetector (yolov8Obj, 'data.yaml');
%
% See also trainYOLOv4ObjectDetector, trainYOLOv3ObjectDetector
%
% Copyright 2024 The MathWorks, Inc.

% Parse Name-Value pairs
p = inputParser;
p.addRequired('configFile');
p.addRequired('baseModel', @(x) endsWith(x, '.pt'));
p.addParameter('MaxEpochs', 10, @(x) isnumeric(x) && isscalar(x) && x > 0);
p.addParameter('ImageSize', [640 640 3], @(x) isnumeric(x) && (numel(x) == 2 || numel(x) == 3));
p.addParameter('resume', false, @(x) islogical(x) && isscalar(x));
p.KeepUnmatched = true;
p.parse(configFile, baseModel, varargin{:});
options = p.Results;

if ~canUseGPU()
    error("Training of YOLO v8 object detector requires GPU.")
end

terminate(pyenv)

if (ispc)
    pyenv(Version="win64/python/python.exe", ExecutionMode = "OutOfProcess")
else
    pyenv(Version="glnxa64/python/bin/python3", ExecutionMode = "OutOfProcess")
end

if isunix
    py.sys.setdlopenflags(int32(bitor(int64(py.os.RTLD_LAZY),int64(py.os.RTLD_DEEPBIND))));
end

pythonObject = py.trainYOLOv8Wrapper.yolov8TrainerClass(py.str(baseModel), py.int(options.ImageSize(1,1)));

% Extract extra YOLO arguments (not handled by MATLAB)
knownFields = {'configFile','baseModel','MaxEpochs','ImageSize','resume'};
extraArgs = struct();
for i = 1:2:length(varargin)
    argName = varargin{i};
    if ischar(argName) || isstring(argName)
        % Chequeo case-insensitive
        if ~any(strcmpi(argName, knownFields))
            argValue = varargin{i+1};
            % Convierte booleanos MATLAB a booleanos Python
            if islogical(argValue)
                if argValue
                    argValue = py.True;
                else
                    argValue = py.False;
                end
            end
            extraArgs.(char(argName)) = argValue;
        end
    end
end
pyExtraArgs = {};
fields = fieldnames(extraArgs);
for i = 1:numel(fields)
    pyExtraArgs{end+1} = fields{i};
    pyExtraArgs{end+1} = extraArgs.(fields{i});
end

if options.resume
    results = pythonObject.resumeYOLOv8();
else
    disp("extra:")
    disp(pyExtraArgs)
    disp(".........")
    results = pythonObject.trainYOLOv8(configFile, py.int(options.MaxEpochs), varargin);
end

% Obtain path to results dir that has .pt file
getSaveDir = string(results.save_dir.parts);

% Extract location of export directory
onnxExportDir = [getSaveDir,'weights','best.pt'];
onnxExportPath = fullfile(onnxExportDir{:});

% Export best trained model to onnx format
pythonObject.exportModel(onnxExportPath);

% Import the exported model in MATLAB
modelPath = fullfile(onnxExportDir{1:end-1});
net = importYOLOv8Model(fullfile(modelPath,"best.onnx"));

dictValues = pythonObject.getClassNames(configFile);
classDict = dictValues{"names"};
matlabDict = dictionary(classDict);
classNames = values(matlabDict);

yolov8Det = yolov8ObjectDetector(net, classNames);

end