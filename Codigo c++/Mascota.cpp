#include "Mascota.h"

Mascota::Mascota(std::string nombre, int edad)
    : nombre(nombre), edad(edad), energia(100), salud(EstadoSalud::SANO),
      estadoEmocional(EstadoEmocional::NEUTRO), experiencia(0),
      historial(std::make_shared<Historial>()) {}

std::string Mascota::obtenerNombre() const {
    return nombre;
}

int Mascota::obtenerExperiencia() const {  // <--- Implementación de la nueva función
    return experiencia;
}

void Mascota::recibirObjeto(const Objeto& objeto) {
    historial->registrarEvento("Objeto recibido: " + objeto.obtenerNombre());
}

void Mascota::aprenderHabilidad(Habilidad habilidad) {
    if (experiencia >= habilidad.obtenerNivelRequerido()) {
        habilidades.push_back(habilidad);
        historial->registrarEvento("Habilidad aprendida: " + habilidad.obtenerNombre());
    }
}

void Mascota::aumentarExperiencia(int exp) {
    experiencia += exp;
    historial->registrarEvento("Experiencia aumentada en " + std::to_string(exp));
}

void Mascota::mostrarEstado() const {
    std::cout << "Mascota: " << nombre << ", Edad: " << edad
              << ", Energía: " << energia << ", Salud: " << static_cast<int>(salud)
              << ", Estado emocional: " << static_cast<int>(estadoEmocional)
              << ", Experiencia: " << experiencia << std::endl;
}

void Mascota::consultarHistorial() const {
    historial->mostrarHistorial();
}
