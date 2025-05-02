cmake_minimum_required(VERSION 3.30)
project(ProyectoPoodesarrollo)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoPoodesarrollo main.cpp
        CriaturaBase.cpp
        CriaturaBase.h
        Animal.cpp
        Animal.h
        Planta.cpp
        Planta.h
        glorbo.cpp
        glorbo.h
        jirafa.cpp
        jirafa.h
        Ecosistema.cpp
        Ecosistema.h
        Mapa.cpp
        Mapa.h
        Celda.cpp
        Celda.h)
