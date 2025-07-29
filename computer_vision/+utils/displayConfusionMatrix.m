function displayConfusionMatrix(confMat, classNames)
    % Display confusion matrix as a chart
    classNamesCat = categorical(classNames, classNames, 'Ordinal', true);

    confChart = confusionchart(confMat, classNamesCat);
    title('Confusion Matrix');
    xlabel('True Class');
    ylabel('Predicted Class');
end