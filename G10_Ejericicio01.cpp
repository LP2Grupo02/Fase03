#include <iostream>
#include <fstream>

struct Persona {
    char nombre[20];
    int edad;
};

int main() {
    std::fstream archivo("datos.bin", std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    // Escribir datos en el archivo
    Persona persona1 = { "Juan", 25 };
    Persona persona2 = { "María", 30 };

    archivo.write(reinterpret_cast<char*>(&persona1), sizeof(Persona));
    archivo.write(reinterpret_cast<char*>(&persona2), sizeof(Persona));

    // Leer datos del archivo
    archivo.seekg(0, std::ios::beg); // Mover el puntero al inicio del archivo

    Persona personaLeida;
    while (archivo.read(reinterpret_cast<char*>(&personaLeida), sizeof(Persona))) {
        std::cout << "Nombre: " << personaLeida.nombre << ", Edad: " << personaLeida.edad << std::endl;
    }

    archivo.close();
    return 0;
}
