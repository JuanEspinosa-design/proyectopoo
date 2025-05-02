//
// Created by juanc on 23/04/2025.
//
#ifndef CRIATURABASE_H
#define CRIATURABASE_H
#include <memory>
#include <string>
#include "Mapa.h"
using namespace std;

#include <vector>
class Mapa;


class CriaturaBase : enable_shared_from_this<CriaturaBase> {

    protected:
    string nombre;
    weak_ptr<CriaturaBase> selfPtr;
    int vida;
    int ataque;
    int posx;
    int posy;
public:

    CriaturaBase( const string& nombre, int vida, int ataque,int _posx, int _posy);

    void setSharedPtr(std::shared_ptr<CriaturaBase> ptr);

    string getNombre()const;

    int getVida()const;

    void moverse(Mapa& mapa);

    int getAtaque()const;

    virtual void recibirAtaque(int daño) ;


    virtual void actuar(Mapa& mapa);;

    virtual void mostrar() const;

    int getposX();

    int getposY();
};




#endif //CRIATURABASE_H
