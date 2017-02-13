/*
Construya un programa que lea un valor T y calcule la siguiente sumatoria
*/
#include <iostream>

using namespace std;

int main()
{
    int T, factorial, sumatorio=0 i, j;

    cout << "Introduce el valor T: ";
    cin >> T;

    for(i=1; i<=T; i++){
        factorial = 1;
        for(j=1; j<=i; j++){
            factorial *= j;
        }
        sumatorio += factorial;
    }

    /*
    Realizado con bucle while anidado
    ---------------------------------
    int T, factorial=1, sumatorio=0, cont1=1, cont2;
    cout << "Introduce el valor T: ";
    cin >> T;
    while(cont1 <= T){
        factorial = 1;
        cont2 = 1;
        while(cont2 <= cont1){
            factorial *= cont2;
            cont2++;
        }
        sumatorio += factorial;
        cont1++;
    }
    */

    cout << "El resultado es: " << sumatorio;
}
