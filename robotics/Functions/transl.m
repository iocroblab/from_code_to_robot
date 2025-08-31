function [Matrix] = transl(vec)
Matrix=eye(4); 

[row,col,~]=size(vec); 
if row==1&&col==3
    vec=vec'; 
elseif row==3&&col==1
   
else
    error('Input vector must be either a 1x3 or 3x1 vector.');
end
if isa(vec, 'sym')
    Matrix = sym(Matrix);
end

Matrix(1:3,4)=vec;


end