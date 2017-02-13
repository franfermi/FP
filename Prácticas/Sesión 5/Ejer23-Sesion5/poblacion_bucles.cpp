/*
Amplie el ejercicio 12 (Población) de la relación de problemas I.
Esta nueva versión del programa, además de los datos ya pedidos en dicho ejercicio,
se le pedirá al usuario que introduzca un número de años (será el último dato leído)
Debe leer cada dato con un filtro conveniente. Por ejemplo, las tasas de natalidad,
mortalidad y emigración deben ser enteros entre 0 y 1000, mientras que la población
inicial debe ser un entero positivo.
El programa debe calcular e imprimir el número total de habitantes transcurridos di-
chos años.
Además, el programa también calculará el número de años que tienen que pasar
hasta que haya, como mínimo, el doble de la población inicial. Imprima dicho número
de años, junto con la población que habrá pasado ese tiempo.
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long poblacion_inicial, poblacion_final, poblacion_doble;
    int tasa_natalidad, tasa_mortalidad, tasa_migracion, tasa_global;
    double variacion_tasa_global;
    float anios;

    do{
        cout << "Introduce la población inicial: ";
        cin >> poblacion_inicial;
    }while(poblacion_inicial < 0);

    do{
        cout << "Introduce la tasa de natalidad: ";
        cin >> tasa_natalidad;

        cout << "Introduce la tasa de mortalidad: ";
        cin >> tasa_mortalidad;

        cout << "Introduce la tasa de migración: ";
        cin >> tasa_migracion;
    }while((tasa_natalidad < 0 || tasa_natalidad > 1000) || (tasa_mortalidad < 0 || tasa_mortalidad > 1000)
            || (tasa_migracion < 0 || tasa_migracion > 1000));

    cout << "Introduce el número de años: ";
    cin >> anios;

    tasa_global = tasa_natalidad - tasa_mortalidad + tasa_migracion;
    variacion_tasa_global = 1 + tasa_global / 1000.0;
    poblacion_final = poblacion_inicial * pow(variacion_tasa_global, anios);

    poblacion_doble = poblacion_final;

    while(poblacion_doble < (poblacion_inicial*2)){
        poblacion_doble *= variacion_tasa_global;
        anios++;
    }

    cout << "La población final pasados " << anios << " años es de: " << poblacion_final << endl;
    cout << "Años que tienen que pasar para doblar la población: " << cont_anios << endl;
    cout << "La población transcurridos " << anios << " es: " << poblacion_doble;
}
