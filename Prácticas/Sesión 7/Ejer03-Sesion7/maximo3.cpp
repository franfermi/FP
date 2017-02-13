/*
En las transparencias de clase se ha visto la función
de tres valores enteros.
Max3 que calculaba el máximo
Defina ahora la función Max que calcule el máximo de dos valores enteros y cambie
la implementación de Max3 para que llame a la función Max.
Construya un programa principal que llame a teclado.
Max3 con tres valores leídos desde teclado.
*/
#include <iostream>

using namespace std;

int Max(int a, int b){
    int max;

    if(a > b)
        max = a;
    else
        max = b;

    return max;
}

int Max3(int a, int b, int c){
    int max;

    max = Max(a, b);

    if(c > max)
        max = c;

    return max;
}

int main()
{
    int a, b, c, max;

    cout << "Introduce tres enteros: ";
    cin >> a >> b >> c;

    max = Max3(a, b, c);

    cout << "El mayor de los tres enteros es el: " << max;
}
