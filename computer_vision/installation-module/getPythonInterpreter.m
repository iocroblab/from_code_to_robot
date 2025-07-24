function pyInterpreter = getPythonInterpreter()
%getPythonInterpreter Returns the path to the Python interpreter based on OS and architecture.
%
%   pyInterpreter = getPythonInterpreter() returns the full path to the
%   Python interpreter for the current system (Windows or Unix).
%
%   Example:
%       pyenv('Version', getPythonInterpreter);

    arch = computer('arch');
    installLocation = string(pwd) + filesep + arch;
    if ispc
        pyInterpreter = installLocation + filesep + "python\python";
    else
        pyInterpreter = installLocation + filesep + "python/bin/python3.11";
    end
end 