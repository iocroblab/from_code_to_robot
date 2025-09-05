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
Tsym = [cos(theta), -sin(theta)*cos(alpha_), sin(theta)*sin(alpha_), a*cos(theta);
    sin(theta), cos(theta)*cos(alpha_), -cos(theta)*sin(alpha_), a*sin(theta);
    0, sin(alpha_), cos(alpha_), d;
    0, 0, 0, 1];

% Substitute DH parameters into the transformation matrix
T=eye(4);
for i=1:size(dh,1)
    if isnumeric(dh)
        T = T * double(subs(Tsym,{a,alpha_,d,theta},{dh(i,:)}));
    else
        T = T * subs(Tsym, {a, alpha_, d, theta}, dh(i,:));
    end
end

if ~isnumeric(T)
    T=simplify(T); 
end

end