function variableResponseFromController = setControllerInputRecipe(ip)
% Simple function to check the controller response for the requested input
% recipe "input_int_register_1". On normal scenarios the function should
% return 'INT32'

% Connect to RTDE server
rtde = tcpclient(ip, 30004);

% Set protocol version
write(rtde, uint8([0 5 86 0 2]));
read(rtde, 4, "uint8");

% Request input register
write(rtde, uint8([0 23 73]), "uint8"); % for below mentioned input variable
write(rtde, "input_int_register_1", 'char');

% Read response header and payload
controllerResponse = read(rtde, 4, "uint8");
payloadSize = controllerResponse(2) - 4;

% 'INT32' - expected output. should not return 'IN_USE'
variableResponseFromController = read(rtde, payloadSize, "char");
end