function [bboxes, labels] = readYoloLabel(labelPath, imgSize, classNames)
    % Formato YOLO: class x_center y_center width height (normalizado)
    if ~isfile(labelPath)
        bboxes = [];
        labels = {};
        return;
    end
    fileInfo = dir(labelPath);
    if fileInfo.bytes == 0
        bboxes = [];
        labels = {};
        return;
    end
    data = dlmread(labelPath);
    if isempty(data)
        bboxes = [];
        labels = {};
        return;
    end
    if size(data,2) == 5
        classIdx = data(:,1) + 1;
        labels = classNames(classIdx);
        w = imgSize(2); h = imgSize(1);
        x_center = data(:,2);
        y_center = data(:,3);
        width = data(:,4);
        height = data(:,5);
        x1 = (x_center - width/2) * w;
        y1 = (y_center - height/2) * h;
        x2 = (x_center + width/2) * w;
        y2 = (y_center + height/2) * h;
        
        x_center = data(:,2) * w;
        y_center = data(:, 3) * h;
        width = data(:,4)* w;
        height = data(:,5) * h;

        bboxes = [x1 y1 x2 y2];
    else
        disp("Error in data size");
        bboxes = [];
        labels = {};
    end
end
