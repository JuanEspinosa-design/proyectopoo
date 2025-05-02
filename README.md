# 🌿🦒 Mundo de Criaturas - Simulación de Ecosistema con POO

## Descripción
Simulación de un ecosistema virtual donde criaturas (animales y plantas) interactúan en un mapa bidimensional, implementando:
- Herencia multiple (`CriaturaBase → Animal → glorbo/jirafa`)
- Polimorfismo (métodos virtuales `actuar()`, `mostrar()`)
- Gestión de memoria con smart pointers (`shared_ptr`, `weak_ptr`)
- Relaciones de agregación/composición entre clases
  ### ¿Qué encontramos en este proyecto?
| Clase | Descripción |
|-------|-------------|
| `CriaturaBase` | Clase abstracta base con posición, vida y ataque |
| `Animal` | Clase intermedia con hambre, preferencias y personalidad |
| `Planta` | Vegetales con sistema de frutos |

### Criaturas
| Clase | Características |
|-------|-----------------|
| `glorbo` | Depredador con escudo que ataca jirafas |
| `jirafa` | Herbívoro que esquiva y come plantas |

### Mundo
| Clase | Función |
|-------|---------|
| `Mapa` | Matriz de celdas para posicionamiento |
| `Celda` | Contiene criaturas y recursos (agua/comida) |
| `Ecosistema` | Controla la simulación y turnos |

## 🧮 Diagrama de Clases Estructurado

```mermaid
classDiagram
    direction TB

    class CriaturaBase {
        +string nombre
        +int vida
        +int ataque
        +int posx
        +int posy
        +moverse(Mapa& mapa) void
        +actuar(Mapa& mapa)* void
        +recibirAtaque(int daño) virtual void
        +mostrar()* void
        +getNombre() string
        +getVida() int
    }
    
    class Animal {
        +string tipo
        +int niveldehambre
        +string preferencia
        +string personalidad
        +mutar() virtual void
        +regenerarvida(int cantidad) void
    }
    
    class Planta {
       +int frutos
        +getFrutos() int
        +recibirAtaque(int daño) void
        +actuar(Mapa& mapa) void
    }
    
    class glorbo {
       +int escudo
        +recibirAtaque(int daño) override void
        +actuar(Mapa& mapa) override void
        +getescudo() int
    }
    
    class jirafa {
        +int salto
        +recibirAtaque(int daño) override void
        +actuar(Mapa& mapa) override void
        +getsalto() int
        +mutar() override void
    }
    
    class Celda {
       -bool tieneAgua
        -bool tieneComida
        -vector<shared_ptr<CriaturaBase>> criaturas
        +setAgua(bool agua) void
        +setComida(bool comida) void
        +hayAgua() bool
        +hayComida() bool
        +agregarCriatura(shared_ptr<CriaturaBase>) void
        +eliminarCriatura(shared_ptr<CriaturaBase>) void
    }
    
    class Mapa {
       -int filas
        -int columnas
        -vector<vector<Celda>> celdas
        +obtenerCelda(int x, int y) Celda&
        +mostrarMapa() void
        +getFilas() int
        +getColumnas() int
    }
    
    class Ecosistema {
        -shared_ptr<Mapa> mapa
        -vector<shared_ptr<CriaturaBase>> criaturas
        -int cicloActual
        +agregarCriatura(shared_ptr<CriaturaBase>, int x, int y) void
        +simularTurno() void
        +mostrarMapa() void
        +removerMuertas() void
        +agregarAguaAleatoria(int cantidad) void
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
