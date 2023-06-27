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
            this->correo = co;
            this->codigo = cd;
            this->nombre = nm;
            this->telefono = tl;
            this->ruc = _ruc;
            this->direccion = di;
        }
};

class Clientesindividuales : public Cliente{
    public:
        string categoria;
        Clientesindividuales(string co = "",  string cd = "", string nm = "", string tl = "", string _ruc = "", string di = "", string ct = "D") : Cliente(co, cd, nm, tl, _ruc, di), categoria(ct) { }

        int tasadescuento2(string categoria,int monto) {
            if (categoria == "D" and categoria == "C") {
                cout << "Usted es un cliente de nivel bajo, no accede a descuento" << endl;
            }
            else if (categoria == "A" and categoria == "B") {
                cout << "Usted es un cliente de nivel alto, accede a descuento" << endl;
                int predesc = monto - (monto * (3 / 100));
                return predesc;
            }
            else {
                cout << "Ingreso un dato erroneo" << endl;
            }
        }
};

class Clientescorporativos : public Cliente{
    public:
        Clientescorporativos(string co = "",  string cd = "", string nm = "", string tl = "", string _ruc = "", string di = "") : Cliente(co, cd, nm, tl, _ruc, di) { }
        
        int tasadescuento2(int monto) {
            int predesc = monto - (monto * (10 / 100));
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

void NuevosClientes () {
    int op = 0;
    while (op =! 3){
        cout << "       MENU       " << endl;
        cout << "1. Corporativo." << endl;
        cout << "2. Individual." << endl;
        cout << "3. SALIR." << endl;
        cout << "Ingrese la opción que desea: " << endl;
        cin >> op;
        switch (op) {
            case 1:
                string correo;
                for (int i = 0; i > len(correo); i++) {
                    while ("@gmail.com"  correo) {

                    }
                }
                string codigo;
                string nombre;
                string telefono;
                string categoria;
                string ruc;
                string direccion;
                break;

            case 2:
                break;

            case 3:
                cout << "Redirigiendo al sistema comercial...";
                break;

            default:
                break;
        }
    }
}

int main()
{
    vector <Clientescorporativos> cliCopr;
    vector <Clientesindividuales> cliIndi;
    Clientescorporativos cliente1("001", "Juan", "23541789302", "Av.Parra 425", "juan4855@gmail.com", "945733867");
    Clientescorporativos cliente2("002", "Julieta", "56387030242", "Av.Parra 429", "julieta25@gmail.com", "946324113");
    Clientesindividuales cliente3("003", "Manuel", "A", "89283572386", "Calle Melgar 123", "Manuel2985@gmail.com", "954872634");
    cliCopr.push_back(cliente1);
    cliCopr.push_back(cliente2);
    cliIndi.push_back(cliente3);
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
        cout << "Ingrese su opcion: ";
        cin >> opc;
        switch (opc) {
        case 1:
            cout << "Selecciono NUEVOS CLIENTES" << endl;
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
