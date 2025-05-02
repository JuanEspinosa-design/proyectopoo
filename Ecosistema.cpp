//
// Created by samue on 27/04/2025.
//

#include "Ecosistema.h"
#include "Planta.h"
#include "glorbo.h"
#include "jirafa.h"

Ecosistema::Ecosistema(Mapa *mapa): mapa(mapa), cicloActual(0) {}

Ecosistema::Ecosistema(int filas, int columnas)
    : mapa(std::make_shared<Mapa>(filas, columnas)), cicloActual(0) {}

void Ecosistema::agregarCriatura(shared_ptr<CriaturaBase> criatura, int x, int y) {
    criatura->setSharedPtr(criatura);
    criaturas.push_back(criatura);
    mapa->obtenerCelda(x, y).agregarCriatura(criatura);
}

void Ecosistema::mostrarMapa() const {
    int ancho = 6;
    std::string bordeFila = "+" + std::string(mapa->getColumnas() * (ancho + 1), '-') + "+";

    for (int i = 0; i < mapa->getFilas(); ++i) {
        std::cout << bordeFila << "\n";
        for (int j = 0; j < mapa->getColumnas(); ++j) {
            const Celda& celda = mapa->obtenerCelda(i, j);
            std::string contenido = "";
            for (const auto& criatura : celda.getcriaturas()) {
                if (dynamic_cast<glorbo*>(criatura.get())) contenido += "G";
                else if (dynamic_cast<jirafa*>(criatura.get())) contenido += "J";
                else if (dynamic_cast<Planta*>(criatura.get())) contenido += "P";
            }

            if (celda.hayAgua()) contenido += "A";
            if (contenido.empty()) contenido = "__";

            std::cout << "|" << std::setw(ancho) << std::left << contenido;
        }
        std::cout << "|\n";
    }
    std::cout << bordeFila << "\n\n";
}

void Ecosistema:: agregarAguaAleatoria(Mapa& mapa, int cantidad) {
    int filas = mapa.getFilas();
    int columnas = mapa.getColumnas();
    std::srand(std::time(nullptr));

    for (int i = 0; i < cantidad; ++i) {
        int x = std::rand() % filas;
        int y = std::rand() % columnas;
        mapa.obtenerCelda(x, y).setAgua(true);
        std::cout << "Agua agregada en (" << x << ", " << y << ")\n";
    }
}

void Ecosistema::simularTurno() {
    cout << "\n--- Ciclo " << cicloActual << " ---\n";

    // 1. Cada criatura decide qué hacer
    for (auto& criatura : criaturas) {
        if (criatura->getVida()>0) {
            criatura->moverse(*mapa);
            criatura->actuar(*mapa);
            removerMuertas();
        }

    }

    // 2. Eliminar criaturas muertas del ecosistema y mapa



    cicloActual++;
}

void Ecosistema::removerMuertas() {
    for (auto it = criaturas.begin(); it != criaturas.end();) {
        if (!(*it)->getVida()>0) {
            eliminarCriaturaDeMapa(*it);  // requiere implementación
            it = criaturas.erase(it);
        } else {
            ++it;
        }
    }
}
void Ecosistema::eliminarCriaturaDeMapa(std::shared_ptr<CriaturaBase> criatura) {
    int x = criatura->getposX();
    int y = criatura->getposY();
    mapa->obtenerCelda(x, y).eliminarCriatura(criatura);
}

void Ecosistema::imprimirEstado() const {
    std::cout << "\nCiclo actual: " << cicloActual
            << " | Criaturas vivas: " << criaturas.size() << "\n";
}

int Ecosistema::getCiclo() const { return cicloActual; }

std::shared_ptr<Mapa> Ecosistema::getMapa() const {
    return mapa;
}

