#include <iostream>
#include <map>
#include <string>

using namespace std;
struct Producto{
    string nombre;
    int cantidad;
};

int main(){
    map<int, Producto> inventario;
    int code;
    string nombre;
    int cantidad;

    code=1;
    nombre="Laptop";
    cantidad=10;
    inventario[code]={nombre, cantidad};

    code=2;
    nombre="Smartphone";
    cantidad=20;
    inventario[code]={nombre, cantidad};

    {
    int opcion;
    bool repetir = true;
    
    do {
        system("cls");
 
        cout << "\n\nElija la opción que desea realizar" << endl;
        cout << "1. Agregar un nuevo producto al inventario" << endl;
        cout << "2. Actualizar la cantidad disponible de un producto existente" << endl;
        cout << "3. Buscar un producto por su código" << endl;
        cout << "4. Mostrar la lista de productos ordenada alfabéticamente por su descripción" << endl;
        cout << "0. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout<<"\nAgregar nuevo producto"<<endl;
                cout<<"Ingresa el código"<<endl;
                cin>>code;
                cout<<"Ingresa el nombre"<<endl;
                cin>>nombre;
                cout<<"Ingresa la cantidad"<<endl;
                cin>>cantidad;
                inventario[code]={nombre, cantidad};
                system("pause>nul"); // Pausa
                break;
                
            case 2:
                int newCantidad;
                cout<<"Ingresa el código del producto: ";
                cin>>code;
                cout<<"Ingresa la cantidad: ";
                cin>>newCantidad;
                if(inventario.find(code)!=inventario.end()){
                inventario[code].cantidad = newCantidad;
                cout<<"Cantidad en stock actualizada correctamente."<<endl;
                } else {
                cout<<"Producto no encontrado."<<endl;
                }              
                
                system("pause>nul"); // Pausa
                break;
                
            case 3:
                cout<<"Ingresa el código del producto: ";
                cin>>code;
                if(inventario.find(code)!= inventario.end()){
                cout<<"Producto encontrado."<<endl;
                cout<<"Codigo: "<<code<<endl;
                cout<<"Nombre: "<<inventario[code].nombre<<endl;
                cout<<"Cantidad en stock "<<inventario[code].cantidad<<endl;
                } else {
                cout<<"Producto no encontrado."<<endl;
                }
                system("pause>nul"); // Pausa            
                break;
                
            case 4:
                for (const auto& x : inventario) { 

                    cout << x.first << ", "; 
                    cout << inventario[x.first].nombre << ", "; 
                    cout << inventario[x.first].cantidad << endl; 
                } 

                system("pause>nul"); // Pausa                
                break;
            
            case 0:
            	repetir = false;
            	break;
        }        
    } while (repetir);
    return 0;
}
}
