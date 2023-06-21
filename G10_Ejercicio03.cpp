#include <iostream> 
using namespace std; 
 
class Persona { 
private: 
    string nombre; 
    int edad; 
    string direccion; 
 
public: 
 
    Persona(string _nombre, int _edad, string _direccion) { 
        nombre = _nombre; 
        edad = _edad; 
        direccion = _direccion; 
    } 
 

    void setNombre(string _nombre) { 
        nombre = _nombre; 
    } 
 
    void setEdad(int _edad) { 
        edad = _edad; 
    } 
 
    void setDireccion(string _direccion) { 
        direccion = _direccion; 
    } 
 
    string getNombre() { 
        return nombre; 
    } 
 
    int getEdad() { 
        return edad; 
    } 
 
    string getDireccion() { 
        return direccion; 
    } 
}; 
 
int main() { 
     
 
    return 0; 
} 
