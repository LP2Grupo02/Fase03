#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Producto {
    private:
        string nombre;
        double precio;
        int cantidad;

    public:
        Producto(const string& nombre, double precio, int cantidad) : nombre(nombre), precio(precio), cantidad(cantidad) {}

        string getNombre() const { return nombre; }
        double getPrecio() const { return precio; }
        int getCantidad() const { return cantidad; }

        void setPrecio(double nuevoPrecio) { precio = nuevoPrecio; }
        void setCantidad(int nuevaCantidad) { cantidad = nuevaCantidad; }
        void mostrar() const {
            cout << "Nombre: " << nombre << endl << "Precio: " << precio << endl << "Cantidad: " << cantidad << endl;
        }
};

class Inventario {
    private:
        vector<Producto> productos;

    public:
        void agregarProducto(const Producto& producto) {
            productos.push_back(producto);
            escribirRegistro(producto);
        }

        void actualizarProducto(const string& nombre, double nuevoPrecio, int nuevaCantidad) {
            int indiceProducto = buscarProducto(nombre);
            if (indiceProducto != -1) {
                productos[indiceProducto].setPrecio(nuevoPrecio);
                productos[indiceProducto].setCantidad(nuevaCantidad);
                actualizarRegistro(productos[indiceProducto]);
            }
            else {
                cout << "\n\tEl producto no existe en el inventario." << endl;
            }
        }

        void venderProducto(const string& nombre, int cantidad) {
            int indiceProducto = buscarProducto(nombre);
            if (indiceProducto != -1) {
                int cantidadActual = productos[indiceProducto].getCantidad();
                if (cantidad <= cantidadActual) {
                    productos[indiceProducto].setCantidad(cantidadActual - cantidad);
                    actualizarRegistro(productos[indiceProducto]);
                }
                else {
                    cout << "\n\tNo hay suficiente cantidad de producto disponible." << endl;
                }
            }
            else {
                cout << "\n\tEl producto no existe en el inventario." << endl;
            }
        }

        void generarInforme() const {
            vector<string> nombresMostrados;
            for (const auto& producto : productos) {
                bool encontrado = false;
                for (const auto& nombre : nombresMostrados) {
                    if (producto.getNombre() == nombre) {
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    producto.mostrar();
                    nombresMostrados.push_back(producto.getNombre());
                }
            }
        }

        int buscarProducto(const string& nombre) const {
            for (int i = 0; i < productos.size(); ++i) {
                if (productos[i].getNombre() == nombre) {
                    cout << "\nEl producto existe en el inventario." << endl;
                    productos[i].mostrar();
                    return i;
                }
            }
            cout << "\nEl producto no existe en el inventario." << endl;
            return -1;
        }

        void escribirRegistro(const Producto& producto) {
            ofstream archivo("inventario.csv", ios::app);
            archivo << producto.getNombre() << "," << producto.getPrecio() << "," << producto.getCantidad() << endl;
            archivo.close();
        }

        void actualizarRegistro(const Producto& producto) {
            ifstream aLectura("inventario.csv");
            ofstream aEscritura("temp.csv");
            string linea;
            while (getline(aLectura, linea)) {
                string nombre, precio, cantidad;
                size_t commaPos1 = linea.find(',');
                size_t commaPos2 = linea.find(',', commaPos1 + 1);
                nombre = linea.substr(0, commaPos1);
                precio = linea.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
                cantidad = linea.substr(commaPos2 + 1);
                if (nombre == producto.getNombre()) {
                    aEscritura << producto.getNombre() << "," << producto.getPrecio() << "," << producto.getCantidad() << endl;
                }
                else {
                    aEscritura << linea << endl;
                }
            }
            aLectura.close();
            aEscritura.close();
            remove("inventario.csv");
            rename("temp.csv", "inventario.csv");
        }

        void leerRegistros() {
            ifstream archivo("inventario.csv");
            string linea;
            while (getline(archivo, linea)) {
                string nombre, precio, cantidad;
                size_t commaPos1 = linea.find(',');
                size_t commaPos2 = linea.find(',', commaPos1 + 1);
                nombre = linea.substr(0, commaPos1);
                precio = linea.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
                cantidad = linea.substr(commaPos2 + 1);
                double precioProducto = stod(precio);
                int cantidadProducto = stoi(cantidad);
                Producto producto(nombre, precioProducto, cantidadProducto);
                productos.push_back(producto);
            }
            archivo.close();
        }
};

int main() {
    Inventario inventario;
    inventario.leerRegistros();
    inventario.agregarProducto(Producto("Calculadora", 24.5, 8));
    inventario.agregarProducto(Producto("Cuaderno", 5.9, 1));
    inventario.actualizarProducto("Calculadora", 28.3, 10);
    inventario.venderProducto("Calculadora", 3);
    cout << "                        INFORME:                        " << endl;
    inventario.generarInforme();
    inventario.buscarProducto("Lapicero");
    return 0;
}
