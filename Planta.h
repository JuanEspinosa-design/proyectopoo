//
// Created by juanc on 23/04/2025.
//

#ifndef PLANTA_H
#define PLANTA_H
#include <iostream>
#include "CriaturaBase.h"
using namespace std;
#include <string>



class Planta : public CriaturaBase {
protected:
    int frutos;
public:

    Planta(const string &nombre, int vida, int ataque, int frutos, int posx, int posy);

    int getFrutos()const;

    void recibirAtaque(int daño);

    void actuar(Mapa& mapa);




    void mostrar()const override;
};



#endif //PLANTA_H
