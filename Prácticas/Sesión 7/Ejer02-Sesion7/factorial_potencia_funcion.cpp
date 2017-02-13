/*
Reescriba la solución del ejercicio 40 (factorial y potencia) de la Relación de Proble-
mas II, modularizándola con funciones.
Para el factorial, use la función Factorial vista en las transparencias de clase. Para
el cómputo de la potencia, defina la función Potencia.
*/
#include <iostream>

using namespace std;

long long Factorial(int n){
    int i;
    long long fact = 1;

    for(i = 2; i <= n; i++)
        fact = fact * i;

    return fact;
}

long Potencia(int base, int exponente){
    int resultado=1, i;

    for(i=0; i<exponente; i++)
        resultado = resultado * base;

    return resultado;
}

int main()
{
    int n;
    double x;
    long potencia;
    long long factorial;

    cout << "Introduce un valor entero: ";
    cin >> n;

    cout << "Introduce un valor real: ";
    cin >> x;

    potencia = Potencia(x, n);
    factorial = Factorial(n);

    cout << "La potencia de " << x << "^" << n << " es: " << potencia << endl;
    cout << "El factorial de " << n << " es: " << factorial;
}
