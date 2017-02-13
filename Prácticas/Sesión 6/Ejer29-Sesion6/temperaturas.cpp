/*
Construya un programa que calcule cuándo se produjo la mayor secuencia de días
consecutivos con temperaturas crecientes. El programa leerá una secuencia de reales
representando temperaturas, hasta llegar al -1 y debe calcular la subsecuencia de
números ordenada, de menor a mayor, de mayor longitud.
El programa nos debe decir la posición donde comienza la subsecuencia y su longitud.
*/
//NO FUNCIONA DEL TODO BIEN
#include <iostream>

using namespace std;

int main()
{
    double temperaturas=0, aux_temp=0;
    int long_secuencia=0, posicion=0, cont=0, mayor_subsecuencia;
    bool primera_vez = true;

        cout << "Introduce la temperatura: ";
        cin >> temperaturas;
        cont++;
        long_secuencia++;

        while(temperaturas != -1){
        	//Si la temperatura actual es mayor a la anterior
            if(temperaturas > aux_temp){
            	//Comprobamos que es una nueva secuencia
                if(primera_vez){
                    posicion = cont;
                    primera_vez = false;
                }else
                    long_secuencia++;
                //Si la longitud de la secuencia es mayor que la anterior
                //actualizamos la mayor subsecuencia
                if(long_secuencia > mayor_subsecuencia)
                        mayor_subsecuencia = long_secuencia;
            }else
                primera_vez = true;
            //Almacenamos el valor de temperaturas para la posterior comprobación
            aux_temp = temperaturas;

            cout << "Introduce la temperatura: ";
            cin >> temperaturas;
            cont++;
        }

    cout << posicion << " " << mayor_subsecuencia;
}
