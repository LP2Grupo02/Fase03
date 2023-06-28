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

    Personas(int cl, string co, string cd, string nm, string tl) {
        this->clave = cl;
        this->correo = co;
        this->codigo = cd;
        this->nombre = nm;
        this->telefono = tl;
    }

    Personas(string co, string cd, string nm, string tl) {
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

    friend void BuscarClientes();
};

class Clientesindividuales : public Cliente {
public:
    string categoria;

    Clientesindividuales(string co = "", string cd = "", string nm = "", string tl = "", string _ruc = "", string di = "", string ct = "D") : Cliente(co, cd, nm, tl, _ruc, di), categoria(ct) {}

    int tasadescuento2(int monto) {
        if (categoria == "D" or categoria == "C") {
            cout << "Usted es un cliente de nivel bajo, no accede a descuento" << endl;
        }
        else if (categoria == "A" or categoria == "B") {
            cout << "Usted es un cliente de nivel alto, accede a descuento" << endl;
            int predesc = monto - (monto * 3 / 100);
            return predesc;
        }
        else {
            cout << "Ingresó un dato erróneo" << endl;
        }
        return 0;
    }

    friend void MostrarClientes();
};

class Clientescorporativos : public Cliente {
public:
    Clientescorporativos(string co = "", string cd = "", string nm = "", string tl = "", string _ruc = "", string di = "") : Cliente(co, cd, nm, tl, _ruc, di) {}

    int tasadescuento2(int monto) {
        int predesc = monto - (monto * 10 / 100);
        return predesc;
    }

    friend void MostrarClientes();
};

class Vendedores : public Personas {
protected:
    float salario;
public:
    Vendedores(string correo = " ", string codigo = " ", string nombre = " ", string telefono = " ", float salario = 0.0) : Personas(correo, codigo, nombre, telefono), salario(salario) {
        this->salario = salario;
    }
    friend void MostrarVendedores();
};

class Productos {
public:
    string codigo;
    string nombre;
    string descripcion;
    float precio;
    string tipo;
    int stock;

    Productos(string codigo = "",string nombre = "", string descripcion = "", float precio = 0.0f, string tipo = "", int stock = 0) {
        this->codigo = codigo;
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->precio = precio;
        this->tipo = tipo;
        this->stock = stock;
    }
};

vector<Clientescorporativos> cliCO;
vector<Clientesindividuales> cliIN;

void NuevosClientes() {
    cliCO.clear();
    cliIN.clear();
    Clientescorporativos cliente1("001", "Juan", "23541789302", "Av.Parra 425", "juan4855@gmail.com", "945733867");
    Clientescorporativos cliente2("002", "Julieta", "56387030242", "Av.Parra 429", "julieta25@gmail.com", "946324113");
    Clientesindividuales cliente3("003", "Manuel", "A", "89283572386", "Calle Melgar 123", "Manuel2985@gmail.com", "954872634");
    cliCO.push_back(cliente1);
    cliCO.push_back(cliente2);
    cliIN.push_back(cliente3);

    string correo = "xyz", codigo = "00", nombre, telefono = "123", ruc = "321", direccion, categoria = "Y";

    for (int i = 0; i < cliCO.size(); i++) {
        for (int i = 0; i < cliIN.size(); i++) {
            if (cliCO[i].codigo == codigo or cliCO[i].nombre == nombre) {
                cout << "Ese cliente ya existe en clientes corporativos." << endl;
            }
            else if (cliIN[i].codigo == codigo or cliIN[i].nombre == nombre) {
                cout << "Ese cliente ya existe en clientes individuales." << endl;
            }
            else {
                if ((cliCO.size() + cliIN.size()) >= 6) {
                    cout << "Agenda llena. No se permiten más clientes." << endl;
                    return;
                }
                else {
                    while (nombre.empty()) {
                        cout << "Ingrese el nombre del cliente: " << endl;
                        getline(cin, nombre);
                        if (nombre.empty()) {
                            cout << "Nombre inválido. Ingrese nuevamente: " << endl;
                        }
                    }

                    bool hotmail = false;
                    bool gmail = false;
                    while (!hotmail or !gmail) {
                        cout << "Ingrese el correo electrónico del cliente: " << endl;
                        getline(cin, correo);

                        if (correo.find("@hotmail.com") != string::npos) {
                            hotmail = true;
                            break;
                        }
                        else if (correo.find("@gmail.com") != string::npos) {
                            gmail = true;
                            break;
                        }

                        if (!hotmail or !gmail) {
                            cout << "Correo inválido. Ingrese nuevamente: " << endl;
                        }
                    }

                    while (telefono.length() != 9) {
                        cout << "Ingrese el número de teléfono del cliente: " << endl;
                        getline(cin, telefono);
                        if (telefono.length() != 9) {
                            cout << "Teléfono inválido. Ingrese nuevamente: " << endl;
                        }
                    }

                    char tipoCliente = 'G';
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
                            cout << "Ingrese el RUC del cliente: " << endl;
                            getline(cin, ruc);
                            if (ruc.length() != 11) {
                                cout << "RUC inválido. Debe tener 11 dígitos. Ingrese nuevamente: " << endl;
                            }
                        }

                        cout << "Ingrese la dirección del cliente: ";
                        getline(cin, direccion);

                        while (categoria != "A" and categoria != "B" and categoria != "C" and categoria != "D") {
                            cout << "Ingrese la categoría del cliente (A/B/C/D): ";
                            cin >> categoria;
                            if (categoria != "A" and categoria != "B" and categoria != "C" and categoria != "D") {
                                cout << "Categoría inválida. Ingrese nuevamente (A/B/C/D): ";
                            }
                        }

                        Clientesindividuales nuevoCliente(correo, codigo, nombre, telefono, ruc, direccion, categoria);
                        cliIN.push_back(nuevoCliente);
                        cout << "Cliente individual agregado correctamente." << endl;
                        break;
                        break;
                        break;
                    }
                    else {
                        while (ruc.length() != 11) {
                            cout << "Ingrese el RUC del cliente: ";
                            getline(cin, ruc);
                            if (ruc.length() != 11) {
                                cout << "RUC inválido. Debe tener 11 dígitos. Ingrese nuevamente: ";
                            }
                        }

                        cout << "Ingrese la dirección del cliente: ";
                        getline(cin, direccion);

                        Clientescorporativos nuevoCliente(correo, codigo, nombre, telefono, ruc, direccion);
                        cliCO.push_back(nuevoCliente);
                        cout << "Cliente corporativo agregado correctamente." << endl;
                        break;
                    }
                }
            }
        }
    }
}

void BuscarClientes() {
    string codigo;
    string tipo;
    cout << "              Busqueda de Clientes             " << endl;
    cout << "Ingrese el tipo de cliente a buscar (I/C): " << endl;
    cin >> tipo;
    cout << "Ingrese el codigo del cliente: " << endl;
    cin >> codigo;

    if (tipo == "I") {
        for (int i = 0; i < cliIN.size(); i++) {
            if (cliIN[i].codigo == codigo) {
                cout << "Correo: " << cliIN[i].correo << endl;
                cout << "Codigo: " << cliIN[i].codigo << endl;
                cout << "Nombre: " << cliIN[i].nombre << endl;
                cout << "Telefono: " << cliIN[i].telefono << endl;
                cout << "RUC: " << cliIN[i].ruc << endl;
                cout << "Direccion: " << cliIN[i].direccion << endl;
                cout << "Categoria: " << cliIN[i].categoria << endl;
                break;
            }
            else {
                cout << "Cliente NO encontrado." << endl;
            }
        }
    }

    if (tipo == "C") {
        for (int i = 0; i < cliCO.size(); i++) {
            if (cliCO[i].codigo == codigo) {
                cout << "Correo: " << cliCO[i].correo << endl;
                cout << "Codigo: " << cliCO[i].codigo << endl;
                cout << "Nombre: " << cliCO[i].nombre << endl;
                cout << "Telefono: " << cliCO[i].telefono << endl;
                cout << "RUC: " << cliCO[i].ruc << endl;
                cout << "Direccion: " << cliCO[i].direccion << endl;
            }
            else {
                cout << "Cliente NO encontrado." << endl;
            }
        }
    }
}

vector<Vendedores> vendedores;

void AgregarVendedor() {
    vendedores.clear();
    Vendedores vendedor1("auron@gmail.com", "2023001", "Auron", "959697901", 3800.0);
    Vendedores vendedor2("reborn@hotmail.com", "2023002", "Reborn", "959697902", 1500.0);
    Vendedores vendedor3("mariana@gmail.com", "2023003", "Mariana", "959697903", 1800.0);
    Vendedores vendedor4("carola@gmail.com", "2023004", "Carola", "959697904", 2500.0);
    Vendedores vendedor5("juan@hotmail.com", "2023005", "Juan", "959697905", 1300.0);
    Vendedores vendedor6("sara@gmail.com", "2023006", "Sara", "959697906", 1500.0);
    Vendedores vendedor7("osvaldo@gmail.com", "2023007", "Osvaldo", "959697907", 2800.0);
    Vendedores vendedor8("raul@hotmail.com", "2023008", "Raul", "959697908", 1700.0);
    Vendedores vendedor9("ocho@gmail.com", "2023009", "Ocho", "959697909", 1500.0);
    Vendedores vendedor10("axoxxer@hotmail.com", "2023010", "Axoxer", "959697910", 1800.0);

    vendedores.push_back(vendedor1);
    vendedores.push_back(vendedor2);
    vendedores.push_back(vendedor3);
    vendedores.push_back(vendedor4);
    vendedores.push_back(vendedor5);
    vendedores.push_back(vendedor6);
    vendedores.push_back(vendedor7);
    vendedores.push_back(vendedor8);
    vendedores.push_back(vendedor9);
    vendedores.push_back(vendedor10);

    string nombre = "abc", codigo, telefono = "123", correo = "abc";
    double salario;

    for (int i = 0; i < vendedores.size(); i++) {
        if (vendedores[i].nombre == nombre) {
            cout << "Ese Vendedor ya existe." << endl;
        }
        else {
            bool hotmail = false;
            bool gmail = false;
            while (!hotmail or !gmail) {
                cout << "Ingrese el correo electrónico del cliente: " << endl;
                getline(cin, correo);

                if (correo.find("@hotmail.com") != string::npos) {
                    hotmail = true;
                }
                else if (correo.find("@gmail.com") != string::npos) {
                    gmail = true;
                }

                if (!hotmail or !gmail) {
                    cout << "Correo inválido. Ingrese nuevamente: " << endl;
                }
            }

            cout << "Ingrese el codigo del vendedor: ";
            cin >> codigo;

            cout << "Ingrese el nombre del vendedor: ";
            cin >> nombre;

            while (telefono.length() != 9) {
                cout << "Ingrese el número de teléfono del cliente: " << endl;
                getline(cin, telefono);
                if (telefono.length() != 9) {
                    cout << "Teléfono inválido. Ingrese nuevamente: " << endl;
                }
            }

            cout << "Ingrese el salario del vendedor: " << endl;
            cin >> salario;

            Vendedores nuevoVendedor(correo, codigo, nombre, telefono, salario);
            vendedores.push_back(nuevoVendedor);
            cout << "VENDEDOR REGISTRADO CORRECTAMENTE!" << endl;
            break;
        }
    }
}

void MostrarVendedores() {
    cout << "Lista de vendedores:" << endl;
    for (Vendedores& vendedor : vendedores) {
        cout << "Correo: " << vendedor.correo << ", Codigo: " << vendedor.codigo << ", Nombre: " << vendedor.nombre << ", Telefono: " << vendedor.telefono << ", Salario: " << vendedor.salario << endl;
        cout << endl;
    }
}

void MostrarClientes() {
    cout << "Lista de clientes:" << endl;

    cout << "Clientes individuales: " << endl;
    for (Clientesindividuales& clI : cliIN) {
        cout << "Correo: " << clI.correo << ", Codigo: " << clI.codigo << ", Nombre: " << clI.nombre << ", Telefono: " << clI.telefono << ", Telefono: " << clI.telefono << ", RUC: " << clI.ruc << ", Direccion: " << clI.direccion << ", Categoria: " << clI.categoria << endl;
        cout << endl;
    }

    cout << "Clientes corporativos: " << endl;
    for (Clientescorporativos& clC : cliCO) {
        cout << "Correo: " << clC.correo << ", Codigo: " << clC.codigo << ", Nombre: " << clC.nombre << ", Telefono: " << clC.telefono << ", Telefono: " << clC.telefono << ", RUC: " << clC.ruc << ", Direccion: " << clC.direccion << endl;
        cout << endl;
    }
}

vector<Productos> veProductos;

void NuevoProducto() {
    veProductos.clear();
    Productos Producto1("001", "Limpiamax", "Este es un producto que ayudara con la limpieza de utensilios de cocina", 12.50f, "Aseo", 5);
    Productos Producto2("002", "Sarten", "Este es una sarten que cocinara sus comidas de la mejor manera", 32.50f, "Utensilio", 3);
    Productos Producto3("003", "tortees", "Este es un snack picante hecho a base de hojuela de maiz", 2.00f, "Snack", 2);
    Productos Producto4("004", "hot dog", "Un embutido muy agradable al paladar y ademas es economico", 7.00f, "Embutido", 4);
    veProductos.push_back(Producto1);
    veProductos.push_back(Producto2);
    veProductos.push_back(Producto3);
    veProductos.push_back(Producto4);
    string codigo = "", nombre = "", descripcion = "";
    float precio = -1.0f;
    string tipo = "";
    int stock = 7;
    while (codigo.length() != 3) {
        cout << "Ingrese el codigo del producto: " << endl;
        getline(cin, codigo);
        if (codigo.length() != 3) {
            cout << "Codigo invalido. Ingrese nuevamente: " << endl;
        }
    }
    while (nombre.empty()) {    
        cout << "Ingrese el nombre del producto: " << endl;
        getline(cin, nombre);         
        if (nombre.empty()) {
            cout << "Nombre inválido. Ingrese nuevamente: " << endl;
        }
    }    
    for (int i = 0; i < veProductos.size(); i++) {
        if (veProductos[i].codigo == codigo or veProductos[i].nombre == nombre) {
            cout << "Ese producto ya existe." << endl;
            codigo = "";
            nombre = "";
        }
    }
    while (codigo.length() != 3) {
        cout << "Ingrese el codigo del producto: " << endl;
        getline(cin, codigo);
        if (codigo.length() != 3) {
            cout << "Codigo invalido. Ingrese nuevamente: " << endl;
        }
    }
    while (nombre.empty()) {
        cout << "Ingrese el nombre del producto: " << endl;
        getline(cin, nombre);
        if (nombre.empty()) {
            cout << "Nombre inválido. Ingrese nuevamente: " << endl;
        }
    }
    while (descripcion.empty()) {
        cout << "Ingrese la descripcion del producto: " << endl;
        getline(cin, descripcion);
        if (descripcion.empty()) {
            cout << "No ingreso una descripcion valida, intentelo de nuevo: " << endl;
        }
    }
    while (precio <= 0) {
        cout << "Ingrese el precio del producto: " << endl;
        cin >> precio;
        if (precio <= 0) {
            cout << "No ingreso un precio valido, intentelo de nuevo: " << endl;
        }
    }
    while (tipo.empty()) {
        cout << "ingrese el tipo de producto: " << endl;
        getline(cin, tipo);
        if (tipo.empty()) {
            cout << "No ingreso un tipo de producto valido, intentelo de nuevo: " << endl;
        }
    }
    while (stock > 5 and stock <= 0) {
        cout << "Ingrese el stock del producto(maximo 5): " << endl;
        cin >> stock;
        if (stock > 5 and stock <= 0) {
            cout << "Ingreso un stock no valido, intentelo de nuevo: " << endl;
        }
    }
    Productos nuevoProducto(codigo,nombre,descripcion,precio,tipo,stock);
    veProductos.push_back(nuevoProducto);
    cout << "Producto agregado correctamente." << endl;
}
void MostrarProductos() {
    cout << "Lista de productos:" << endl;
    for (Productos& producto : veProductos) {
        cout << "Codigo: " << producto.codigo << ", Nombre: " << producto.nombre << ", Descripcion: " << producto.descripcion << ", Precio: " << producto.precio << ", Tipo: " << producto.tipo << ", Stock: " << producto.stock << endl;
        cout << endl;
    }
}
void menu() {
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
        system("pause");
        system("cls");

        switch (opc) {
        case 1:
            cout << "Selecciono NUEVOS CLIENTES" << endl;
            NuevosClientes();
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Selecciono BUSCAR CLIENTES" << endl;
            BuscarClientes();
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Selecciono NUEVO VENDEDOR" << endl;
            AgregarVendedor();
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "Selecciono NUEVO PRODUCTO" << endl;
            NuevoProducto();
            MostrarProductos();
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Selecciono VENTAS" << endl;
            system("pause");
            system("cls");
            break;
        case 6:
            cout << "Selecciono LISTA DE CLIENTES" << endl;
            MostrarClientes();
            system("pause");
            system("cls");
            break;
        case 7:
            cout << "Selecciono LISTA DE VENDEDORES" << endl;
            MostrarVendedores();
            system("pause");
            system("cls");
            break;
        case 8:
            cout << "Saliendo del programa..." << endl;
            system("pause");
            system("cls");
            break;
        default:
            cout << "ERROR, Opción incorrecta. Ingresar una opción correcta: " << endl;
            system("pause");
            system("cls");
        }
    }
}

int main() {
    menu();
}
