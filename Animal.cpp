//
// Created by juanc on 23/04/2025.
//
#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal(const string &nombre, int vida, int ataque, string tipo) : CriaturaBase(nombre, vida, ataque), tipo(tipo) {}

string Animal::getTipo() const {
    return tipo;
}

void Animal::recibirAtaque(int daño) {

}

void Animal::mostrar() const {
    cout << "[" << nombre << ", " << vida << ", " << ataque << ", " << tipo << "]";
    if (vida == 0) {
        cout << "Animal: " << nombre << " de tipo" << tipo << "murio" << endl;
    }
}
