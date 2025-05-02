//
// Created by juanc on 23/04/2025.
//

#include "Planta.h"

Planta::Planta(const string &nombre, int vida, int ataque, int frutos, int _posx, int _posy): CriaturaBase(nombre, vida, ataque, _posx, _posy), frutos(frutos) {}

int Planta::getFrutos() const {
    return frutos;
}

void Planta::recibirAtaque(int daño) {
    vida-=daño;


}

void Planta::actuar(Mapa& mapa) {
    std::cout << nombre << " esta realizando fotosintesis.\n";
    // Por ahora no hace nada ofensivo
}

void profucirecursos() {

}

void Planta::mostrar() const {
    cout << "[" << getNombre() << ", " << getVida() << ", " << getAtaque() << ", " << frutos << "]";
    if (vida == 0) {
        cout << "Planta: " << getNombre() << " con frutos" << frutos << "murio" << endl;
    }
}
