//
// Created by samue on 25/04/2025.
//

#include "jirafa.h"
#include "Planta.h"

jirafa::jirafa(const string &nombre, int vida, int ataque, string tipo, int _salto, int _niveldehambre,
    string _preferencia, string _personalidad, int _posx, int _posy): Animal(nombre, vida, ataque, tipo, _niveldehambre, _preferencia, _personalidad,_posx,_posy) {
    salto=_salto;
}

void jirafa::recibirAtaque(int daño) { //La jirafa tiene la habilidad de esquivar depende del daño
    if (daño<50) {
        vida-=0;
    }
    else {
        vida-=daño;
    }
}

void jirafa::actuar(Mapa& mapa) {
    auto& celda = mapa.obtenerCelda(posx, posy);

    for (auto& otra : celda.getcriaturas()) {
        if (otra.get() != this && dynamic_cast<Planta*>(otra.get())) {
            std::cout << nombre << " devora a " << otra->getNombre() << "!\n";
            otra->recibirAtaque(ataque);

            std::cout << nombre << " ha evolucionado tras comer planta.\n";
            vida += 5;
            ataque += 2;
        }
    }
}



int jirafa::getsalto() {
    return salto;
}

void jirafa::mostrar() const {
    cout << "jirafa: "<<"[" << getNombre() << ", " << getVida() << ", " << getAtaque() << ", " << salto << "]";
    if (vida <= 0) {
        cout << "Jirafa: " << getNombre() << " con salto" << salto<< "murio" << endl;
    }

}

void jirafa::mutar() {
    cout<<"la jirafa "<<nombre<< " muta";
    salto+=1;
    vida+=20;
    cout<<"vida +20"<<endl;
    cout<<"salto +1"<<endl;
}
