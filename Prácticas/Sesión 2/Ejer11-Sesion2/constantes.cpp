/*
Re-escriba las soluciones de los ejercicios 3, 9, 6, 10 (circunferencia, subir sueldo,
diferencia de tiempo, gaussiana) utilizando datos de tipo constante en aquellos sitios
donde considere oportuno.
*/
#include <iostream>

using namespace std;

int main()
{
    //Ejercicio 3
    /*
    La variable PI la ponemos constante ya que su valor es constante
    y no se modifica en el programa.
    */
    const float PI = 3.1415927;

    //Ejercicio 6
    /*
    En el calculo total de los segundos, se utiliza el valor 60 para
    la cnversión a minutos y a segundos, como es un valor que no cambia
    se puede declarar como una variable constante.
    */
    const int CONVERSION = 60;

    //Ejercicio 9
    /*
    Las variables que corresponden a los incrementos del 2% y 3%
    las declaramos como constantes ya que su valor no se va a modificar
    en el programa.
    */
    const float INCREMENTO1 = 1.02, INCREMENTO2 = 1.03;

    //Ejercicio 10
    /*
    Al igual que en el ejercicio 3, la variable PI la ponemos constante
    ya que no va a cambiar su valor en el programa.
    */
    const float PI = 3.1416;

}
