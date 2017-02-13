/*
Un banco presenta la siguiente oferta. Si se deposita una cantidad de euros dada por
la variable capital durante un año a plazo fijo, se dará un interés dado por la variable
interes. Realice un programa que lea una cantidad capital y un interés interes
desde teclado. A continuación, el programa debe calcular en una variable total el
dinero que se tendrá al cabo de un año, aplicando la fórmula de abajo e imprimirá el
resultado en pantalla.
    total = capital + capital * interes/100
*/
#include <iostream>

using namespace std;

int main()
{
    float capital, interes, total;

    //Muestra por pantalla:
    cout << "\nIntroduce el capital: ";
    //Se introduce por teclado el capital inicial
    cin >> capital;

    //Muestra por pantalla
    cout << "\nIntroduce el interés: ";
    //Se introduce por teclado el interes
    cin >> interes;

    //Cálculo del salario total
    total = capital + capital * (interes/100);

    //Muestra por pantalla:
    cout << "\nEl total es de: " << total;

    /*
    En la asignación que calcula la variable total, ¿se podría sustituir dicha variable por
    capital? es decir:
        capital = capital + capital * interes / 100;

    Si se podría usar la misma varible capital
    ya que machaca su valor inicial por el resultado
    de la operación.
    */

}
