# 🌿🦒 Mundo de Criaturas - Simulación Ecosistémica con POO

## 📌 Descripción
Simulación de un ecosistema virtual donde criaturas (animales y plantas) interactúan en un mapa bidimensional, implementando:
- Herencia multinivel (`CriaturaBase → Animal → glorbo/jirafa`)
- Polimorfismo (métodos virtuales `actuar()`, `mostrar()`)
- Gestión de memoria con smart pointers (`shared_ptr`, `weak_ptr`)
- Relaciones de agregación/composición entre clases

## 🧬 Estructura de Clases
```mermaid
classDiagram
    direction TB
    class CriaturaBase{
        <<abstract>>
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
