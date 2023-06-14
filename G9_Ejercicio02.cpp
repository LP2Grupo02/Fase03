#include <iostream>
#include <vector>

using namespace std;

// Clase de vehículo
class Vehiculo {
    string nombre_;
public:
    Vehiculo(const string& nombre) : nombre_(nombre) {}
    string getNombre() const {
        return nombre_;
    }
};
// Clase de entrega
template <typename T>
class Entrega {
    vector<T> vehiculos_;
public:
    void asignarVehiculo(const T& vehiculo) {
        vehiculos_.push_back(vehiculo);
    }
    void mostrarVehiculos() const {
        cout << "Vehículos asignados a la entrega:" << endl;
        for (const auto& vehiculo : vehiculos_) {
            cout << vehiculo.getNombre() << endl;
        }
    }
};
int main() {
    // Crear una entrega de vehículos
    Entrega<Vehiculo> entrega;
    // Asignar vehículos a la entrega
    Vehiculo vehiculo1("Camión");
    entrega.asignarVehiculo(vehiculo1);
    Vehiculo vehiculo2("Furgoneta");
    entrega.asignarVehiculo(vehiculo2);
    Vehiculo vehiculo3("Moto");
    entrega.asignarVehiculo(vehiculo3);
    // Mostrar los vehículos asignados a la entrega
    entrega.mostrarVehiculos();
    return 0;
}

