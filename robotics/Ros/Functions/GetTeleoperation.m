function [v6, teleopMode] = GetTeleoperation()
%GETTELEOPERATION Return latest /cmd_vel and /teleop_mode (ROS 2).
%   [V6, MODE] = GETTELEOPERATION()
%   V6   : 6x1 double [vx; vy; vz; wx; wy; wz]
%   MODE : string with latest teleoperation mode ("" if none yet)

    persistent node subTwist subMode %lastV6 lastMode
 %   global v6 teleopMode
        v6   = zeros(6,1,'double');
        teleopMode = "";

    if isempty(node) || ~isvalid(node)
        nodeName = sprintf("/get_teleop_node_%d", feature('getpid'));
        node = ros2node(nodeName);

        % Persistent subscribers (no callback)
        subTwist = ros2subscriber(node, "/cmd_vel", "geometry_msgs/Twist");
        subMode  = ros2subscriber(node, "/teleop_mode", "std_msgs/String");

        % lastV6   = zeros(6,1,'double');
        % lastMode = "";
    end

    % Try to grab any fresh messages very quickly (non-blocking-ish)
    try
         msg =subTwist.LatestMessage;  % 1 ms timeout
         v6 = [ double(msg.linear.x);  double(msg.linear.y);  double(msg.linear.z); ...
                   double(msg.angular.x); double(msg.angular.y); double(msg.angular.z) ];
    catch
        % no new /cmd_vel; keep lastV6
    end

    try
        m = subMode.LatestMessage;     % 1 ms timeout
        if ~isempty(m.data)
            teleopMode = string(m.data);
        end
    catch
        % no new /teleop_mode; keep lastMode
    end

    % v6 = lastV6;
    % teleopMode = lastMode;


end
% function twistcallback(msg)
%     global v6 
%     v6 = [ double(msg.linear.x);  double(msg.linear.y);  double(msg.linear.z); ...
%                double(msg.angular.x); double(msg.angular.y); double(msg.angular.z) ];
% 
% end
% 
% function modecallback(msg)
%     global teleopMode
%      teleopMode = string(msg.data);
% end