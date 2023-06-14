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

        template <class U>
        
        class Recipiente {
            private:
                vector<U> elementos;
            public:
                void agregarElemento(const U& elemento) {
                    elementos.push_back(elemento);
                }

                void imprimirElementos() const {
                    cout << "Elementos en el recipiente:" << endl;
                    for (const auto& elemento : elementos) {
                        cout << "- " << elemento << endl;
                    }
                }
        };
};

int main() {
    SistemaGestionRutas<string> sistema;

    RutaEntrega<string> ruta1("Ciudad A");
    ruta1.agregarPaquete("Paquete 1");
    ruta1.agregarPaquete("Paquete 2");
    
    RutaEntrega<string> ruta2("Ciudad B");
    ruta2.agregarPaquete("Paquete 3");
    
    RutaEntrega<string> ruta3("Ciudad C");
    ruta3.agregarPaquete(to_string(4));
    ruta3.agregarPaquete(to_string(5));
    
    sistema.agregarRuta(ruta1);
    sistema.agregarRuta(ruta2);
    sistema.agregarRuta(ruta3);
    sistema.ordenarRutas();
    sistema.imprimirRutas();
    
    SistemaGestionRutas<int>::Recipiente<int> recipiente;
    
    recipiente.agregarElemento(10);
    recipiente.agregarElemento(20);
    recipiente.agregarElemento(30);
    recipiente.imprimirElementos();
    
    return 0;
}
