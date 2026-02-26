function SetRosDomain(domainID)
% SetRosDomain  Set the ROS 2 domain ID for this MATLAB session.
%
%   SetRosDomain()          % sets ROS_DOMAIN_ID = 0
%   SetRosDomain(domainID)  % sets ROS_DOMAIN_ID = domainID (integer)

    % --- Handle "no input" case ---
    if nargin < 1 || isempty(domainID)
        domainID = 0;
    end

    % --- Validate input ---
    validateattributes(domainID, ...
        {'numeric'}, {'scalar','integer','nonnegative'}, ...
        mfilename, 'domainID');

    % --- Apply domain ---
    setenv("ROS_DOMAIN_ID", num2str(domainID));

    fprintf("ROS_DOMAIN_ID set to %d\n", domainID);

    clear all; 
    evalin("base","clear all") ; 
    fprintf("cleared all workspaces, functions and applications started from inside matlab using StartTutorialApplication() will now use the new ROS domain");
end
