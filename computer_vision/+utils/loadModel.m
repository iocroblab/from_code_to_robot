function yolov8Det = loadModel(modelPath, configFile, baseModel, options)
%LOADMODEL Loads a YOLOv8 model and prepares the detector.
%   yolov8Det = loadModel(modelPath, configFile, baseModel, options)
%   - modelPath: path to the folder containing the ONNX weights
%   - configFile: path to the config file for class names
%   - baseModel: name of the base .pt model (string, default: 'yolov8s.pt')
%   - options: struct with field ImageSize (e.g., options.ImageSize = [256 256 3], default: [256 256 3])
%   - baseModel: name of the base .pt model (string, default: 'yolov8s.pt')
%   - options: struct with field ImageSize (e.g., options.ImageSize = [256 256 3], default: [256 256 3])

    arguments
        modelPath (1,:) char
        configFile (1,:) char
        baseModel (1,:) char = 'yolov8s.pt'
        options struct = struct('ImageSize', [256 256 3])
    end

    % Import the YOLOv8 ONNX model
    net = importYOLOv8Model(fullfile(modelPath, "best.onnx"));

    % Create the Python YOLOv8 trainer object
    pyTrainer = py.trainYOLOv8Wrapper.yolov8TrainerClass( ...
        py.str(baseModel), py.int(options.ImageSize(1)));

    % Get class names from the config file
    dictValues = pyTrainer.getClassNames(configFile);
    classDict = dictValues{"names"};
    matlabDict = dictionary(classDict);
    classNames = values(matlabDict);

    % Create the YOLOv8 object detector
    yolov8Det = yolov8ObjectDetector(net, classNames);
end
