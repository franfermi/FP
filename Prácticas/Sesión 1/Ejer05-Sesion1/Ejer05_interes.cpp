/*
Un banco presenta la siguiente oferta. Si se deposita una cantidad de euros dada por
la variable capital durante un a�o a plazo fijo, se dar� un inter�s dado por la variable
interes. Realice un programa que lea una cantidad capital y un inter�s interes
desde teclado. A continuaci�n, el programa debe calcular en una variable total el
dinero que se tendr� al cabo de un a�o, aplicando la f�rmula de abajo e imprimir� el
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
    cout << "\nIntroduce el inter�s: ";
    //Se introduce por teclado el interes
    cin >> interes;

    //C�lculo del salario total
    total = capital + capital * (interes/100);

    //Muestra por pantalla:
    cout << "\nEl total es de: " << total;

    /*
    En la asignaci�n que calcula la variable total, �se podr�a sustituir dicha variable por
    capital? es decir:
        capital = capital + capital * interes / 100;

    Si se podr�a usar la misma varible capital
    ya que machaca su valor inicial por el resultado
    de la operaci�n.
    */

}
