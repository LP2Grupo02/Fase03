#include <iostream>
#include <stdexcept>

double divide(int numerador, int denominador) {
    if (denominador == 0) {
        throw std::runtime_error("No se puede dividir entre cero.");
    }
    return static_cast<double>(numerador) / denominador;
}

int main() {
    try {
        int numerador, denominador;
        
        // Ejemplo 1: División válida
        numerador = 10;
        denominador = 2;
        double resultado = divide(numerador, denominador);
        std::cout << "Resultado: " << resultado << std::endl;
        
        // Ejemplo 2: División entre cero
        numerador = 8;
        denominador = 0;
        resultado = divide(numerador, denominador);
        std::cout << "Resultado: " << resultado << std::endl;  // Esta línea no se ejecutará debido a la excepción
        
    } catch (const std::runtime_error& error) {
        std::cout << "Excepción capturada: " << error.what() << std::endl;
    }
    
    return 0;
}


// DIAGRAMA DE CLASES

+---------------------+
|    std::iostream    |
+---------------------+
          ^
          |
          |
+----------------------+
|  std::runtime_error  |
+----------------------+

        ^
        |
        |
+-----------------------+
|        divide         |
+-----------------------+
| - numerador: int      |
| - denominador: int    |
+-----------------------+
| + divide(numerador,   |
|   denominador): double|
+-----------------------+

        ^
        |
        |
+-----------------------+
|         main          |
+-----------------------+
|                       |
+-----------------------+


// DIAGRAMA DE SECUENCIA

+-------------------------+
|        Usuario          |
+-------------------------+
        |
        |  Ingresar valores numerador y denominador
        |------------------------------------------->|
        |                                          |
        |    +----------------------+
        |    |     divide()        |
        |    +----------------------+
        |                |
        |      |------------------|
        |      |  denominador = 0 |
        |      |------------------|
        |                |
        |          Lanzar excepción
        |----------------------------->|
        |                |
        |       +---------------------+
        |       | std::runtime_error |
        |       +---------------------+
        |                |
        |      |-------------------|
        |      |   Capturar excepción  |
        |      |-------------------|
        |                |
        |    Mostrar mensaje de error
        |--------------------------------------->|
        |                |
        |    |---------------------|
        |    |   Finalizar programa  |
        |    |---------------------|
        |                |
        |   |----------------------|
        |   |  denominador != 0    |
        |   |----------------------|
        |                |
        |    Realizar división
        |----------------------------->|
        |                |
        |    Mostrar resultado
        |----------------------------------------->|
        |                |
        |   |-------------------|
        |   |   Finalizar programa |
        |   |-------------------|

