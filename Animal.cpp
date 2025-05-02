//
// Created by juanc on 23/04/2025.
//
#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal(const string &nombre, int vida, int ataque, string tipo,int _niveldehambre, string _preferencia, string _personalidad,int _posx, int _posy ) : CriaturaBase(nombre, vida, ataque,_posx,_posy), tipo(tipo) {
    niveldehambre = _niveldehambre;
    preferencia= _preferencia;
    personalidad = _personalidad;
}

string Animal::getTipo() const {
    return tipo;
}

void Animal::recibirAtaque(int daño) {
    vida-=daño;
}

void Animal::regenerarvida(int numero) {
    vida+=numero;
}

void Animal::mutar() {
    cout << "Mutar Animal" << endl;
}

int Animal::getniveldehambre() {
    return niveldehambre;
}

string Animal::getPersonalidad() {
    return personalidad;
}

string Animal::getpreferencia() {
    return personalidad;
}

void Animal::mostrar() const {
    cout << "[" << getNombre() << ", " << getVida() << ", " << getAtaque() << ", " << tipo << "]";
    if (vida == 0) {
        cout << "Animal: " << getNombre() << " de tipo" << tipo << "murio" << endl;
    }
}
