function displayFilteredDetections(detector, imageName, filter)
% display_filtered_detections: Muestra una figura comparando detecciones sin filtrar y filtradas.
%   detector: objeto detector YOLOv8
%   imageName: nombre del archivo de imagen (ej: 'apple2.jpg')
%   filter: objeto Filter para postprocesar las detecciones

% Obtener imagen con detecciones sin filtrar
rawImg = utils.detectObjects(detector, imageName);

% Obtener imagen con detecciones filtradas
filtImg = utils.detectObjects(detector, imageName, filter);

% Mostrar ambas imágenes lado a lado
figure('Name','Comparación detecciones','NumberTitle','off');
tiledlayout(1,2,'Padding','tight','TileSpacing','compact');

% Detecciones sin filtrar
nexttile;
imshow(rawImg);
title('Raw Detections / Detecciones sin filtrar');

% Detecciones filtradas
nexttile;
imshow(filtImg);
title('Filtered Detections / Detecciones filtradas');

end
