//
// Created by samue on 27/04/2025.
//

#ifndef MAPA_H
#define MAPA_H
using namespace std;
#include <vector>
#include "Celda.h"
#include "iostream"
#include <algorithm>
#include <iomanip>

class Celda;


class Mapa {
private:
    int filas;
    int columnas;
    std::vector<std::vector<Celda>> celdas;

public:
    Mapa(int f, int c);
    Celda& obtenerCelda(int x, int y);

    void mostrarMapa()const;
    int getFilas()const;
    int getColumnas()const;
};









#endif //MAPA_H
