function detection = detectAndDisplayImage(detector, imageName, filter)
    % detectAndDisplayImage: Detects objects in an image using a YOLOv8 detector and displays them with colored annotations per label.
  
    if nargin < 3
        detection = utils.detectObjects(detector, imageName);
    else
        detection = utils.detectObjects(detector, imageName, filter);
    end
    figure;
    imshow(detection);
    title(['Detections in: ', imageName], 'Interpreter', 'none');
end
