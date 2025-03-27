#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <map>
#include <memory>
#include "Mascota.h"

class Usuario {
private:
    std::string nombre;
    std::map<std::string, std::shared_ptr<Mascota>> mascotas;  // Relación con mascotas

public:
    Usuario();
    Usuario(std::string nombre);
    void adoptarMascota(std::shared_ptr<Mascota> mascota);
    void mostrarMascotas();
    std::shared_ptr<Mascota> obtenerMascota(std::string nombre);
};

#endif
