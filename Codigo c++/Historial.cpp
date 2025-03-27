#include "Historial.h"
#include <iostream>

void Historial::registrarEvento(const std::string& evento) {
    eventos.push_back(evento);
}

void Historial::mostrarHistorial() const {
    std::cout << "Historial de eventos:\n";
    for (const auto& evento : eventos) {
        std::cout << "- " << evento << "\n";
    }
}
