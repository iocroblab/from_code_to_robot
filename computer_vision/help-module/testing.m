% Paso 1: Verificar versión de Python
pyenv  % Muestra configuración actual

% Paso 2: Añadir la ruta del módulo si no está ya incluida
wrapperPath = 'C:\ruta\a\tu\carpeta';  % ← Cambia esto a la ruta real
if count(py.sys.path, wrapperPath) == 0
    insert(py.sys.path, int32(0), wrapperPath);
end

% Paso 3: Intentar importar el módulo y ver contenido
try
    mod = py.importlib.import_module('trainYOLOv8Wrapper');
    disp('✅ Módulo importado correctamente.');
    disp('🔍 Contenido del módulo:');
    disp(fieldnames(mod));
catch ME
    disp('❌ No se pudo importar el módulo.');
    disp(getReport(ME));
end
