//
// Created by samue on 23/04/2025.
//

#ifndef GLORBO_H
#include "jirafa.h"
#include "Celda.h"
#define GLORBO_H
#include <iostream>

#include "Animal.h"
using namespace std;



class glorbo: public Animal {
private:
    int escudo;
public:
    glorbo(const string &nombre, int vida, int ataque, string tipo,int _escudo,int _niveldehambre, string _preferencia, string _personalidad, int _posx,int posy);

    void recibirAtaque(int daño) override;


    void actuar(Mapa& mapa);

    int getescudo();

    void mostrar()const override;
};



#endif //GLORBO_H
