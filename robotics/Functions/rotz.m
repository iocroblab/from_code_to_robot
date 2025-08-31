function [Matrix] = rotz(angle)

Matrix=robotics.internal.ang2rotm(angle,"z");

end