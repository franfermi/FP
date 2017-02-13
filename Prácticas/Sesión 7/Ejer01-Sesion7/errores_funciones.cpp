/*
Encuentre los errores de las siguientes funciones:
*/
#include <iostream>

using namespace std;

    int ValorAbsoluto(int entero){
        if(entero < 0)
            entero = -entero;
        else
            return entero;
    }
    /*
    Si el entero pasado por parámetros es <0
    la funcion no devuelve nada porque el return
    se encuentra en el else, y solo devuelve un valor
    cuando entero es >=0.
    */

    void Imprime(double valor){
        double valor;

        cout << valor;
    }
    /*
    Tenemos un conflicto de nombre ya que el parámetro
    de la función y la variable local tienen el mismo nombre.
    */

    void Cuadrado(int entero){
        return entero*entero;
    }
    /*
    La función está declarada como tipo void, es decir,
    no devuelve nada por tanto no debe aparecer ningún
    return.
    */

    bool EsPositivo(int valor){
        if(valor > 0)
            return true;
    }
    /*
    La función tiene que devolver un bool, y en este
    caso solo lo devolvería en el caso en que valor
    sea > 0, para otro caso no devuelve nada.
    */
