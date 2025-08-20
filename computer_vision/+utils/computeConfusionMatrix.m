function confusionMat = computeConfusionMatrix(predictions, classNames, scoreThreshold, iouFunc, iouThreshold)
if nargin < 8 || isempty(iouThreshold)
    iouThreshold = 0.75;
end
numClasses = numel(classNames);
confusionMat = zeros(numClasses + 1, numClasses + 1); % confusion matrix

for i = 1:length(predictions)

    confMatImg = utils.computeImageConfusionMatrix(predictions(i).bboxes_pred, predictions(i).scores_pred, predictions(i).labels_pred, ...
        predictions(i).bboxes_gt, predictions(i).labels_gt, classNames, scoreThreshold, iouFunc, iouThreshold);

    confusionMat = confusionMat + confMatImg;
end


end

