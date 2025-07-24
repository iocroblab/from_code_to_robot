function classNames = ReadClassNames(yamlFile)
%READCLASSNAMES Lee los nombres de clase de un archivo YAML tipo YOLOv8
%   classNames = ReadClassNames(yamlFile) devuelve un cell array con los nombres de clase
%   encontrados en la sección 'names:' del archivo YAML especificado.

if nargin < 1
    yamlFile = 'data.yaml';
end

fid = fopen(yamlFile, 'r');
if fid == -1
    error('No se pudo abrir el archivo: %s', yamlFile);
end

classNames = {};
insideNames = false;

while ~feof(fid)
    line = strtrim(fgetl(fid));
    if startsWith(line, 'names:')
        insideNames = true;
        continue;
    end
    if insideNames
        % Fin de la sección names si la línea está vacía o no tiene formato de índice
        if isempty(line) || ~contains(line, ':')
            break;
        end
        % Extraer nombre de clase
        tokens = regexp(line, '^\d+:\s*(.+)$', 'tokens');
        if ~isempty(tokens)
            classNames{end+1} = strtrim(tokens{1}{1}); %#ok<AGROW>
        end
    end
end

fclose(fid);

end
