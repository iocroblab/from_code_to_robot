








function precisionTable = computePrecisionFromConfusionMatrix(confusionMat, classNames)
% confusionMat: (numClasses+1) x (numClasses+1), last row/column = background
% classNames: cell array with the class names (excluding background)

numClasses = numel(classNames); % Exclude background
precision = zeros(numClasses, 1);

TP_total = 0;
FP_total = 0;

for i = 1:numClasses
    TP = confusionMat(i, i);
    FP = sum(confusionMat(i, :)) - TP;
    TP_total = TP_total + TP;
    FP_total = FP_total + FP;
    if (TP + FP) > 0
        precision(i) = TP / (TP + FP);
    else
        error("Precision is NaN");
    end
end

% Calculate overall precision
if (TP_total + FP_total) > 0
    overallPrecision = TP_total / (TP_total + FP_total);
else
    overallPrecision = NaN;
end

% Add overall row to the table
allClassNames = [classNames(:); {'Overall'}];
allPrecisions = [precision; overallPrecision];

precisionTable = table(allClassNames, allPrecisions, 'VariableNames', {'ClassName', 'Precision'});
end 