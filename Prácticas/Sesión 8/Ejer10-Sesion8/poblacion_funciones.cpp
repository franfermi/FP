/*
Retome la solución del ejercicio 23 (población) de la Relación de Problemas II. Re-
escríbalo usando las funciones LeeIntRango del ejercicio 4 para leer los valores
de las tasas y LeeIntMayorIgualQue del ejercicio 5 para leer el número de años
que sea positivo. Defina también sendas funciones para calcular los dos valores que
se piden en el ejercicio, a saber, el número de habitantes después de tres años y
el número de años que pasarán hasta doblar la población inicial. Intente diseñar las
funciones para que sean lo más generales posible.
*/
#include <iostream>
#include <cmath>

using namespace std;

int LeeIntRango(){
    int tasa;

    do{
        cout << "Introduce la tasa: ";
        cin >> tasa;
    }while(tasa < 0 || tasa > 1000);

    return tasa;
}

float LeeIntMayorIgualQue(){
    int anios;

    do{
        cout << "Introduce los años: ";
        cin >> anios;
    }while(anios < 0);

    return anios;
}

long long PoblacionFinal(double tasa_global, long long pobl_inicial, float anios){
    long long pobl_final;

    pobl_final = pobl_inicial * pow(tasa_global, anios);

    return pobl_final;
}

float TotalAnios(long long pobl_doble, long long pobl_inicial, double tasa_global){
    float anios;

    while(pobl_doble < (pobl_inicial*2)){
        pobl_doble *= tasa_global;
        anios++;
    }

    return anios;
}

long long PoblacionFinalDoble(long long pobl_doble, long long pobl_inicial, double tasa_global){
    long long pobl_final_doble;

    pobl_final_doble = pobl_doble;

    while(pobl_final_doble < (pobl_inicial*2)){
        pobl_final_doble *= tasa_global;
    }

    return pobl_final_doble;
}

int main()
{
    long long poblacion_inicial, poblacion_final, poblacion_doble;
    int tasa_natalidad, tasa_mortalidad, tasa_migracion, tasa_global;
    double variacion_tasa_global;
    float anios, cont_anios;

    do{
        cout << "Introduce la población inicial: ";
        cin >> poblacion_inicial;
    }while(poblacion_inicial < 0);

    tasa_natalidad = LeeIntRango();
    tasa_mortalidad = LeeIntRango();
    tasa_migracion = LeeIntRango();

    anios = LeeIntMayorIgualQue();

    tasa_global = tasa_natalidad - tasa_mortalidad + tasa_migracion;
    variacion_tasa_global = 1 + tasa_global / 1000.0;
    poblacion_final = PoblacionFinal(variacion_tasa_global, poblacion_inicial, anios);

    poblacion_doble = poblacion_final;

    cont_anios = anios + TotalAnios(poblacion_doble, poblacion_inicial, variacion_tasa_global);

    poblacion_doble = PoblacionFinalDoble(poblacion_doble, poblacion_inicial, variacion_tasa_global);

    cout << "La población final pasados " << anios << " años es de: " << poblacion_final << endl;
    cout << "Años que tienen que pasar para doblar la población: " << cont_anios << endl;
    cout << "La población transcurridos " << cont_anios << " años es: " << poblacion_doble;
}
