/*
Escriba un programa en C++ para que lea tres enteros desde teclado y nos diga si
están ordenados (da igual si es de forma ascendente o descendente) o no lo están.
Por ejemplo, la sucesión de números 3, 6, 9 estaría ordenada así como la serie
13, 2, 1 pero no lo estaría la serie 3, 9, 5 .
*/
#include <iostream>

using namespace std;

int main()
{
    int num1, num2, num3;

    cout << "Introduce el primer número: ";
    cin >> num1;

    cout << "Introduce el segundo número: ";
    cin >> num2;

    cout << "Introduce el tercer número: ";
    cin >> num3;

    if(num1 <= num2 && num2 <= num3){
        cout << "La sucesión está ordenada de forma ascendente";
    }else if(num3 <= num2 && num2 <= num1){
        cout << "La sucesión está ordenada de forma descendente";
    }else{
        cout << "La sucesión está desordenada";
    }

}
