//
// Created by juanc on 23/04/2025.
//

#include "CriaturaBase.h"
CriaturaBase::CriaturaBase(const string &nombre, int vida, int ataque): nombre(nombre), vida(vida), ataque(ataque) {}

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
}


void CriaturaBase::mostrar() const {
}
