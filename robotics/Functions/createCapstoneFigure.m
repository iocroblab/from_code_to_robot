function ax = createCapstoneFigure()
% CREATECAPSTONEFIGURE Creates a separate figure window for webcam display.
%
%   ax = createCapstoneFigure()
%
%   Returns an axes handle that can be passed into Capstone_Vision_demo.

    set(groot, 'DefaultFigureWindowStyle', 'normal');

    fig = figure( ...
        'Name', 'Capstone Yolo Detection', ...
        'NumberTitle', 'off', ...
        'WindowStyle', 'normal', ...
        'Visible', 'on');

    ax = axes('Parent', fig);

    title(ax, 'Capstone Yolo Detection');
    axis(ax, 'image');
end