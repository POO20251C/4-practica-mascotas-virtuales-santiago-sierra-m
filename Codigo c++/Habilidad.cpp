#include "Habilidad.h"

Habilidad::Habilidad(std::string nombre, int nivelRequerido)
    : nombre(nombre), nivelRequerido(nivelRequerido) {}

std::string Habilidad::obtenerNombre() const {
    return nombre;
}

int Habilidad::obtenerNivelRequerido() const {
    return nivelRequerido;
}
