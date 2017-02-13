/*
Se quiere generalizar el ejercicio 7 que intercambiaba el valor de dos variables al caso
de tres variables. Construya un programa que declare las variables x , y y z , lea su
valor desde teclado e intercambien entre sí sus valores de forma que el valor de x
pasa a y , el de y pasa a z y el valor de z pasa a x (se pueden declarar variables
auxiliares aunque se pide que se use el menor número posible).
Ejemplo de entrada: 7 4 5 −− Salida correcta: 5 7 4
*/
#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    int aux1, aux2;

    cout << "Introduce el valor x: ";
    cin >> x;

    cout << "Introduce el valor y: ";
    cin >> y;

    cout << "Introduce el valor z: ";
    cin >> z;

    aux1 = x;
    aux2 = y;
    x = z;
    y = aux1;
    z = aux2;

    cout << "\nX: " << x;
    cout << "\nY: " << y;
    cout << "\nZ: " << z;
}
