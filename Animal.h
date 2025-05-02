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
    int niveldehambre;
    string preferencia;
    string personalidad;
    public:

    Animal(const string &nombre, int vida, int ataque, string tipo,int _niveldehambre, string _preferencia, string _personalidad, int _posx, int _posy);

    string getTipo()const;

    void recibirAtaque(int daño) override;

    void regenerarvida(int numero);

    virtual void mutar();;

    int getniveldehambre();

    string getPersonalidad();

    string getpreferencia();

    void mostrar()const override;

};



#endif //ANIMAL_H
