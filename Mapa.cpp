//
// Created by samue on 27/04/2025.
//

#include "Mapa.h"

Mapa::Mapa(int f, int c) {
    filas = f;
    columnas = c;
    celdas = vector<vector<Celda>>(filas, vector<Celda>(columnas));

}

Celda & Mapa::obtenerCelda(int x, int y) {
    return celdas[x][y]; // Devuelve referencia a la celda
}

int Mapa::getFilas() const {
    return filas;
}

int Mapa::getColumnas() const {
    return columnas;
}

void Mapa::mostrarMapa() const {
    const int ancho = 10; // Ancho de cada celda
    string bordeFila = "+" + string(columnas * (ancho + 1), '-'); // línea horizontal

    for (int i = 0; i < filas; ++i) {
        cout << bordeFila << "+\n";  // Línea superior de la fila

        cout << "|"; // Empieza la línea de contenido

        for (int j = 0; j < columnas; ++j) {
            const Celda& celda = celdas[i][j];

            std::string contenido = ".";

            if (!celda.getcriaturas().empty())
                contenido = "Criatura";
            else if (celda.hayAgua())
                contenido = "Agua";
            else if (celda.hayComida())
                contenido = "Comida";

            cout << std::setw(ancho) << std::left << contenido << "|";
        }

        cout << "\n";
    }

    cout << bordeFila << "+\n"; // Línea inferior final
}
