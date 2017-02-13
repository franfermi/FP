/*
Se pide leer dos enteros min y max que representarán un rango de valores
[min,max] . El primer valor a leer, min , debe ser un número positivo y el segun-
do valor max , debe ser mayor que min . El programa irá leyendo estos dos valores
hasta que el usuario los introduzca correctamente.
Una vez leídos ambos valores, el programa pedirá otro entero nuevo obligando a que
esté dentro del intervalo [min, max] . Si el usuario introduce más de 3 valores fuera
del rango, el bucle terminará y se mostrará en pantalla un mensaje indicando que
superó el número de intentos máximo. En caso contrario (el usuario introduce un valor
en el rango pedido), se mostrará en pantalla el resultado de calcular nuevo - min y
max - nuevo .
Debe resolver este problema separando los bloques de Entrada/Salida de los de
Cómputos.
*/
#include <iostream>

using namespace std;

int main()
{
    const int LIMITE_INTENTOS = 3;
    int min, max, valor_intervalo, cont_valores = 0;
    bool salir = false;

    do{
        cout << "Introduce el valor min: ";
        cin >> min;
    }while(min < 0);

    do{
        cout << "Introduce el valor max (debe ser mayor que min): ";
        cin >> max;
    }while(min > max);

    do{
        cout << "Introduce un valor que se encuentre en el intervalo: ";
        cin >> valor_intervalo;
        cont_valores++;
        if(valor_intervalo >= min && valor_intervalo <= max)
            salir = false;
        else if(cont_valores == LIMITE_INTENTOS)
            salir = true;
    }while((valor_intervalo < min || valor_intervalo > max) && !salir);

    if(salir)
        cout << "Se superó el número de intentos válidos";
    else
        cout << valor_intervalo - min << " " << max - valor_intervalo;
}
