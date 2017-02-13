/*
[k mayores que otro valor, eficiente]. Modifique la solución del ejercicio 2 usando un
algoritmo más eficiente. Observe que no hace falta ordenar todo el vector, sino única-
mente considerar los datos que son mayores que la referencia.
Aplique el siguiente algoritmo:

    Recorrer las componentes del vector original
        Si es mayor que la referencia, insertar dicho
            valor de forma ordenada en el vector "mayores_que"
        El vector "mayores_que" siempre tendrá,
        como mucho, k componentes

Mientras que la versión vista en el ejercicio 2 tardaba varios segundos, esta nueva
versión tarda menos de un segundo.
*/

#include <iostream>
using namespace std;

int main(){
   const int TERMINADOR = -1;
   double dato, referencia;
   const int TAMANIO                 =  1e5;
   double vector[TAMANIO], mayores_que[TAMANIO];
   int utilizados_vector, utilizados_mayores_que, k;


   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:

   cout << "k valores mayores que."
        << "\nIntroduzca reales con terminador "
        << TERMINADOR << "\n"
        << "Luego introduzca el valor de referencia y k.\n";

   utilizados_vector = 0;
   cin >> dato;

   while (dato != TERMINADOR && utilizados_vector < TAMANIO){
      vector[utilizados_vector] = dato;
      utilizados_vector++;
      cin >> dato;
   }

   cin >> referencia;
   cin >> k;

   int i, j, l, m, pos=0;
   double a_insertar;
    //Recorremos el vector
    for (i = 0; i < utilizados_vector; i++){
        a_insertar = vector[i];
        //Solo insertamos los valores >= a la referencia
        if(a_insertar >= referencia){
            mayores_que[pos] = a_insertar;
            pos++;
        }
    }
    //Ordeamos los elementos del vector
    for (j = 0; j < k-1; j++){
        for (l = j+1; l < k ; l++){
            if(mayores_que[j] > mayores_que[l]){
                a_insertar = mayores_que[j];
                mayores_que[j] = mayores_que[l];
                mayores_que[l] = a_insertar;
            }
        }
    }
    //Se muestra por pantalla los elementos del vector
    for (m = 0; m < k; m++)
        cout << mayores_que[m] << " ";
}



