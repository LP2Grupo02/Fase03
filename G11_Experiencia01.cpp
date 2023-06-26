#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numeros;
    int n, cnt;
    int suma = 0;
    int i = 0;

    cout << "Ingrese la cantidad de números a ingresar: " << endl;
    cin >> cnt;

    cout << "Ingrese los números:" << endl;
    while (i < cnt) {
        cin >> n;
        numeros.push_back(n);
        i++;
    }

    for (int j = 0; j < cnt; j++) {
        suma = suma + numeros[j];
    }

    int my = *max_element(numeros.begin(), numeros.end());
    int mn = *min_element(numeros.begin(), numeros.end());

    sort(numeros.begin(), numeros.end());

    cout << "         Resultados         " << endl;
    cout << "----------------------------" << endl;
    cout << "Suma: " << suma << endl;
    cout << "Número máximo: " << my << endl;
    cout << "Número mínimo: " << mn << endl;
    cout << "Números ordenados de forma ascendente: " << endl;
    for (int x : numeros) {
        cout << x << endl;
    }

    numeros.erase(remove_if(numeros.begin(), numeros.end(), [](int num) { return num % 2 == 0; }), numeros.end());

    cout << "Vector sin los números pares: " << endl;
    for (int y : numeros) {
        cout << y << endl;
    }

    cout << "El programa ha finalizado correctamente." << endl;

    return 0;
}

