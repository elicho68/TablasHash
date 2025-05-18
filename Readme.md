Este programa permite leer líneas de código en lenguaje C++ desde consola, identificar cada token (palabra, número o símbolo) y almacenarlo en una tabla hash usando como clave su posición exacta (fila, columna) en el texto.

int suma = 0;
suma = 54 + 20;

Tabla Hash de Tokens:
000: 'int'
004: 'suma'
009: '='
011: '0'
012: ';'
100: 'suma'
105: '='
107: '54'
110: '+'
112: '20'
114: ';'

como copilar:
g++ main.cpp -o tabla_hash
./tabla_hash
