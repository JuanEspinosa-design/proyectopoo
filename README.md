# 🌿🦒 Mundo de Criaturas - Simulación de Ecosistema con POO

## ¿COMO CLONAR EL REPOSITORIO?
En la terminal de bash pon: git clone https://github.com/tuusuario/proyectopoo.git
- Luego: cd proyectopoo

# MANUAL DE USUARIO:

## FUNCIONALIDADES PRINCIPALES
- **Simulación por turnos**: Avanza el ecosistema paso a paso
- **Sistema de interacciones**:
  - Depredación (glorbos → jirafas)
  - Herbivoría (jirafas → plantas)
  - Efectos ambientales (agua mejora atributos)
- **Evolución dinámica**: Mutaciones que modifican habilidades

## DESCRIPCIÓN:
Simulación de un ecosistema virtual donde criaturas (animales y plantas) interactúan en un mapa bidimensional, implementando:
- Herencia multiple (`CriaturaBase → Animal → glorbo/jirafa`)
- Polimorfismo (métodos virtuales `actuar()`, `mostrar()`)
- Gestión de memoria con smart pointers (`shared_ptr`, `weak_ptr`)
- Relaciones de agregación/composición entre clases
  ### ¿QUÉ ENCONTRAMOS EN ESTE PROYECTO?
| Clase | Descripción |
|-------|-------------|
| `CriaturaBase` | Clase abstracta base con posición, vida y ataque |
| `Animal` | Clase intermedia con hambre, preferencias y personalidad |
| `Planta` | Vegetales con sistema de frutos |

### CRIATURAS:
| Clase | Características |
|-------|-----------------|
| `glorbo` | Depredador con escudo que ataca jirafas |
| `jirafa` | Herbívoro que esquiva y come plantas |

### MUNDO:
| Clase | Función |
|-------|---------|
| `Mapa` | Matriz de celdas para posicionamiento |
| `Celda` | Contiene criaturas y recursos (agua/comida) |
| `Ecosistema` | Controla la simulación y turnos |


## DIAGRAMA DE CLASES UML:

```mermaid
classDiagram
    direction TB

    class CriaturaBase {
        +string nombre
        +int vida
        +int ataque
        +int posx
        +int posy
        +void moverse(Mapa& mapa) 
        +void actuar(Mapa& mapa)* 
        +virtual void recibirAtaque(int daño) 
        +void mostrar()*
        +string getNombre() 
        +int getVida() 
    }
    
    class Animal {
        +string tipo
        +int niveldehambre
        +string preferencia
        +string personalidad
        +virtual void mutar() 
        +void regenerarvida(int cantidad) 
    }
    
    class Planta {
       +int frutos
        +int getFrutos() 
        +void recibirAtaque(int daño) 
        +void actuar(Mapa& mapa) 
    }
    
    class glorbo {
       +int escudo
        +override void recibirAtaque(int daño) 
        +override void actuar(Mapa& mapa)
        +int getescudo() 
    }
    
    class jirafa {
        +int salto
        +override void recibirAtaque(int daño) 
        +override void actuar(Mapa& mapa) 
        +int getsalto() 
        +override void mutar() 
    }
    
    class Celda {
       -bool tieneAgua
        -bool tieneComida
        -vector<shared_ptr<CriaturaBase>> criaturas
        +void setAgua(bool agua) 
        +void setComida(bool comida) 
        +bool hayAgua() 
        +bool hayComida() 
        +oid agregarCriatura(shared_ptr<CriaturaBase>) 
        +void eliminarCriatura(shared_ptr<CriaturaBase>) 
    }
    
    class Mapa {
       -int filas
        -int columnas
        -vector<vector<Celda>> celdas
        +obtenerCelda(int x, int y) Celda&
        +void mostrarMapa() 
        +int getFilas() 
        +int getColumnas() 
    }
    
    class Ecosistema {
        -shared_ptr<Mapa> mapa
        -vector<shared_ptr<CriaturaBase>> criaturas
        -int cicloActual
        +void agregarCriatura(shared_ptr<CriaturaBase>, int x, int y) 
        +void simularTurno() 
        +void mostrarMapa() 
        +void removerMuertas() 
        +void agregarAguaAleatoria(int cantidad) 
    }
    
    CriaturaBase <|-- Animal
    CriaturaBase <|-- Planta
    Animal <|-- glorbo
    Animal <|-- jirafa
    
    Ecosistema "1" *-- "1" Mapa
    Mapa "1" *-- "*" Celda
    Celda "1" o-- "*" CriaturaBase
    
    glorbo --> jirafa : ataca
    jirafa --> Planta : consume


