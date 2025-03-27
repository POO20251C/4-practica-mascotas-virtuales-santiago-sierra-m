#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <vector>
#include <memory>
#include "Habilidad.h"
#include "Objeto.h"
#include "Historial.h"

enum class EstadoSalud { SANO, REGULAR, ENFERMO, MUY_ENFERMO };
enum class EstadoEmocional { FELIZ, NEUTRO, TRISTE };

class Mascota {
private:
    std::string nombre;
    int energia;
    EstadoSalud salud;
    int edad;
    EstadoEmocional estadoEmocional;
    int experiencia;
    std::vector<Habilidad> habilidades;
    std::shared_ptr<Historial> historial;

public:
    Mascota(std::string nombre, int edad);

    std::string obtenerNombre() const;
    int obtenerExperiencia() const;  // <--- Nueva función agregada

    void recibirObjeto(const Objeto& objeto);
    void aprenderHabilidad(Habilidad habilidad);
    void aumentarExperiencia(int exp);
    void mostrarEstado() const;
    void consultarHistorial() const;
};

#endif
