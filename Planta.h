//
// Created by juanc on 23/04/2025.
//

#ifndef PLANTA_H
#define PLANTA_H
#include <iostream>
#include "CriaturaBase.h"
using namespace std;
#include <string>



class Planta : CriaturaBase {
protected:
    string frutos;
    public:

    Planta(const string &nombre, int vida, int ataque, string frutos);

    string getFrutos()const;;

    void recibirAtaque();

    virtual void mostrar()const;
};



#endif //PLANTA_H
