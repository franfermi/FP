/*
El algoritmo de la multiplicación rusa es una forma distinta de calcular la multiplicación
de dos números enteros n ∗ m. Para ello este algoritmo va calculando el doble del
multiplicador m y la mitad (sin decimales) del multiplicando n hasta que n tome el
valor 1 y suma todos aquellos multiplicadores cuyos multiplicandos sean impares.
*/
#include <iostream>

using namespace std;

int main()
{
    int n, m, resultado=0;

    cout << "Introduce el primer número a multiplicar: ";
    cin >> n;

    cout << "Introduce el segundo número a multiplicar: ";
    cin >> m;

    //Mientras el primer número sea distinto de cero
    while(n != 0){
        if(n % 2 != 0) //Si el resto es par sumamos el segundo número
            resultado += m;
        n/=2; //Dividimos entre 2 el primer número
        m+=m; //Sumamos el doble al segundo número
    }
    cout << "El resultado es : " << resultado;
}
