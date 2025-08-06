function meanAUC = precisionRecallCurve(predictions, classNames, calculateIoU, showPlot)
    % Parameters
    step_size = 0.05;
    steps = 1 / step_size + 1;
    numClasses = numel(classNames);

    % Initialization
    precision = zeros(steps, numClasses + 1);  % +1 for macro
    recall = zeros(steps, numClasses + 1);
    confidence = zeros(steps, 1);

    % Loop over confidence thresholds
    for i = 1:steps
        confidenceThreshold = (i - 1) * step_size;
        confidence(i) = confidenceThreshold;

        precision(i, :) = precisionFunc(predictions, classNames, confidenceThreshold, calculateIoU);
        recall(i, :) = recallFunc(predictions, classNames, confidenceThreshold, calculateIoU);
    end

    % Compute AUC per class (excluding macro column)
    auc = zeros(1, numClasses);
    for c = 1:numClasses
        [sortedRecall, idx] = sort(recall(:, c));
        sortedPrecision = precision(idx, c);
        auc(c) = trapz(sortedRecall, sortedPrecision);
    end
    meanAUC = mean(auc);

    % Plot if required
    if showPlot
        figure;
        hold on;
        colors = lines(numClasses);

        % Plot per-class PR curves
        for c = 1:numClasses
            plot(recall(:, c), precision(:, c), '-o', ...
                'Color', colors(c,:), 'LineWidth', 1.5, ...
                'DisplayName', sprintf('Class: %s', classNames{c}));
        end

        % Plot mean curve
        precisionMean = mean(precision(:, 1:numClasses), 2, 'omitnan');
        recallMean = mean(recall(:, 1:numClasses), 2, 'omitnan');
        [recallMeanSorted, idx] = sort(recallMean);
        precisionMeanSorted = precisionMean(idx);
        plot(recallMeanSorted, precisionMeanSorted, '--k', ...
            'LineWidth', 2.5, 'DisplayName', 'Mean');

        grid on;
        xlabel('Recall');
        ylabel('Precision');
        title('Precision-Recall Curve');
        legend('Location', 'northeastoutside');
        hold off;
    end
end


%precisionRecallCurve(predictions, classNames, @calculateIoU, true)  
