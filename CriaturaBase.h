//
// Created by juanc on 23/04/2025.
//
#include <string>
using namespace std;
#ifndef CRIATURABASE_H
#define CRIATURABASE_H



class CriaturaBase {

    protected:
    string nombre;
    int vida;
    int ataque;
public:

    CriaturaBase( const string& nombre, int vida, int ataque);

    string getNombre()const;

    int getVida()const;

    int getAtaque()const;

    virtual void recibirAtaque(int daño);

    virtual void mostrar() const;
};




#endif //CRIATURABASE_H
