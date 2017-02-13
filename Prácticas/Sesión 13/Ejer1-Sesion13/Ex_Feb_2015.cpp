/*
(Examen Febrero 2015) En este ejercicio no hay que construir ninguna función o clase.
Todo se programará en el main . Defina dos matrices de reales original y suavizada de
tamaño 50 x 30 . Lea desde teclado los valores de la matriz original , obligando a que
sea simétrica. Para ello, lea el número de filas n y a continuación introduzca los n x n
datos de la matriz. Construya la matriz suavizada acorde a las siguientes indicaciones:
    a) La tabla resultante será simétrica.
    b) Los valores de la diagonal principal de la tabla resultante serán iguales a los de
       la tabla original.
    c) Los valores del triángulo superior de la tabla resultante se calculan de la si-
       guiente manera: si (i, j) es una posición en el triángulo superior de la tabla re-
       sultante, su valor es el valor medio de los valores que ocupan las posiciones de
       las columnas j, j + 1, ..., n − 1 en la fila i de la tabla original.
*/
#include <iostream>

using namespace std;

int main()
{
    const int FIL = 50, COL = 30;
    double original[FIL][COL];
    double suavizada[FIL][COL];
    int filas, cont;
    double valor_medio;

    cout << "Introduce el número de filas: ";
    cin >> filas;

    cout << "Introduce elementos en la matriz de " << filas << "x" << filas << endl;

    for(int i=0; i<filas; i++)
        for(int j=0; j<filas; j++)
            cin >> original[i][j];

    cout << "\nMatriz suavizada" << endl;

    //Insertamos la diagonal
    int j = 0;
    for(int i=0; i<filas; i++){
        j = i;
        suavizada[i][j] = original[i][j];
    }

    //Insertamos el triangulo inferior
    for(int i=1; i<filas; i++){
        for(int j=0; j<filas; j++){
            if(i>=j)
                suavizada[i][j] = original[i][j];
        }
    }

    //Insertamos el triangulo superior
    for(int i=0; i<filas; i++){
        for(int j=i+1; j<filas; j++){
            if(j>i){
                for(int k=j; k<filas; k++){
                    valor_medio += original[i][k];
                    cont++;
                }
                suavizada[i][j] = valor_medio / cont;
                valor_medio = cont = 0;
            }
        }
    }

    //Mostramos la matriz suavizada
    for(int i=0; i<filas; i++){
        for(int j=0; j<filas; j++)
            cout << suavizada[i][j] << " | ";
        cout << endl;
    }
}
