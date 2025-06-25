function [Matrix] = troty(angle)
Matrix=eye(4); 

if isa(angle, 'sym')
    Matrix = sym(Matrix);
end

Matrix(1:3,1:3)=robotics.internal.ang2rotm(angle,"y");

end