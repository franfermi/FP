/*
Modifique la solución del ejercicio 8 (año bisiesto) para que no se mezclen E/S y C
(entradas/salidas y cómputos) dentro de la misma estructura condicional.
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

