function plotMetric = plotMetric(name, predictions, classNames, metricFunc, calculateIoU)  
    disp("Computing plot...")
    step_size = 0.05;
    steps = 1/step_size + 1;   
    numClasses = numel(classNames);

    metric = zeros(steps, numClasses +1);

    for i = 1:steps
        confidenceThreshold = (i - 1) * step_size;        
        metricTemp  = metricFunc(predictions, classNames, confidenceThreshold, calculateIoU);
        metricTemp(isnan(metricTemp)) = 0;
        metric(i, :) = metricTemp;
        confidence(i) = confidenceThreshold;
    end
    figure;
    hold on;
    disp(size(confidence))
    colors = lines(numClasses);
    for c = 1:numClasses
        plot(confidence, metric(:, c), '-o', 'Color', colors(c,:), 'LineWidth', 1.5, ...
             'DisplayName', sprintf('Class: %s', classNames{c}));
    end
    % Last Column, avg
    plot(confidence, metric(:, end), '--k', 'LineWidth', 2, 'DisplayName', 'Mean');
    hold off;
    
    grid on;
    xlabel('Confidence Threshold');
    ylabel(name);
    title(sprintf('%s vs Confidence Threshold', name));
    legend('Location', 'best');
end
