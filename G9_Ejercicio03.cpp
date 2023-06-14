#include <iostream>
using namespace std; 

template <typename T, int capacidadMaxima>
class Contenedor {
private:
    T elementos[capacidadMaxima];
    int tamano;

public:
    Contenedor() : tamano(0) {}

    void agregarElemento(const T& elemento) {
        if (tamano < capacidadMaxima) {
            elementos[tamano] = elemento;
            tamano++;
        } else {
            cout << "Error: el contenedor está lleno." << endl;
        }
    }

    void imprimirElementos() const {
        for (int i = 0; i < tamano; i++) {
            cout << elementos[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Contenedor<int, 5> contenedorInt;
    contenedorInt.agregarElemento(1);
    contenedorInt.agregarElemento(2);
    contenedorInt.agregarElemento(3);
    contenedorInt.agregarElemento(4);
    contenedorInt.agregarElemento(5);
    contenedorInt.imprimirElementos();
    
    Contenedor<string, 3> contenedorString;
    contenedorString.agregarElemento("Universidad");
    contenedorString.agregarElemento("Catolica");
    contenedorString.imprimirElementos();

    return 0;
}
