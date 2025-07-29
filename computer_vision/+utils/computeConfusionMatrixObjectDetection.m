function confusionMat = computeConfusionMatrixObjectDetection(bboxes_pred, scores, labels_pred, ...
    bboxes_gt, labels_gt, classNames, scoreThreshold, iouThreshold, iouFunc)
    % bboxes_pred: Nx4, scores_pred: Nx1, labels_pred: Nx1 (o cellstr)
    % bboxes_gt: Mx4, labels_gt: Mx1 (o cellstr)
    % classNames: cellstr con los nombres de las clases
    % confusionMat: numClasses x numClasses (TP, FP, FN, TN por clase)


    numClasses = numel(classNames) + 1; % +1 para el background

    confusionMat = zeros(numClasses, numClasses); 

    bg_class = numClasses;

    % bboxes_pred: Nx4
    % bboxes_gt: Mx4

    if size(bboxes_gt, 1) == 0 && size(bboxes_pred, 1) ~= 0
        for i = 1:size(bboxes_pred, 1)
            if scores(i) < scoreThreshold
                continue
            end
            pred_class = labels_pred(i);
            pred_class_idx = getClassIndex(pred_class, classNames);
            confusionMat(pred_class_idx, bg_class) = confusionMat(pred_class_idx, bg_class) + 1;
        end
        return

    elseif size(bboxes_gt, 1) ~= 0 && size(bboxes_pred, 1) == 0
        for i = 1:size(bboxes_gt, 1)
            gt_class = labels_gt(i);
            gt_class_idx = getClassIndex(gt_class, classNames);
            confusionMat(bg_class, gt_class_idx) = confusionMat(bg_class, gt_class_idx) + 1;
        end
        return
    elseif size(bboxes_gt, 1) == 0 && size(bboxes_pred, 1) == 0
        return
    end


    overlaps = []; % [IoU, idx_pred, idx_gt]

    for i = 1:size(bboxes_gt, 1)
        for j = 1:size(bboxes_pred,1)
            [x1p, y1p, x2p, y2p] = boxCornerToCorners(bboxes_pred(j,:));
            bbox_pred_corners = [x1p, y1p, x2p, y2p];
            overlaps = [overlaps; iouFunc(bbox_pred_corners, bboxes_gt(i,:)), j, i];
        end
    end

    matched_gt = false(size(bboxes_gt,1),1);
    matched_pred = false(size(bboxes_pred,1),1);

    overlaps = sortrows(overlaps, -1);
    for i = 1:size(overlaps,1)
        idx_pred = overlaps(i,2);
        idx_gt = overlaps(i,3);
        if matched_pred(idx_pred) || matched_gt(idx_gt)
            continue
        end
        matched_pred(idx_pred) = true;

        % if score is below threshold, it is ignored
        if scores(idx_pred) < scoreThreshold
            continue
        end

        pred_class = labels_pred(idx_pred);
        pred_class_idx = getClassIndex(pred_class, classNames);

        % if IoU is below threshold, it is classified as background
        if overlaps(i,1) < iouThreshold
            confusionMat(pred_class_idx, bg_class) = confusionMat(pred_class_idx, bg_class) + 1;
            continue
        end


        matched_gt(idx_gt) = true;

        gt_class = labels_gt(idx_gt);
        gt_class_idx = getClassIndex(gt_class, classNames);

        confusionMat(pred_class_idx, gt_class_idx) = confusionMat(pred_class_idx, gt_class_idx) + 1;

    end

    for i = 1:length(matched_gt)
        if ~matched_gt(i)
            gt_class = labels_gt(i);
            gt_class_idx = getClassIndex(gt_class, classNames);
            confusionMat(bg_class, gt_class_idx) = confusionMat(bg_class, gt_class_idx) + 1;
        end
    end

 end




function iou = calculateIoU(b1, b2)

    x1 = max(b1(1), b2(1));
    y1 = max(b1(2), b2(2));
    x2 = min(b1(3), b2(3));
    y2 = min(b1(4), b2(4));
    inter = max(0, x2-x1) * max(0, y2-y1);
    area1 = (b1(3)-b1(1))*(b1(4)-b1(2));
    area2 = (b2(3)-b2(1))*(b2(4)-b2(2));
    union = area1 + area2 - inter;
    if union>0
        iou = inter/union;
    else
        iou = 0;
    end
   
end

function [x1, y1, x2, y2] = boxCornerToCorners(bbox)
    % Convierte ([x1, y1, width, height]) a ([x1, y1, x2, y2])
    x1 = bbox(1);
    y1 = bbox(2);
    width = bbox(3);
    height = bbox(4);
    x2 = x1 + width;
    y2 = y1 + height;
    
end 

function idx = getClassIndex(className, classNames)
    % className: string o char, nombre de la clase a buscar
    % classNames: cell array de strings/chars con los nombres de las clases
    % idx: índice de la clase en classNames (1-based). Si no se encuentra, devuelve []
    if ~isstring(className)

        className = char(className);
    end

    idx = find(strcmp(classNames, className), 1);
    if isempty(idx)
        warning('Clase "%s" no encontrada en classNames.', className);
    end
end 
