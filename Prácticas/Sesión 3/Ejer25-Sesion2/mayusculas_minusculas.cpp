/*
Construya un programa que lea un carácter (supondremos que el usuario introduce
una mayúscula), lo pase a minúscula y lo imprima en pantalla. Hágalo sin usar las
funciones toupper ni tolower de la biblioteca cctype . Para ello, debe considerarse
la relación que hay en C++ entre los tipos enteros y caracteres.
Ejemplo de entrada: D −− Salida correcta: d
*/
#include <iostream>

using namespace std;

int main()
{
    const int SALTO = 'a' - 'A';
    char caracter;

    cout << "Introduce un caracter mayúscula: ";
    cin >> caracter;

    //Convertimos el caracter introducido en su
    //equivalente en minúsculas.
    caracter += MAY_MIN;

    cout << "El caracter en minúsculas es: " << caracter;
}
