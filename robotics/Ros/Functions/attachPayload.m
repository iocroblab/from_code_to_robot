function attachPayload(flag)
% attachPayload Call ROS 2 SetBool service to attach or detach a payload
%
%   success = attachPayload(flag)
%
%   Input:
%       flag (logical or numeric) - true/1 to attach, false/0 to detach
%
%   Output:
%       success (logical) - service response success field
%
%   Example:
%       attachPayload(true)
%       attachPayload(false)

    arguments
        flag (1,1) {mustBeNumericOrLogical}
    end

    % Ensure logical
    flag = logical(flag);

    % Create (or reuse) ROS 2 node
    persistent node client
    if isempty(node) || ~isvalid(node)
        node = ros2node("attach_payload_client");
        client = ros2svcclient(node, ...
            "/attach_payload", ...
            "std_srvs/SetBool");
    end

    % Create request message
    req = ros2message(client);
    req.data = flag;

    % Call service
    resp = call(client, req);

    % Return success flag

end
