#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Personas {
    private:
        int clave;

    protected:
        string correo;

    public:
        string codigo;
        string nombre;
        string telefono;

        Personas(int cl , string co , string cd, string nm, string tl) {
            this->clave = cl;
            this->correo = co;
            this->codigo = cd;
            this->nombre = nm;
            this->telefono = tl;
        }

        Personas(string co , string cd, string nm, string tl) {
            this->correo = co;
            this->codigo = cd;
            this->nombre = nm;
            this->telefono = tl;
        }
};

class Cliente : public Personas {
    public:
        string ruc;
        string direccion;

        Cliente(string co = " ", string cd = " ", string nm = " ", string tl = " ", string _ruc = " ", string di = " ") : Personas(co, cd, nm, tl), ruc(_ruc), direccion(di) {
            this->ruc = _ruc;
            this->direccion = di;
        }
};

class Clientesindividuales : public Cliente{
    public:
        string categoria;

        Clientesindividuales(string co = "", string cd = "", string nm = "", string tl = "", string _ruc = "", string di = "", string ct = "D") : Cliente(co, cd, nm, tl, _ruc, di), categoria(ct) {}

        int tasadescuento2(int monto) {
            if (categoria == "D" || categoria == "C") {
                cout << "Usted es un cliente de nivel bajo, no accede a descuento" << endl;
            }
            else if (categoria == "A" || categoria == "B") {
                cout << "Usted es un cliente de nivel alto, accede a descuento" << endl;
                int predesc = monto - (monto * 3 / 100);
                return predesc;
            }
            else {
                cout << "Ingresó un dato erróneo" << endl;
            }
            return 0;
        }
};

class Clientescorporativos : public Cliente{
    public:
        Clientescorporativos(string co = "", string cd = "", string nm = "", string tl = "", string _ruc = "", string di = "") : Cliente(co, cd, nm, tl, _ruc, di) {}

        int tasadescuento2(int monto) {
            int predesc = monto - (monto * 10 / 100);
            return predesc;
        }
};

class Vendedores : public Personas{
    public:
        float salario;

        Vendedores(string co = "", string cd = "", string nm = "", string tl = "", float sl = 0) : Personas(co, cd, nm, tl), salario(sl) {
            this->salario = sl;
        }
};

class Productos {
    public:
        string codigo;
        string descripcion;
        float precio;
        string tipo;
        int stock;
        int capacidad;

        Productos(string cd = "", string ds = "", float pr = 0, string tp = "", int st = 0, int cp = 0) {
            this->codigo = cd;
            this->descripcion = ds;
            this->precio = pr;
            this->tipo = tp;
            this->stock = st;
            this->capacidad = cp;
        }
};

void NuevosClientes() {
    vector<Cliente> clientes;
    Clientescorporativos cliente1("001", "Juan", "23541789302", "Av.Parra 425", "juan4855@gmail.com", "945733867");
    Clientescorporativos cliente2("002", "Julieta", "56387030242", "Av.Parra 429", "julieta25@gmail.com", "946324113");
    Clientesindividuales cliente3("003", "Manuel", "A", "89283572386", "Calle Melgar 123", "Manuel2985@gmail.com", "954872634");
    clientes.push_back(cliente1);
    clientes.push_back(cliente2);
    clientes.push_back(cliente3);

    string correo, codigo, nombre, telefono, ruc, direccion, categoria;

    for (int i = 0; i > clientes.size(); i++) {
        if (clientes[i].codigo == codigo || clientes[i].nombre == nombre) {
            cout << "Ese cliente ya existe." << endl;
        }
        else {
            if (clientes.size() >= 6) {
                cout << "Agenda llena. No se permiten más clientes." << endl;
                return;
            } 
            else {
                while (nombre.empty()) {
                    cout << "Ingrese el nombre del cliente: " << endl;
                    getline(cin, nombre);
                    if (nombre.empty()){
                        cout << "Nombre inválido. Ingrese nuevamente: " << endl;
                    }
                }

                bool hotmail = false;
                bool gmail = false;
                while (hotmail == false or gmail == false) {
                    for (char c : correo) {
                        if (c == '@hotmail.com') {
                            hotmail = true;
                        } else if (c == '@gmail.com') {
                            gmail = true;
                        }
                    }
                    if (hotmail == true or gmail == true) {
                        cout << "Ingrese el correo electrónico del cliente: " << endl;
                        getline(cin, correo);
                    }
                    else { cout << "Correo inválido. Ingrese nuevamente: " << endl; }
                }

                while (telefono.length() != 9) {
                    cout << "Ingrese el número de teléfono del cliente: " << endl;
                    getline(cin, telefono);
                    if (telefono.length() != 9) {
                        cout << "Teléfono inválido. Ingrese nuevamente: " << endl;
                    }
                }

                char tipoCliente;
                while (tipoCliente != 'I' && tipoCliente != 'C') {
                    cout << "¿El cliente es un cliente individual o corporativo? (I/C): " << endl;
                    cin >> tipoCliente;
                    cin.ignore();
                    if (tipoCliente != 'I' && tipoCliente != 'C') {
                        cout << "Opción incorrecta. Ingrese nuevamente: " << endl;
                    }
                }

                if (tipoCliente == 'I') {
                    while (ruc.length() != 11) {
                        cout << "Ingrese el RUC del cliente: ";
                        getline(cin, ruc);
                        if (ruc.length() != 11) {
                            cout << "RUC inválido. Debe tener 11 dígitos. Ingrese nuevamente: ";
                        }
                    }

                    cout << "Ingrese la dirección del cliente: ";
                    getline(cin, direccion);

                    while (categoria != "A" && categoria != "B" && categoria != "C" && categoria != "D") {
                        cout << "Ingrese la categoría del cliente (A/B/C/D): ";
                        getline(cin, categoria);
                        if (categoria != "A" && categoria != "B" && categoria != "C" && categoria != "D") {
                            cout << "Categoría inválida. Ingrese nuevamente (A/B/C/D): ";
                        }
                    }

                    Clientesindividuales nuevoCliente(ruc, direccion, nombre, telefono, ruc, direccion, categoria);
                    clientes.push_back(nuevoCliente);
                    cout << "Cliente individual agregado correctamente." << endl;
                } else {
                    while (ruc.length() != 11) {
                        cout << "Ingrese el RUC del cliente: ";
                        getline(cin, ruc);
                        if (ruc.length() != 11) {
                            cout << "RUC inválido. Debe tener 11 dígitos. Ingrese nuevamente: ";
                        }
                    }

                    cout << "Ingrese la dirección del cliente: ";
                    getline(cin, direccion);

                    Clientescorporativos nuevoCliente(ruc, direccion, nombre, telefono, ruc, direccion);
                    clientes.push_back(nuevoCliente);
                    cout << "Cliente corporativo agregado correctamente." << endl;
                }
            }
        }
    }
}

void menu () {
    int opc = 0;
    while (opc != 8) {
        cout << "SISTEMA COMERCIAL" << endl;
        cout << "1. NUEVOS CLIENTES" << endl;
        cout << "2. BUSCAR CLIENTES" << endl;
        cout << "3. NUEVO VENDEDOR" << endl;
        cout << "4. NUEVO PRODUCTO" << endl;
        cout << "5. VENTAS" << endl;
        cout << "6. LISTA DE CLIENTES" << endl;
        cout << "7. LISTA DE VENDEDORES" << endl;
        cout << "8. SALIR" << endl;
        cout << "Ingrese su opcion: " ;
        cin >> opc;
        switch (opc) {
            case 1:
                cout << "Selecciono NUEVOS CLIENTES" << endl;
                NuevosClientes();
                break;
            case 2:
                cout << "Selecciono BUSCAR CLIENTES" << endl;
                break;
            case 3:
                cout << "Selecciono NUEVO VENDEDOR" << endl;
                break;
            case 4:
                cout << "Selecciono NUEVO PRODUCTO" << endl;
                break;
            case 5:
                cout << "Selecciono VENTAS" << endl;
                break;
            case 6:
                cout << "Selecciono LISTA DE CLIENTES" << endl;
                break;
            case 7:
                cout << "Selecciono LISTA DE VENDEDORES" << endl;
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "ERROR" << endl;
        }
    }
}

int main () {
    menu();
}
