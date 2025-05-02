//
// Created by juanc on 23/04/2025.
//

#include "CriaturaBase.h"
#include "Mapa.h"
CriaturaBase::CriaturaBase(const string &nombre, int vida, int ataque, int _posx, int _posy): nombre(nombre), vida(vida), ataque(ataque) {
    posx = _posx;
    posy = _posy;
}

void CriaturaBase::setSharedPtr(std::shared_ptr<CriaturaBase> ptr) {
    selfPtr = ptr;
}

string CriaturaBase::getNombre() const {
    return nombre;
}

int CriaturaBase::getVida() const {
    return vida;
}

int CriaturaBase::getAtaque() const {
    return ataque;
}

void CriaturaBase::recibirAtaque(int daño) {
    vida-=daño;
    if (vida<0) {
        vida=0;
    }
}

void CriaturaBase::actuar(Mapa& mapa) {

};


void CriaturaBase::mostrar() const {
}

int CriaturaBase::getposX() {
    return posx;
}

int CriaturaBase::getposY() {
    return posy;
}

void CriaturaBase::moverse(Mapa& mapa) {
    std::vector<std::pair<int, int>> direcciones = {
        {0, 1},   // Derecha
        {0, -1},  // Izquierda
        {1, 0},   // Abajo
        {-1, 0}   // Arriba
    };

    int indice = rand() % direcciones.size();
    int nuevaX = posx + direcciones[indice].first;
    int nuevaY = posy + direcciones[indice].second;

    if (nuevaX >= 0 && nuevaX < mapa.getFilas() &&
        nuevaY >= 0 && nuevaY < mapa.getColumnas()) {

        // 💡 Usar el puntero compartido guardado de forma segura
        std::shared_ptr<CriaturaBase> ptr = selfPtr.lock();

        if (ptr) {
            mapa.obtenerCelda(posx, posy).eliminarCriaturaCompartida(ptr);
            mapa.obtenerCelda(nuevaX, nuevaY).agregarCriatura(ptr);

            posx = nuevaX;
            posy = nuevaY;
        } else {
            std::cerr << "[ERROR] Puntero compartido no válido en moverse().\n";
        }
        }
}

