#include "Tienda.h"

Tienda::Tienda() {
    inventario.push_back(Objeto("Pocion", "Restaura salud"));
    inventario.push_back(Objeto("Pelota", "Mejora estado emocional"));
    inventario.push_back(Objeto("Barra nutritiva", "Restaura salud"));
    inventario.push_back(Objeto("Palo", "Mejora estado emocional"));
    inventario.push_back(Objeto("Agua", "Restaura salud"));
    inventario.push_back(Objeto("Mascadero", "Mejora estado emocional"));
    inventario.push_back(Objeto("Leche", "Restaura salud"));
    inventario.push_back(Objeto("Cama", "Mejora estado emocional"));
}

void Tienda::mostrarInventario() const {
    for (const auto& obj : inventario) {
        std::cout << obj.obtenerNombre() << " - " << obj.obtenerEfecto() << std::endl;
    }
}

Objeto Tienda::obtenerObjeto(std::string nombre) const {
    for (const auto& obj : inventario) {
        if (obj.obtenerNombre() == nombre) {
            return obj;
        }
    }
    return Objeto("", "");
}
