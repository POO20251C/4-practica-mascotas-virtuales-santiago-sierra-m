#include <iostream>
#include <map>
#include <memory>
#include "Usuario.h"
#include "Mascota.h"
#include "Objeto.h"
#include "Habilidad.h"

void mostrarMenu() {
    std::cout << "\n--- PixelPets ---\n";
    std::cout << "1. Registrar nuevo usuario\n";
    std::cout << "2. Adoptar nueva mascota\n";
    std::cout << "3. Brindar objeto a una mascota\n";
    std::cout << "4. Ensenar habilidad a una mascota\n";
    std::cout << "5. Aumentar experiencia de una mascota\n";
    std::cout << "6. Consultar historial de una mascota\n";
    std::cout << "7. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    std::map<std::string, Usuario> usuarios;
    std::vector<Objeto> tienda = {
        Objeto("Snack", "Aumenta energia"),
        Objeto("Juguete", "Mejora estado emocional"),
        Objeto("Pocion", "Cura enfermedad"),
        Objeto("Vitaminas", "Fortalece salud"),
        Objeto("Pelota", "Aumenta felicidad"),
        Objeto("Libro de trucos", "Ayuda a aprender habilidades"),
        Objeto("Agua magica", "Cura completamente"),
        Objeto("Galleta", "Pequeno aumento de energia")
    };

    std::vector<Habilidad> habilidadesDisponibles = {
        Habilidad("Bailar", 5),
        Habilidad("Buscar objetos", 10),
        Habilidad("Comunicarse con emojis", 15)
    };

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombreUsuario;
                std::cout << "Ingrese nombre de usuario: ";
                std::cin >> nombreUsuario;


                if (usuarios.find(nombreUsuario) != usuarios.end()) {
                    std::cout << "Error: Usuario ya registrado.\n";
                } else {
                    usuarios[nombreUsuario] = Usuario(nombreUsuario);
                    std::cout << "Usuario registrado con exito.\n";
                }
                break;
            }

            case 2: {  //
                std::string nombreUsuario, nombreMascota;
                int edadMascota;
                std::cout << "Ingrese nombre de usuario: ";
                std::cin >> nombreUsuario;

                if (usuarios.find(nombreUsuario) != usuarios.end()) {
                    std::cout << "Ingrese nombre de la mascota: ";
                    std::cin >> nombreMascota;


                    if (usuarios[nombreUsuario].obtenerMascota(nombreMascota)) {
                        std::cout << "Error: La mascota ya existe para este usuario.";
                    } else {
                        std::cout << "Ingrese edad de la mascota: ";
                        std::cin >> edadMascota;
                        usuarios[nombreUsuario].adoptarMascota(std::make_shared<Mascota>(nombreMascota, edadMascota));
                        std::cout << "Mascota adoptada con exito.";
                    }
                } else {
                    std::cout << "Usuario no encontrado.\n";
                }
                break;
            }

            case 3: {
                std::string nombreUsuario, nombreMascota;
                int objIndex;
                std::cout << "Ingrese nombre de usuario: ";
                std::cin >> nombreUsuario;
                if (usuarios.find(nombreUsuario) != usuarios.end()) {
                    std::cout << "Ingrese nombre de la mascota: ";
                    std::cin >> nombreMascota;
                    auto mascota = usuarios[nombreUsuario].obtenerMascota(nombreMascota);
                    if (mascota) {
                        std::cout << "Seleccione un objeto:\n";
                        for (size_t i = 0; i < tienda.size(); ++i) {
                            std::cout << i + 1 << ". " << tienda[i].obtenerNombre() << " - " << tienda[i].obtenerEfecto() << "\n";
                        }
                        std::cin >> objIndex;
                        if (objIndex > 0 && objIndex <= tienda.size()) {
                            mascota->recibirObjeto(tienda[objIndex - 1]);
                            std::cout << "Objeto brindado con exito.\n";
                        } else {
                            std::cout << "Opcion invalida.\n";
                        }
                    } else {
                        std::cout << "Mascota no encontrada.\n";
                    }
                } else {
                    std::cout << "Usuario no encontrado.\n";
                }
                break;
            }
            case 4: {  // Enseñar habilidad a una mascota
                std::string nombreUsuario, nombreMascota;
                int habIndex;
                std::cout << "Ingrese nombre de usuario: ";
                std::cin >> nombreUsuario;

                if (usuarios.find(nombreUsuario) != usuarios.end()) {
                    std::cout << "Ingrese nombre de la mascota: ";
                    std::cin >> nombreMascota;
                    auto mascota = usuarios[nombreUsuario].obtenerMascota(nombreMascota);

                    if (mascota) {
                        std::cout << "Seleccione una habilidad para ensenar:\n";
                        for (size_t i = 0; i < habilidadesDisponibles.size(); ++i) {
                            std::cout << i + 1 << ". " << habilidadesDisponibles[i].obtenerNombre()
                                      << " (Nivel requerido: " << habilidadesDisponibles[i].obtenerNivelRequerido() << ")\n";
                        }
                        std::cin >> habIndex;

                        if (habIndex > 0 && habIndex <= habilidadesDisponibles.size()) {
                            Habilidad habilidad = habilidadesDisponibles[habIndex - 1];

                            // Verificar si la mascota tiene suficiente experiencia
                            if (mascota->obtenerExperiencia() >= habilidad.obtenerNivelRequerido()) {
                                mascota->aprenderHabilidad(habilidad);
                                std::cout << "Habilidad aprendida con exito.\n";
                            } else {
                                std::cout << "Error: La mascota no tiene suficiente experiencia para aprender esta habilidad.\n";
                            }
                        } else {
                            std::cout << "Opcion invalida.\n";
                        }
                    } else {
                        std::cout << "Mascota no encontrada.\n";
                    }
                } else {
                    std::cout << "Usuario no encontrado.\n";
                }
                break;
            }

            case 5: {
                std::string nombreUsuario, nombreMascota;
                int exp;
                std::cout << "Ingrese nombre de usuario: ";
                std::cin >> nombreUsuario;
                if (usuarios.find(nombreUsuario) != usuarios.end()) {
                    std::cout << "Ingrese nombre de la mascota: ";
                    std::cin >> nombreMascota;
                    auto mascota = usuarios[nombreUsuario].obtenerMascota(nombreMascota);
                    if (mascota) {
                        std::cout << "Ingrese la cantidad de experiencia a aumentar: ";
                        std::cin >> exp;
                        mascota->aumentarExperiencia(exp);
                        std::cout << "Experiencia aumentada con exito.\n";
                    } else {
                        std::cout << "Mascota no encontrada.\n";
                    }
                } else {
                    std::cout << "Usuario no encontrado.\n";
                }
                break;
            }
            case 6: {
                std::string nombreUsuario, nombreMascota;
                std::cout << "Ingrese nombre de usuario: ";
                std::cin >> nombreUsuario;
                if (usuarios.find(nombreUsuario) != usuarios.end()) {
                    std::cout << "Ingrese nombre de la mascota: ";
                    std::cin >> nombreMascota;
                    auto mascota = usuarios[nombreUsuario].obtenerMascota(nombreMascota);
                    if (mascota) {
                        mascota->consultarHistorial();
                    } else {
                        std::cout << "Mascota no encontrada.\n";
                    }
                } else {
                    std::cout << "Usuario no encontrado.\n";
                }
                break;
            }
            case 7:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 7);

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.