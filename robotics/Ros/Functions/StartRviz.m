function StartRviz(ur_model)
%STARTRVIZ Summary of this function goes here
%   Detailed explanation goes here
arguments (Input)
    ur_model
    
end

if isunix %only start up Rviz automatically if run on Ubuntu
    promt = strcat(['cd Ros/Repo/; ' ...
        'source install/setup.bash; ' ...
        'ros2 launch ur_description view_ur.launch.py ur_type:=', ur_model]); 
    StartIfNotRunning('view_ur\.launch\.py', promt);


elseif ispc
    promt=strcat('wsl docker exec -dit gz-modified bash -c "cd Ros/Repo && source install/setup.bash && ros2 launch ur_description view_ur.launch.py ur_type:=', ur_model, '"');
    StartIfNotRunning('view_ur\.launch\.py', promt, "windows");    
end
end