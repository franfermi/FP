/*
Diremos que un número entero positivo es secuenciable si se puede generar como
suma de números consecutivos (al menos dos). Por ejemplo, 6 = 1+2+3, 15 = 7+8.
Esta descomposición no tiene por qué ser única. Por ejemplo, 15 = 7+8 = 4+5+6 =
1 + 2 + 3 + 4 + 5. Escriba un programa que lea un entero n ≥ 1 e imprima todas las
descomposiciones posibles. En este ejercicio puede mezclar operaciones de E/S y C
dentro del mismo bucle.
Como curiosidad, los únicos números con 0 descomposiciones son las potencias de
2.
*/
#include <iostream>

using namespace std;

int main()
{
    int numero, suma=0, limite, i, j, k;
    bool secuenciable = false;

    do{
        cout << "introduce el número: ";
        cin >> numero;
    }while(numero < 1);

    limite = (numero/2)+1; //Establecemos el tope el cual se puede
                        //sumar un numero + otro para conseguir
                        //el introducido.
    for(i=limite; i>0; i--){
        for(j=i; suma<numero; j--)
            suma += j;

        if(suma == numero){
            secuenciable = true;
            for(k=i; k>j; k--)
                cout << k << " ";
            cout << " / ";
        }
        suma = 0;
    }

    if(!secuenciable)
        cout << "El número no es secuenciable";
}
