#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <iostream>
#include <vector>

class Historial {
private:
    std::vector<std::string> eventos;
public:
    void registrarEvento(const std::string& evento);
    void mostrarHistorial() const;
};

#endif

