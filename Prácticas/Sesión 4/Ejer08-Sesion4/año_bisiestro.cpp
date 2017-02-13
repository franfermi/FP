/*
Cree un programa que lea el número de un año e indique si es bisiesto o no. Un año
es bisiesto si es múltiplo de cuatro, pero no de cien. Excepción a la regla anterior son
los múltiplos de cuatrocientos que siempre son bisiestos. Por ejemplo, son bisiestos:
1600,1996, 2000, 2004. No son bisiestos: 1700, 1800, 1900, 1998, 2002.
*/
#include <iostream>

using namespace std;

int main()
{
    int anio;

    cout << "Introduce el año: ";
    cin >> anio;

    if(((anio % 4 == 0) && (anio % 100 != 0)) || (anio % 400 == 0)){
        cout << "El año es bisiestro";
    }else{
        cout << "El año NO es bisiestro";
    }
}
