/*
Construya un programa que lea desde teclado tres variables correspondientes a un
número de horas, minutos y segundos, respectivamente. A continuación, el programa
debe calcular las horas, minutos y segundos dentro de su rango correspondiente. Por
ejemplo, dadas 312 horas, 119 minutos y 1291 segundos, debería dar como resultado
13 días, 2 horas, 20 minutos y 31 segundos. El programa no calculará meses, años,
etc. sino que se quedará en los días.
Como consejo, utilice el operador / que cuando trabaja sobre datos enteros, obtiene
la división entera. Para calcular el resto de la división entera, use el operador % .
Ejemplo de entrada: 312 119 1291 −− Salida correcta: 13 2 20 31
*/
#include <iostream>

using namespace std;

int main()
{
    const int SEG_MIN = 60;
    const int MIN_HORA = 60;
    const int HORAS_DIA = 24;
    int horas, minutos, segundos;
    int total_dias, total_horas, total_minutos, total_segundos;
    int resto_horas, resto_minutos, resto_segundos;

    cout << "Introduce el número de horas: ";
    cin >> horas;

    cout << "Introduce el número de minutos: ";
    cin >> minutos;

    cout << "Introduce el número de segundos: ";
    cin >> segundos;

    //Cociente y resto de los segundos
    total_segundos = segundos / SEG_MIN;
    resto_segundos = segundos % SEG_MIN;

    //Cociente y resto de los minutos
    total_minutos = (minutos + total_segundos) / MIN_HORA;
    resto_minutos = (minutos + total_segundos) % MIN_HORA;

    //Cociente y resto de las horas
    total_horas = (horas + total_minutos) / HORAS_DIA;
    resto_horas = (horas + total_minutos) % HORAS_DIA;

    total_dias = total_horas;

    cout << "\nDías: " << total_horas
            << "\nHoras: " << resto_horas
            << "\nMinutos: " << resto_minutos
            << "\nSegundos: " << resto_segundos;

}
