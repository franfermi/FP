/*
Escriba un programa que calcule la estimación de la población de un territorio después
de tres años. Para ello, el programa debe leer la población inicial, la tasa de natalidad,
la de mortalidad y la tasa de migración. Ésta última es la diferencia entre los que se
van y los que vienen, por lo que puede ser o bien positiva o bien negativa.
Suponga que todos los datos son enteros.
Tenga en cuenta que una vez calculada la población que habrá el siguiente año, las
tasas se vuelven a aplicar sobre la población así obtenida, y así sucesivamente, tantos
años como estemos interesados.
Ejemplo de entrada: 1375570814 32 12 7 -- Salida correcta: 1596949197
*/
#include <iostream>

using namespace std;

int main()
{
    float poblacion_inicial, tasa_natalidad, tasa_mortalidad, tasa_migracion;
    float total_natalidad, total_mortalidad, total_migracion, poblacion_final;
    float anios=0;

    cout << "Introduce la población inicial: ";
    cin >> poblacion_inicial;

    cout << "Introduce la tasa de natalidad: ";
    cin >> tasa_natalidad;

    cout << "Introduce la tasa de mortalidad: ";
    cin >> tasa_mortalidad;

    cout << "Introduce la tasa de migración: ";
    cin >> tasa_migracion;

    //Cálculo total de las tasas junto con la población final en el primer año
    total_natalidad = poblacion_inicial * (tasa_natalidad / 1000);
    total_mortalidad = poblacion_inicial * (tasa_mortalidad / 1000);
    total_migracion = poblacion_inicial * (tasa_migracion / 1000);

    poblacion_final = poblacion_inicial + total_migracion + total_mortalidad + total_natalidad;

    //Cálculo total de las tasas junto con la población final en el segundo año
    total_natalidad = poblacion_final * (tasa_natalidad / 1000);
    total_mortalidad = poblacion_final * (tasa_mortalidad / 1000);
    total_migracion = poblacion_final * (tasa_migracion / 1000);

    poblacion_final = poblacion_final + total_migracion + total_mortalidad + total_natalidad;

    //Cálculo total de las tasas junto con la población final en el tercer año
    total_natalidad = poblacion_final * (tasa_natalidad / 1000);
    total_mortalidad = poblacion_final * (tasa_mortalidad / 1000);
    total_migracion = poblacion_final * (tasa_migracion / 1000);

    poblacion_final = poblacion_final + total_migracion + total_mortalidad + total_natalidad;

    cout << "La población final es de: " << poblacion_final;
}
