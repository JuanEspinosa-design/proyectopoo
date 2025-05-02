//
// Created by samue on 27/04/2025.
//

#include "Celda.h"

Celda::Celda(): tieneAgua(false), tieneComida(false) {}

void Celda::setAgua(bool agua) { tieneAgua = agua; }

void Celda::setComida(bool comida) { tieneComida = comida; }

bool Celda::hayAgua() const { return tieneAgua; }

bool Celda::hayComida() const { return tieneComida; }

void Celda::agregarCriatura(std::shared_ptr<CriaturaBase> criatura) {  criaturas.push_back(criatura); }


void Celda::eliminarCriatura(std::shared_ptr<CriaturaBase> criatura) {
    auto it = std::remove_if(criaturas.begin(), criaturas.end(),
     [&](const std::shared_ptr<CriaturaBase>& c) {
         return c == criatura;
     });

    if (it != criaturas.end()) {
        criaturas.erase(it, criaturas.end());
    }
}

const std::vector<std::shared_ptr<CriaturaBase>>& Celda::getcriaturas() const {
    return criaturas;
}
