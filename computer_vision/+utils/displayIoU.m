function visualizeIoU(b1, b2, calculateIoU)
    % Visualiza dos bounding boxes y su intersección.
    % Inputs:
    %   b1 - Bounding box 1 [x1 y1 x2 y2]
    %   b2 - Bounding box 2 [x1 y1 x2 y2]

    % Calcular IoU
    iou = calculateIoU(b1, b2);

    % Preparar figura
    figure; hold on; axis equal;
    title(['IoU = ' num2str(iou, '%.4f')]);
    xlabel('X'); ylabel('Y');

    % Dibujar ambos bounding boxes
    rectangle('Position', [b1(1), b1(2), b1(3)-b1(1), b1(4)-b1(2)], ...
              'EdgeColor', 'b', 'LineWidth', 2, 'LineStyle', '-');
    rectangle('Position', [b2(1), b2(2), b2(3)-b2(1), b2(4)-b2(2)], ...
              'EdgeColor', 'r', 'LineWidth', 2, 'LineStyle', '--');

    % Dibujar intersección si existe
    x1 = max(b1(1), b2(1));
    y1 = max(b1(2), b2(2));
    x2 = min(b1(3), b2(3));
    y2 = min(b1(4), b2(4));

    if (x2 > x1) && (y2 > y1)
        rectangle('Position', [x1, y1, x2-x1, y2-y1], ...
                  'EdgeColor', 'g', 'LineWidth', 2, 'LineStyle', ':', ...
                  'FaceColor', [0 1 0 0.3]); % Transparente
    end

    hold off
end