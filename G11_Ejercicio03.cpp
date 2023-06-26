#include <iostream>
#include <map>
#include <string>
using namespace std;
// se crea un struct
struct datos {
    string numero;
    string correo;
};
string nombre;
string numero;
string correo;
map<string, datos> agenda;  // aqui se declara el mapa de la agenda de contactos
// funcion para buscar contactos en el mapa
void buscarcontacto(string u) {
    if (agenda.find(u) != agenda.end()) {
        cout << "Contacto encontrado:" << endl;
        cout << "Nombre: " << u << endl;
        cout << "Numero: " << agenda[u].numero << endl;
        cout << "Correo: " << agenda[u].correo << endl;
    }
    else {
        cout << "Contacto inexistente";
    }
}
int main(){
    int i = 0;                
    string newnumero;
    string newcorreo;
    // agregando contactos a la agenda
    nombre = "gerardo";
    numero = "965782312";
    correo = "gerardo123@gmail.com";
    agenda[nombre] = { numero, correo };

    nombre = "laura";
    numero = "943273418";
    correo = "laurauwu@gmail.com";
    agenda[nombre] = { numero, correo };
// creamos un while para repetir el menu
    while (i != 5) {
        cout << "******MENU******" << endl;;
        cout << "ELIJA UNA DE LAS SIGUIENTES OPCIONES" << endl;
        cout << "1.- Agregar un nuevo contacto a la agenda" << endl;
        cout << "2.- Buscar un contacto por su nombre" << endl;
        cout << "3.- Actualizar informacion de un contacto existente" << endl;
        cout << "4.- Mostrar lista de contactos" << endl;
        cout << "5.- SALIR" << endl;
        cin >> i;
        switch (i) {
            case 1:
                // aqui se agregara u nuevo contacto por teclado
                cout << "Ingrese el nombre del contacto: ";
                cin >> nombre;
                cout << "Ingrese el numero de telefono: ";
                cin >> numero;
                cout << "Ingrese el correo:";
                cin >> correo;
                agenda[nombre] = { numero, correo };
                break;
            case 2:
                cout << "Ingrese el nombre del contacto a encontrar: ";
                cin >> nombre;
                buscarcontacto(nombre);
                break;
            case 3:
                //aqui se modificara un contacto 
                cout << "Ingrese el nombre del contacto a modificar: ";
                cin >> nombre;
                cout << "Ingrese el nuevo numero de telefono: ";
                cin >> newnumero;
                cout << "Ingrese el nuevo correo:";
                cin >> newcorreo;
                if (agenda.find(nombre) != agenda.end()) {
                    agenda[nombre].numero = newnumero;
                    agenda[nombre].correo = newcorreo;
                }
                break;
            case 4:
                //mostrar agenda
                for (const auto& x : agenda) {
                    cout << x.first << ", ";
                    cout << agenda[x.first].numero << ", ";
                    cout << agenda[x.first].correo << endl;
                }
                break;
            default:
                cout << "No ingreso una opcion valida";
        }
    }   
}