/*
Recupere la solución del ejercicio 10 (función gaussiana) de la relación de problemas
I. Se pide construir un programa para imprimir el resultado de aplicar dicha función a
varios valores de abscisas.
En primer lugar, se leerán los parámetros que definen la función, es decir, la esperanza
y la desviación. La esperanza puede ser cualquier valor, pero para leer el valor de
desviación debe utilizar un bucle y obligar a que sea mayor o igual que cero.
A continuación el programa pedirá un valor minimo , un valor maximo y un
incremento . El valor maximo ha de leerse con un filtro de entrada obligando a que
sea mayor que minimo . El programa mostrará el valor de la función gaussiana en
todos los valores de x (la abscisa) entre minimo y maximo a saltos de incremento,
es decir, minimo , minimo + incremento , minimo + 2*imcremento...hasta maximo.

*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const float PI = 3.1416;
    float media, desv_tipica, abscisa, gaussiana, maximo, minimo,
        incremento;

    //Se introducen por teclado los valores
    cout << "Introduce la media: ";
    cin >> media;

    do{
        cout << "Introduce la desviación típica: ";
        cin >> desv_tipica;
    }while(desv_tipica < 0);

    cout << "Introduce un valor mínimo: ";
    cin >> minimo;

    do{
        cout << "Introduce un valor máximo: ";
        cin >> maximo;
    }while(maximo < minimo);

    cout << "Introduce el incremento: ";
    cin >> incremento;

    abscisa = minimo;

    while(incremento <= maximo){
        //Cálculo de la función gaussiana
        gaussiana = 1/(desv_tipica*(sqrt(2*PI)))*exp(-0.5*pow((abscisa-media)/desv_tipica, 2));
        cout << "El resultado de la función gaussiana es: " << gaussiana << endl;
        abscisa = minimo + incremento;
        incremento += incremento;
    }
}
