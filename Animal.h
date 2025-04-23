//
// Created by juanc on 23/04/2025.
//

#ifndef ANIMAL_H
#define ANIMAL_H
using namespace std;
#include "CriaturaBase.h"
#include <string>


class Animal : public CriaturaBase {
    protected:
    string tipo;
    public:

    Animal(const string &nombre, int vida, int ataque, string tipo);

    string getTipo()const;

    void recibirAtaque(int daño) override;

    virtual void mostrar()const override;

};



#endif //ANIMAL_H
