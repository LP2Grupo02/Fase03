#include <iostream> 
#include <fstream> 
#include <string> 
#include <boost/archive/binary_oarchive.hpp> 
#include <boost/archive/binary_iarchive.hpp> 
 
using namespace std; 
 
class Persona { 
public: 
    string nombre; 
    int edad; 
    string direccion; 
 
    Persona(const string& _nombre = "", int _edad = 0, const string& _direccion = "") 
        : nombre(_nombre), edad(_edad), direccion(_direccion) {} 
 
    void setNombre(const string& _nombre) { 
        nombre = _nombre; 
    } 
 
    string getNombre() const { 
        return nombre; 
    } 
 
    void setEdad(int _edad) { 
        edad = _edad; 
    } 
 
    int getEdad() const { 
        return edad; 
    } 
 
    void setDireccion(const string& _direccion) { 
        direccion = _direccion; 
    } 
 
    string getDireccion() const { 
        return direccion; 
    } 
 
    template <class Archive> 
    void serialize(Archive& ar, const unsigned int version) { 
        ar & nombre; 
        ar & edad; 
        ar & direccion; 
    } 
}; 
 
int main() { 
    Persona persona("Raul Romero", 20, "Av Mariscal Castilla 200"); 
 
    ofstream archivo("persona.bin", ios::binary); 
    boost::archive::binary_oarchive salidaArchivo(archivo); 
    salidaArchivo << persona; 
    archivo.close(); 
 
    ifstream archivoEntrada("persona.bin", ios::binary); 
    boost::archive::binary_iarchive entradaArchivo(archivoEntrada); 
    Persona personaDeserializada; 
    entradaArchivo >> personaDeserializada; 
    archivoEntrada.close(); 
 
    cout << "Nombre: " << personaDeserializada.getNombre() << endl; 
    cout << "Edad: " << personaDeserializada.getEdad() << endl; 
    cout << "Dirección: " << personaDeserializada.getDireccion() << endl; 
 
    return 0;
}
