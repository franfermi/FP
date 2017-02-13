#include <iostream>

using namespace std;

int main()
{
    float caja_izda;
    float caja_dcha;
    float aux;

    cout << "Introduce la cantidad de la caja izquierda: ";
    cin >> caja_izda;

    cout << "Introduce la cantidad de la caja derecha: ";
    cin >> caja_dcha;

    /*Necesitamos una variable auxiliar para almacenar
    el valor antes de ser machacado por otro. */
    aux =  caja_izda;
    caja_izda = caja_dcha;
    caja_dcha = aux;

    cout << "\nLa caja izquierda vale: " << caja_izda;
    cout << "\nLa caja derecha vale: " << caja_dcha;
}
