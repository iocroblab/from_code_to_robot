function [bboxes,scores,labelIds] = predict(image, model)

numClasses = numel(model.ClassNames);


% Apply Preprocessing on the input image.
origSize = size(image);
Ibgr = image(:,:,[3,2,1]);
img = helper.preprocess(Ibgr, model.InputSize);
newSize = size(img);
img = img(:,:,[3,2,1]);

% Convert to dlarray.
dlInput = dlarray(img, 'SSCB');

% Perform prediction on the input image.
outFeatureMaps = cell(3,1);
[outFeatureMaps{:}] = predict(model.Network, dlInput);

% Apply postprocessing on the output feature maps.
[bboxes,scores,labelIds] = helper.postprocess(outFeatureMaps, ...
    origSize, newSize, numClasses);
end
