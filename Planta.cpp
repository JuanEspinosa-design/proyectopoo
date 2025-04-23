//
// Created by juanc on 23/04/2025.
//

#include "Planta.h"

Planta::Planta(const string &nombre, int vida, int ataque, string frutos): CriaturaBase(nombre, vida, ataque), frutos(frutos) {}

string Planta::getFrutos() const {
    return frutos;
}

void Planta::recibirAtaque() {

}

void Planta::mostrar() const {
    cout << "[" << getNombre() << ", " << getVida() << ", " << getAtaque() << ", " << frutos << "]";
    if (vida == 0) {
        cout << "Planta: " << getNombre() << " con frutos" << frutos << "murio" << endl;
    }
}
