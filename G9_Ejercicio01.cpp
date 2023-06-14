#include <iostream>
#include <vector>

using namespace std;

template <class T>
class RutaEntrega {
    private:
        string destino;
        vector<T> paquetes;

    public:
        RutaEntrega(string _destino) : destino(_destino) {}

        void agregarPaquete(T paquete) {
            paquetes.push_back(paquete);
        }

        void imprimirRuta() const {
            cout << "Destino: " << destino << endl;
            cout << "Paquetes:" << endl;
            for (const auto& paquete : paquetes) {
                cout << "- " << paquete << endl;
            }
        }

        void ordenarPaquetes() {
            for (size_t i = 0; i < paquetes.size() - 1; ++i) {
                size_t minIndex = i;
                for (size_t j = i + 1; j < paquetes.size(); ++j) {
                    if (paquetes[j] < paquetes[minIndex]) {
                        minIndex = j;
                    }
                }
                if (minIndex != i) {
                    swap(paquetes[i], paquetes[minIndex]);
                }
            }
        }
};

template <typename T>
class SistemaGestionRutas {
    private:
        vector<RutaEntrega<T>> rutas;

    public:
        void agregarRuta(const RutaEntrega<T>& ruta) {
            rutas.push_back(ruta);
        }

        void imprimirRutas() const {
            cout << "Rutas de entrega:" << endl;
            for (const auto& ruta : rutas) {
                ruta.imprimirRuta();
                cout << endl;
            }
        }

        void ordenarRutas() {
            for (auto& ruta : rutas) {
                ruta.ordenarPaquetes();
            }
        }
        vector<RutaEntrega<T>> getRutas() const {
            return rutas;
        }
};

template <class X> void imprimirOrdenamiento(const vector<RutaEntrega<X>>& rutas) {
    vector<RutaEntrega<X>> copiaRutas = rutas;
    for (auto& ruta : copiaRutas) {
        ruta.ordenarPaquetes();
    }

    cout << "Ordenamiento de las rutas y paquetes:" << endl;
    for (const auto& ruta : copiaRutas) {
        ruta.imprimirRuta();
        cout << endl;
    }
}

int main() {
    SistemaGestionRutas<string> sistema;

    RutaEntrega<string> r1("A");
    r1.agregarPaquete("P1");
    r1.agregarPaquete("P2");

    RutaEntrega<string> r2("B");
    r2.agregarPaquete("P3");

    RutaEntrega<string> r3("C");
    r3.agregarPaquete("P4");
    r3.agregarPaquete("P5");

    sistema.agregarRuta(r1);
    sistema.agregarRuta(r2);
    sistema.agregarRuta(r3);
    sistema.ordenarRutas();
    sistema.imprimirRutas();

    imprimirOrdenamiento(sistema.getRutas());

    return 0;
}
