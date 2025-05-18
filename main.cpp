#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <regex>
#include <iomanip>
#include <map>

using namespace std;

// Estructura de clave (fila, columna real del token)
struct Posicion {
    int fila;
    int columna;

    bool operator<(const Posicion& other) const {
        return tie(fila, columna) < tie(other.fila, other.columna);
    }
};

int main() {
    vector<string> lineas;
    string linea;
    cout << "Codifica en C++ (ENTER vacío para terminar):\n";

    // Entrada del código multilínea
    while (true) {
        getline(cin, linea);
        if (linea.empty()) break;
        lineas.push_back(linea);
    }

    // Tabla hash de tokens
    map<Posicion, string> tabla_hash;

    // Regex para tokenizar igual que en Python
    regex patron(R"(\w+|[=+\*/;-])");


    for (int fila = 0; fila < lineas.size(); ++fila) {
        string& texto = lineas[fila];
        auto palabras = sregex_iterator(texto.begin(), texto.end(), patron);
        auto fin = sregex_iterator();

        for (auto it = palabras; it != fin; ++it) {
            string token = it->str();
            int columna = it->position();
            tabla_hash[{fila, columna}] = token;
        }
    }

    // Mostrar resultado
    cout << "\nTabla Hash de Tokens:\n";
    for (const auto& par : tabla_hash) {
        cout << par.first.fila << setw(2) << setfill('0') << par.first.columna
             << ": '" << par.second << "'\n";
    }

    return 0;
}
