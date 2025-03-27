#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <vector>
#include "Objeto.h"

class Tienda {
private:
    std::vector<Objeto> inventario;
public:
    Tienda();
    void mostrarInventario() const;
    Objeto obtenerObjeto(std::string nombre) const;
};

#endif
