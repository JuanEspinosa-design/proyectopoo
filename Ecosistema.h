//
// Created by samue on 27/04/2025.
//

#ifndef ECOSISTEMA_H
#define ECOSISTEMA_H
#include "CriaturaBase.h"
using namespace std;
#include "iostream"

class CriaturaBase;
class Mapa;



class Ecosistema {
private:
    std::shared_ptr<Mapa> mapa;  // no es dueño del mapa, solo lo utiliza → agregación
    vector<shared_ptr<CriaturaBase>> criaturas;  // todas las criaturas activas
    int cicloActual;
public:
    Ecosistema(Mapa* mapa);

    Ecosistema(int filas, int columnas);

    void agregarCriatura(shared_ptr<CriaturaBase> criatura, int x, int y);

    void simularTurno();

    void mostrarMapa() const;

    void removerMuertas();

    void imprimirEstado() const;

    void agregarAguaAleatoria(Mapa& mapa, int cantidad);

    int getCiclo() const;
    void eliminarCriaturaDeMapa(std::shared_ptr<CriaturaBase> criatura);

    std::shared_ptr<Mapa> getMapa() const;

};



#endif //ECOSISTEMA_H
