#include "Usuario.h"

Usuario::Usuario() : nombre("Desconocido") {}  // Constructor por defecto con un nombre genérico

Usuario::Usuario(std::string nombre) : nombre(nombre) {}

void Usuario::adoptarMascota(std::shared_ptr<Mascota> mascota) {
    mascotas[mascota->obtenerNombre()] = mascota;
}

void Usuario::mostrarMascotas() {
    std::cout << "Mascotas de " << nombre << ":\n";
    for (const auto& par : mascotas) {
        std::cout << "- " << par.first << "\n";
    }
}
std::shared_ptr<Mascota> Usuario::obtenerMascota(std::string nombre) {
    if (mascotas.find(nombre) != mascotas.end()) {
        return mascotas[nombre];
    }
    return nullptr;
}
