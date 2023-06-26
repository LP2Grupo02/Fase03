#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque<char> caracteres;
    string cd;
    cout << "Ingrese una cadena de caracteres: ";
    getline(cin, cd);                               // Se utiliza getline para poder leer espacios en blanco. 

    for (char c : cd) {
        caracteres.push_back(c);
    }
    
    cout << "Mostrando los caracteres uno por uno: " << endl;
    for (auto i = caracteres.begin(); i != caracteres.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    cout << "Reemplazando todas las vocales en el contenedor con el carácter * " << endl;
    for (auto i = caracteres.begin(); i != caracteres.end(); ++i) {
        if ((tolower(*i) == 'a') or (tolower(*i) == 'e') or (tolower(*i) == 'i') or (tolower(*i) == 'o') or (tolower(*i) == 'u')) {
            *i = '*';
        }
    }
    for (char c : caracteres) {
        cout << c;
    }
    cout << endl;

    // Funciones miembro de la clase deque: rbegin() y rend() son utilizados en combinación para recorrer un contenedor en orden inverso
    cout << "Utilizando el iterador inverso:  " << endl;
    for (auto i = caracteres.rbegin(); i != caracteres.rend(); ++i) { // rbegin() devuelve un iterador que apunta al último elemento del contenedor
        cout << *i << " ";                          // rend() devuelve un iterador que apunta a una posición "ficticia" antes del primer elemento del contenedor
    }
    cout << endl;

    cout << "Cadena resultante: ";
    for (char c : caracteres) {
        cout << c;
    }
    cout << endl;

    return 0;
}

