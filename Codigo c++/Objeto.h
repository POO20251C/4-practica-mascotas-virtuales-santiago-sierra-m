#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>

class Objeto {
private:
    std::string nombre;
    std::string efecto;
public:
    Objeto(std::string nombre, std::string efecto);
    std::string obtenerNombre() const;
    std::string obtenerEfecto() const;
};

#endif
