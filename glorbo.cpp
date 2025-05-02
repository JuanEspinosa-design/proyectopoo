//
// Created by samue on 23/04/2025.
//

#include "glorbo.h"

glorbo::glorbo(const string &nombre, int vida, int ataque, string tipo, int _escudo, int _niveldehambre,
    string _preferencia, string _personalidad, int _posx, int _posy): Animal(nombre, vida, ataque, tipo, _niveldehambre, _preferencia, _personalidad,_posx,_posy) {
    escudo=_escudo;
}

void glorbo::recibirAtaque(int daño) {
    vida-=daño-escudo;
    if (vida<=0) {
        vida=0;
        cout<<"El glorbo "<< nombre<< "murió"<<endl;
    }
}



void glorbo::actuar(Mapa& mapa) {
    auto& celda = mapa.obtenerCelda(posx, posy);

    for (auto& otra : celda.getcriaturas()) {
        if (otra.get() != this && dynamic_cast<jirafa*>(otra.get())) {
            std::cout << nombre << " ataca a " << otra->getNombre() << "!\n";
            otra->recibirAtaque(ataque);
        }
    }

    if (celda.hayAgua()) {
        std::cout << nombre << " ha evolucionado gracias al agua.\n";
        ataque += 5;
        vida += 10;
    }
}


    int glorbo::getescudo() {
        return escudo;
    }

    void glorbo::mostrar() const {
        cout << "[" << getNombre() << ", " << getVida() << ", " << getAtaque() << ", " << escudo << "]";
        if (vida == 0) {
            cout << "Glorbo: " << getNombre() << " con escudo" << escudo << "murio" << endl;
        }
    }
