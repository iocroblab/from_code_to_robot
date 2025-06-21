function visualizeRotation(rotation, viewmode)
translation=[0,0,0]; 

% Transform the rotation matrix to a quaternion (1x4 array)
rot =  quaternion(rotation, 'rotmat', 'point'); % no rotation for this example

% Create a figure
figure;

% Plot the origin frame (at [0, 0, 0]) with the identity rotation
plotTransforms(zeros(1,3), [1,0,0,0]); 
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
if strcmp(viewmode, 'x')
    view(-80, 30); % Set the view to look along the x-axis
elseif strcmp(viewmode, 'y')
    view(-5, 25); % Set the view to look along the y-axis
elseif strcmp(viewmode, 'z')
    view(-20, 40); % Set the view to look along the z-axis
end
grid on;
end