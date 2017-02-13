/*
En el ejercicio 13 de la Relación de Problemas I se pedía escribir un programa que
leyese un valor entero de tres dígitos e imprimiese los dígitos separados por un espa-
cio en blanco. Haga lo mismo pero para un número entero arbitrario. Por ejemplo, si el
número es 3519 , la salida sería:
3 5 1 9
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num, aux, cifras=0, divisor=10, resto=0, digito=0;

    cout << "Introduce un número: ";
    cin >> num;

    aux = num;
    //Calculamos las cifras del número introducido
    while(aux > 0){
        aux = aux / 10;
        cifras++;
    }
    //Calculamos el divisor mayor a partir del número de cifras
    divisor = pow(divisor, cifras-1);

    while(cifras > 0){
        digito = num / divisor; //Obtenemos el digito a pintar por el cociente
        resto = num % divisor; //Almacenamos el resto
        num = resto;

        divisor /= 10; //Decrementamos el divisor entre 10
        cifras--; //Decrementamos el número de cifras
        cout << digito << " ";
    }
}
