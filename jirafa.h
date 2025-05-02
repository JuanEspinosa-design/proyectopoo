//
// Created by samue on 25/04/2025.
//

#ifndef JIRAFA_H
#define JIRAFA_H
#include "Animal.h"
#include "iostream"



class jirafa: public Animal {
private:
    int salto;
public:
    jirafa(const string &nombre, int vida, int ataque, string tipo,int _salto,int _niveldehambre, string _preferencia, string _personalidad, int posx, int posy);

    void recibirAtaque(int daño) override;

    void actuar(Mapa& mapa);

    int getsalto();

    void mostrar() const override;

    void mutar() override;
};



#endif //JIRAFA_H
