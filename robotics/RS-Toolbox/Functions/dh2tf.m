function [T] = dh2tf(dh)
    % DH2TF Function to convert Denavit-Hartenberg parameters to transformation matrix
    %
    % Input Arguments:
    %     dh - Denavit-Hartenberg parameters (can be numeric or symbolic)
    %        - form: (a, alpha, d, theta)
    %
    % Output Arguments:
    %     T - 4x4 transformation matrix

    syms a alpha_ d theta real 
    % Define the transformation matrix based on DH parameters
    T = [cos(theta), -sin(theta)*cos(alpha_), sin(theta)*sin(alpha_), a*cos(theta);
         sin(theta), cos(theta)*cos(alpha_), -cos(theta)*sin(alpha_), a*sin(theta);
         0, sin(alpha_), cos(alpha_), d;
         0, 0, 0, 1];
     
    % Substitute DH parameters into the transformation matrix
    if isnumeric(dh)
        T = double(subs(T,{a,alpha_,d,theta},{dh}));
    else
        T = subs(T, {a, alpha_, d, theta}, dh);
    end
end