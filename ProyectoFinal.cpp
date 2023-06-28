#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

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
        string direccion;

        Cliente(string co = " ", string cd = " ", string nm = " ", string tl = " ", string di = " ") : Personas(co, cd, nm, tl), direccion(di) {
            this->direccion = di;
        }

        friend void NuevosClientes();
        friend void BuscarClientes();
};

class Clientesindividuales : public Cliente {
    public:
        string categoria;
        string DNI;

        Clientesindividuales(string co = "", string cd = "", string nm = "", string tl = "", string di = "", string _dni = "", string ct = "D") : Cliente(co, cd, nm, tl, di), DNI(_dni), categoria(ct) {}

        int tasadescuento(int monto, string categoria) {
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

        friend void NuevosClientes();
        friend void MostrarClientes();
};

class Clientescorporativos : public Cliente {
    public:
        string ruc;

        Clientescorporativos(string co = "", string cd = "", string nm = "", string tl = "", string di = "",  string _ruc = "") : Cliente(co, cd, nm, tl, di), ruc(_ruc) {
            this->ruc = _ruc;
        }

        int tasadescuento(int monto) {
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

vector<Productos> veProductos;
vector<Clientescorporativos> cliCO;
vector<Clientesindividuales> cliIN;

void reporteVentas() {
    string codigo;
    char tipo;
    cout << "              Reporte de ventas por Clientes             " << endl;
    cout << "Ingrese el tipo de cliente a buscar (I/C): ";
    cin >> tipo;
    cout << "Ingrese el código del cliente: ";
    cin >> codigo;

    if (tipo == 'I') {
        bool encontrado = false;
        for (const auto& cliente : cliIN) {
            if (cliente.codigo == codigo) {
                cout << "Cliente encontrado"<< endl;

                for (Productos& producto : veProductos) {
                    cout<<"                                Venta 001                               "<<endl;
                    cout<<"Fecha 27/06/2023"<<endl;
                    cout<<"COD PRODUCTO             CANTIDAD            PRECIO              SUBTOTAL"<<endl;
                    cout<<producto.codigo<<" "<<producto.nombre<<"              "<<producto.precio<<"               "<<producto.stock<<"                    "<<producto.precio*producto.stock<<endl;
                    cout << "--------------------------------------------------------------------------------------" << endl;
                }
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Cliente no encontrado" << endl;
        }
    }
    else if (tipo == 'C') {
        bool encontrado = false;
        for (const auto& cliente : cliCO) {
            if (cliente.codigo == codigo) {
                cout << "Cliente encontrado"<< endl;
                
                for (Productos& producto : veProductos) {
                    cout<<"                                Venta 001                               "<<endl;
                    cout<<"Fecha 27/06/2023"<<endl;
                    cout<<"COD PRODUCTO             CANTIDAD            PRECIO              SUBTOTAL"<<endl;
                    cout<<producto.codigo<<" "<<producto.nombre<<"              "<<producto.precio<<"               "<<producto.stock<<"                    "<<producto.precio*producto.stock<<endl;
                    cout << "--------------------------------------------------------------------------------------" << endl;
                }
                encontrado = true;
                break;
            }
        }
    
        if (!encontrado) {
            cout << "Cliente no encontrado" << endl;
        }
    }
    else {
        cout << "Tipo de cliente inválido" << endl;
    }
    }

void NuevosClientes() {
    string correo = "xyz", codigo = "004", nombre = "", telefono = "123", direccion = "", ruc = "321", dni = "123", categoria = "Y";

    if ((cliCO.size() + cliIN.size()) >= 6) {
        cout << "Agenda llena. No se permiten más clientes." << endl;
        return;
    }

    while (nombre.empty()) {
        cout << "Ingrese el nombre del cliente: " << endl;
        getline(cin, nombre);
        if (nombre.empty()) {
            cout << "Nombre inválido. Ingrese nuevamente: " << endl;
        }
    }

    bool hotmail = false;
    bool gmail = false;
    while (!hotmail && !gmail) {
        cout << "Ingrese el correo electrónico del cliente: " << endl;
        getline(cin, correo);

        if (correo.find("@hotmail.com") != string::npos) {
            hotmail = true;
        }
        else if (correo.find("@gmail.com") != string::npos) {
            gmail = true;
        }

        if (!hotmail && !gmail) {
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
        bool existeCliente = false;
        for (int i = 0; i < cliIN.size(); i++) {
            if (cliIN[i].nombre == nombre and cliIN[i].telefono == telefono) {
                existeCliente = true;
                break;
            }
        }

        if (existeCliente) {
            cout << "Ese cliente ya existe en clientes individuales." << endl;
            return;
        } else {
            while (dni.length() != 8) {
                cout << "Ingrese el DNI del cliente: " << endl;
                getline(cin, dni);
                if (dni.length() != 8) {
                    cout << "DNI inválido. Debe tener 8 dígitos. Ingrese nuevamente: " << endl;
                }
            }

            cout << "Ingrese la dirección del cliente: ";
            getline(cin, direccion);

            while (categoria != "A" && categoria != "B" && categoria != "C" && categoria != "D") {
                cout << "Ingrese la categoría del cliente (A/B/C/D): ";
                cin >> categoria;
                cin.ignore();
                if (categoria != "A" && categoria != "B" && categoria != "C" && categoria != "D") {
                    cout << "Categoría inválida. Ingrese nuevamente (A/B/C/D): ";
                }
            }

            int ultimoCodigoInt = stoi(cliIN[cliIN.size() - 1].codigo);
            ultimoCodigoInt++;
            codigo = to_string(ultimoCodigoInt);

            Clientesindividuales nuevoCliente(correo, codigo, nombre, telefono, dni, direccion, categoria);
            cliIN.push_back(nuevoCliente);
            cout << "Cliente individual agregado correctamente." << endl;
            }
    }
    else {
        bool existeCliente = false;
        for (int i = 0; i < cliCO.size(); i++) {
            if (cliCO[i].nombre == nombre and cliCO[i].telefono == telefono) {
                existeCliente = true;
                break;
            }
        }

        if (existeCliente) {
            cout << "Ese cliente ya existe en clientes corporativos." << endl;
            return;
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

            int ultimoCodigoInt = stoi(cliCO[cliCO.size() - 1].codigo);
            ultimoCodigoInt++;
            codigo = to_string(ultimoCodigoInt);

            Clientescorporativos nuevoCliente(correo, codigo, nombre, telefono, ruc, direccion);
            cliCO.push_back(nuevoCliente);
            cout << "Cliente corporativo agregado correctamente." << endl;
        }
    }
}

void BuscarClientes() {
    string codigo;
    char tipo;
    cout << "              Búsqueda de Clientes             " << endl;
    cout << "Ingrese el tipo de cliente a buscar (I/C): ";
    cin >> tipo;
    cout << "Ingrese el código del cliente: ";
    cin >> codigo;

    if (tipo == 'I') {
        bool encontrado = false;
        for (const auto& cliente : cliIN) {
            if (cliente.codigo == codigo) {
                cout << "Correo: " << cliente.correo << endl;
                cout << "Código: " << cliente.codigo << endl;
                cout << "Nombre: " << cliente.nombre << endl;
                cout << "Teléfono: " << cliente.telefono << endl;
                cout << "DNI: " << cliente.DNI << endl;
                cout << "Dirección: " << cliente.direccion << endl;
                cout << "Categoría: " << cliente.categoria << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Cliente no encontrado" << endl;
        }
    }
    else if (tipo == 'C') {
        bool encontrado = false;
        for (const auto& cliente : cliCO) {
            if (cliente.codigo == codigo) {
                cout << "Correo: " << cliente.correo << endl;
                cout << "Código: " << cliente.codigo << endl;
                cout << "Nombre: " << cliente.nombre << endl;
                cout << "Teléfono: " << cliente.telefono << endl;
                cout << "RUC: " << cliente.ruc << endl;
                cout << "Dirección: " << cliente.direccion << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Cliente no encontrado" << endl;
        }
    }
    else {
        cout << "Tipo de cliente inválido" << endl;
    }
}

vector<Vendedores> vendedores;

void AgregarVendedor() {
    string nombre = "abc", codigo, telefono = "123", correo = "abc";
    double salario;

    for (int i = 0; i < vendedores.size(); i++) {
        if (vendedores[i].nombre == nombre) {
            cout << "Ese Vendedor ya existe." << endl;
        }
        else {
            bool hotmail = false;
            bool gmail = false;
            while (!hotmail && !gmail) {
                cout << "Ingrese el correo electrónico del cliente: " << endl;
                getline(cin, correo);

                if (correo.find("@hotmail.com") != string::npos) {
                    hotmail = true;
                }
                else if (correo.find("@gmail.com") != string::npos) {
                    gmail = true;
                }

                if (!hotmail && !gmail) {
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
        ofstream listavendedores("listvendedores.txt");
        listavendedores << "Correo: " << vendedor.correo << ", Codigo: " << vendedor.codigo << ", Nombre: " << vendedor.nombre << ", Telefono: " << vendedor.telefono << ", Salario: " << vendedor.salario << endl;
        ifstream archivo2("listvendedores.txt)");
        if(archivo2.is_open()){
           string linea;
           while(getline(archivo2,linea)){
            cout << linea << endl;
           }
        }
        cout << endl;
    }
}

void MostrarClientes() {
    cout << "Lista de clientes:" << endl;

    cout << "Clientes individuales: " << endl;
    for (Clientesindividuales& clI : cliIN) {
        ofstream listaclientes("listclientesin.txt");
        listaclientes << "Correo: " << clI.correo << ", Codigo: " << clI.codigo << ", Nombre: " << clI.nombre << ", Telefono: " << clI.telefono << ", Telefono: " << clI.telefono << ", DNI: " << clI.DNI << ", Direccion: " << clI.direccion << ", Categoria: " << clI.categoria << endl;
        ifstream archivo1("listclientesin.txt");
        if (archivo1.is_open()) {
            string linea;
            while (getline(archivo1, linea)) {
                cout << linea << endl;
            }
            archivo1.close();
        }
        cout << endl;
    }

    cout << "Clientes corporativos: " << endl;
    for (Clientescorporativos& clC : cliCO) {
        ofstream listaclientes1("listclientescor.txt");
        listaclientes1 << "Correo: " << clC.correo << ", Codigo: " << clC.codigo << ", Nombre: " << clC.nombre << ", Telefono: " << clC.telefono << ", Telefono: " << clC.telefono << ", RUC: " << clC.ruc << ", Direccion: " << clC.direccion << endl;
        ifstream archivo3("listclientescor.txt");
                if (archivo3.is_open()) {
            string linea;
            while (getline(archivo3, linea)) {
                cout << linea << endl;
            }
            archivo3.close();
        }
        cout << endl;
    }
}

void NuevoProducto() {
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
    while (stock > 5 or stock <= 0) {
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
        ofstream listaproductos("listproduc.txt");
        listaproductos << "Codigo: " << producto.codigo << ", Nombre: " << producto.nombre << ", Descripcion: " << producto.descripcion << ", Precio: " << producto.precio << ", Tipo: " << producto.tipo << ", Stock: " << producto.stock << endl;
        ifstream archivo("listproduc.txt");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                cout << linea << endl;
            }
            archivo.close();
        }
        cout << endl;
    }
}

void menu() {
    string opc = "0";
    while (opc != "8") {
        cout << "SISTEMA DE COMERCIO DE PRODUCTOS DE CONSTRUCCIÓN" << endl;
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

        if (opc == "1") { 
            cout << "Selecciono NUEVOS CLIENTES" << endl;
            NuevosClientes();
            system("pause");
            system("cls");
            break;
        } else if (opc == "2") { 
            cout << "Selecciono BUSCAR CLIENTES" << endl;
            BuscarClientes();
            system("pause");
            system("cls");
            break;
        } else if (opc == "3") { 
            cout << "Selecciono NUEVO VENDEDOR" << endl;
            AgregarVendedor();
            system("pause");
            system("cls");
            break;
        } else if (opc == "4") { 
            cout << "Selecciono NUEVO PRODUCTO" << endl;
            NuevoProducto();
            MostrarProductos();
            system("pause");
            system("cls");
            break;
        } else if (opc == "5") { 
            cout << "Selecciono VENTAS" << endl;
            system("pause");
            system("cls");
            break;
        } else if (opc == "6") { 
            cout << "Selecciono LISTA DE CLIENTES" << endl;
            MostrarClientes();
            system("pause");
            system("cls");
            break;
        } else if (opc == "7") { 
            cout << "Selecciono LISTA DE VENDEDORES" << endl;
            MostrarVendedores();
            system("pause");
            system("cls");
            break;
        } else if (opc == "8") { 
            cout << "Saliendo del programa..." << endl;
            system("pause");
            system("cls");
            break;
        } else {
            cout << "ERROR, Opción incorrecta. Ingresar una opción correcta: " << endl;
            system("pause");
            system("cls");
        }
    }
}

int main() {
    Clientescorporativos cliente1("juan4855@gmail.com", "001", "Juan", "945733867", "Av.Parra 425", "23541789302");
    Clientescorporativos cliente2("julieta25@gmail.com", "002", "Julieta", "978456121", "Av.Parra 429", "56387030242");
    Clientesindividuales cliente3("Manuel2985@gmail.com", "003", "Manuel", "954872634", "Calle Melgar 123", "12345678", "A");
    cliCO.push_back(cliente1);
    cliCO.push_back(cliente2);
    cliIN.push_back(cliente3);

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

    Productos Producto1("001", "Limpiamax", "Este es un producto que ayudara con la limpieza de utensilios de cocina", 12.50f, "Aseo", 5);
    Productos Producto2("002", "Sarten", "Este es una sarten que cocinara sus comidas de la mejor manera", 32.50f, "Utensilio", 3);
    Productos Producto3("003", "tortees", "Este es un snack picante hecho a base de hojuela de maiz", 2.00f, "Snack", 2);
    Productos Producto4("004", "hot dog", "Un embutido muy agradable al paladar y ademas es economico", 7.00f, "Embutido", 4);
    veProductos.push_back(Producto1);
    veProductos.push_back(Producto2);
    veProductos.push_back(Producto3);
    veProductos.push_back(Producto4);

    menu();
}
