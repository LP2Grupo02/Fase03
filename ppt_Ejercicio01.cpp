#include <iostream>
using namespace std;

template <typename T1>
class Cuadrado {
private:
    T1 lado;
    T1 altura;

public:
    Cuadrado(T1 ld, T1 al) : lado(ld), altura(al) {}

    template <typename T2> friend T2 Perimetro(Cuadrado<T2>& c);

    template <typename T3> friend T3 Area(Cuadrado<T3>& c);
};

template <typename T2> T2 Perimetro(Cuadrado<T2>& c) {
    return (c.lado * 2) + (c.altura * 2);
}

template <typename T3> T3 Area(Cuadrado<T3>& c) {
    return c.lado * c.altura;
}

int main() {
    int ld1, al1;
    float ld2, al2;
    int cP1, cA1;
    float cP2, cA2;

    cout << "Ingrese el lado: " << endl;
    cin >> ld1;
    cout << "Ingrese la altura: " << endl;
    cin >> al1;
    Cuadrado<int> c1(ld1, al1);
    cP1 = Perimetro(c1);
    cout << "El perímetro de c1 es: " << cP1 << endl;
    cA1 = Area(c1);
    cout << "El área de c1 es: " << cA1 << endl;

    cout << "Ingrese el lado: " << endl;
    cin >> ld2;
    cout << "Ingrese la altura: " << endl;
    cin >> al2;
    Cuadrado<float> c2(ld2, al2);
    cP2 = Perimetro(c2);
    cout << "El perímetro de c2 es: " << cP2 << endl;
    cA2 = Area(c2);
    cout << "El área de c2 es: " << cA2 << endl;

    return 0;
}
