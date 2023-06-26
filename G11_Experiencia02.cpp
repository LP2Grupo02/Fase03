#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<string> palabras;
    int cont;
    string n, pal;
    int i = 0;
    cout << "Ingrese la cantidad de palabras a ingresar: ";
    cin >> cont;
    while (i < cont) {
        cout << "Ingrese una palabra:" << endl;
        cin >> n;
        palabras.push_back(n);
        i++;
    }
    cout << "Ordenando las palabras en orden alfabetico."<<endl;
    palabras.sort();
    cout << "Ingrese la palabra a buscar: ";
    cin >> pal;

    int cant = count(palabras.begin(), palabras.end(), pal);

    cout << "La cantidad de veces que se muestra la palabra " << pal << " es: " << cant << endl;

    // Convirtiendo a mayusculas
    transform(palabras.begin(), palabras.end(), palabras.begin(), [](string word) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        return word;
    });
    cout<<"Convirtiendo las palabras a mayusculas. \n";
    cout << "Lista resultante despu�s de aplicar los algoritmos:" << endl;
    for (const string& word : palabras) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}


