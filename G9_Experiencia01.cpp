#include <iostream>
#include <string>

using namespace std;

template <typename T>

void gestionRutasLlegada(T distancia) {
    float mtH = 0.009;
    float tiempoEntrega = distancia * mtH;

    cout << "=======================================" << endl;
    cout << "Distancia a recorrer: " << distancia << " m." << endl;
    cout << "Tiempo estimado de entrega: " << tiempoEntrega << " minutos." << endl;
}

int numeroPedido = 1;

int main() {
    int dst1;
    cout << "Ingrese la distancia a recorrer (metros): ";
    cin >> dst1;
    cout << "Pedido Nº" << numeroPedido << endl;

    gestionRutasLlegada<int>(dst1);
    
    numeroPedido++;

    float dst2;
    cout << "Ingrese la distancia a recorrer (metros): ";
    cin >> dst2;
    cout << "Pedido Nº" << numeroPedido << endl;
    gestionRutasLlegada<float>(dst2);

    numeroPedido++;

    return 0;
}
