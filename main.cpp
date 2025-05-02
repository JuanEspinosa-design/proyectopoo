#include <iostream>
#include "Ecosistema.h"
#include "Animal.h"
#include "Planta.h"
#include "glorbo.h"

int main() {
    try {
        Ecosistema ecosistema(5, 5);

        shared_ptr<CriaturaBase> leon = make_shared<glorbo>("paquiao",19,20,"agresivo",18,20,"carnivoro","nose equisde",1,1);

        shared_ptr<CriaturaBase> planta = make_shared<Planta>("Árbol", 50, 0, 1, 1, 2);

        shared_ptr<CriaturaBase>marvin= make_shared<jirafa>("Marvin",18,33,"loco",33,33,"arboles","agresivo",1,0);

        ecosistema.agregarCriatura(leon, 1, 1);
        ecosistema.agregarCriatura(planta, 1, 1);
        ecosistema.agregarCriatura(marvin, 1, 1);
        ecosistema.agregarAguaAleatoria(*ecosistema.getMapa(),3);

        ecosistema.mostrarMapa();

        for (int i = 0; i < 6; ++i) {
            std::cout << "\n--- Ciclo " << i + 1 << " ---\n";
            ecosistema.simularTurno();
            ecosistema.mostrarMapa();
            ecosistema.imprimirEstado();
        }

    } catch (const std::bad_weak_ptr& e) {
        std::cerr << "Error: se usó shared_from_this() en un objeto no gestionado por shared_ptr\n";
        std::cerr << "Detalles: " << e.what() << std::endl;
    }

    return 0;
}
