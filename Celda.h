//
// Created by samue on 27/04/2025.
//

#ifndef CELDA_H
#define CELDA_H
#include <vector>
#include "iostream"
using namespace std;
#include <algorithm>
#include <iomanip>
#include <memory>
#include "Ecosistema.h"

#include <algorithm>


class CriaturaBase;

class Celda {
private:
    bool tieneAgua;
    bool tieneComida;
    vector<shared_ptr<CriaturaBase>> criaturas;  // IDs o nombres de criaturas

public:
    Celda();

    void setAgua(bool agua);

    void setComida(bool comida);

    bool hayAgua() const;

    bool hayComida() const;

    void agregarCriatura(std::shared_ptr<CriaturaBase> criatura);

    void eliminarCriatura(std::shared_ptr<CriaturaBase> criatura);

    const std::vector<std::shared_ptr<CriaturaBase>>& getcriaturas() const;

    void eliminarCriaturaCompartida(std::shared_ptr<CriaturaBase> criatura) {
        criaturas.erase(
            std::remove_if(criaturas.begin(), criaturas.end(),
                [&criatura](const std::shared_ptr<CriaturaBase>& c) {
                    return c == criatura;
                }),
            criaturas.end()
        );
    }
};





#endif //CELDA_H
