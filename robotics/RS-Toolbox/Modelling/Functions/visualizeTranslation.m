function visualizeTranslation(translation)

% Define the rotation as a quaternion (1x4 array)
rot = [1, 0, 0, 0]; % no rotation for this example

% Create a figure
figure;

% Plot the origin frame (at [0, 0, 0]) with the identity rotation
plotTransforms(zeros(1,3), rot); 
hold on;

% Plot the transformed frame at the specified translation with the same rotation
plotTransforms(translation, rot); 
hold off;

% Set axis properties for better visualization
axis equal;
xlabel('X-axis');
ylabel('Y-axis');
zlabel('Z-axis');
title('Visualization of Transformations');
grid on;
end