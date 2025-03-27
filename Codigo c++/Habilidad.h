#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <iostream>

class Habilidad {
private:
    std::string nombre;
    int nivelRequerido;
public:
    Habilidad(std::string nombre, int nivelRequerido);
    std::string obtenerNombre() const;
    int obtenerNivelRequerido() const;
};

#endif
