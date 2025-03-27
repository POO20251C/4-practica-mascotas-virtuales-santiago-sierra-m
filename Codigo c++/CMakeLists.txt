cmake_minimum_required(VERSION 3.10)
project(TiendaMascotas)

set(CMAKE_CXX_STANDARD 17)

add_executable(TiendaMascotas
        main.cpp
        Usuario.cpp
        Mascota.cpp
        Habilidad.cpp
        Objeto.cpp
        Historial.cpp
        Tienda.cpp
)
