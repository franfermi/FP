/*
Escriba un programa que lea un valor entero e imprima en pantalla cada uno de sus
dígitos separados por dos espacios en blanco. Supondremos que el usuario introduce
siempre un entero de tres dígitos, como por ejemplo 351 . En este caso, la salida sería:
    3  5  1
*/
#include <iostream>

using namespace std;

int main()
{
    int num, aux;
    int centenas, decenas, unidades;

    cout << "Introduce un número de tres cifras: ";
    cin >> num;

    //Calculamos las centenas
    centenas = num / 100; //3
    //Almacenamos en una variable auxiliar el resto de dividir por 100
    aux = num % 100; //51
    //Calculamos las decenas a partir del valor auxiliar / 10
    decenas = aux / 10; //5
    //Calculamos las unidades a partir del resto entre el valor auxiliar y 10
    unidades = aux % 10; //1

    cout << "El número con espacios es:\n"
            << centenas << " " << decenas << " " << unidades;
}
