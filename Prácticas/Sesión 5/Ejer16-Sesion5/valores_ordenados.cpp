/*
Modifique el ejercicio 7 para que el programa nos diga si los tres valores leídos es-
tán ordenados de forma ascendente, ordenados de forma descendente o no están
ordenados. Para resolver este problema, debe usar una variable de tipo enumerado.
*/
#include <iostream>

using namespace std;

int main()
{
    int num1, num2, num3;
    enum ordenaciones{
        ordenado_ascendente,
        ordenado_descendente,
        desordenado
    };

    ordenaciones orden;

    cout << "Introduce el primer número: ";
    cin >> num1;

    cout << "Introduce el segundo número: ";
    cin >> num2;

    cout << "Introduce el tercer número: ";
    cin >> num3;

    if(num1 <= num2 && num2 <= num3){
        orden = ordenado_ascendente;
    }else if(num3 <= num2 && num2 <= num1){
        orden = ordenado_descendente;
    }else{
        orden = desordenado;
    }

    switch(orden){
        case 0:
            cout << "Ordenado ascendente";
            break;
        case 1:
            cout << "Ordenado descendente";
            break;
        case 2:
            cout << "Desordenado";
            break;

    }
}

