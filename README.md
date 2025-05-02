# 🌿🦒 Mundo de Criaturas - Simulación Ecosistémica con POO

## 📌 Descripción
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

## 🧬 Estructura de Clases
```mermaid
classDiagram
    direction TB
    class CriaturaBase{
        +string nombre
        +int vida
        +int ataque
        +moverse()
        +actuar() virtual
    }
    class Animal{
        +string tipo
        +mutar() virtual
    }
    class Planta{
        +int frutos
    }
    class glorbo{
        +int escudo
        +actuar() override
    }
    class jirafa{
        +int salto
        +mutar() override
    }
    CriaturaBase <|-- Animal
    CriaturaBase <|-- Planta
    Animal <|-- glorbo
    Animal <|-- jirafa
