#include "Objeto.h"

Objeto::Objeto(std::string nombre, std::string efecto)
    : nombre(nombre), efecto(efecto) {}

std::string Objeto::obtenerNombre() const {
    return nombre;
}

std::string Objeto::obtenerEfecto() const {
    return efecto;
}
