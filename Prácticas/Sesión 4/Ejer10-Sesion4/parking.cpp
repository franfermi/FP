/*
La tabla para el cálculo del precio a pagar en los parkings de Madrid para el 2015 es
la siguiente:
    Si permanece más de 660 minutos se paga una única tarifa de 31.55 euros
    Desde el minuto 0 al 30: 0.0412 euros cada minuto
    Desde el minuto 31 al 90: 0.0370 euros cada minuto
    Desde el minuto 91 al 120: 0.0311 euros cada minuto
    Desde el minuto 121 al 660: 0.0305 euros cada minuto

Dado un tiempo de entrada (hora, minuto y segundo) y un tiempo de salida, construya
un programa que calcule la tarifa final a cobrar. Para calcular el número de minutos en-
tre los dos instantes de tiempo, puede utilizar la solución del ejercicio 6 de la Relación
de Problemas I.
Ejemplo de entrada: 2 1 30      2 1 29 - -Salida correcta: -1
*/
#include <iostream>

using namespace std;

int main()
{
    const int CONVERSION = 60;
    const float TARIFA1 = 0.0412, TARIFA2 = 0.0370, TARIFA3 = 0.0311,
                TARIFA4 = 0.0305, TARIFA5 = 31.55;
    int horasEntrada, minutosEntrada, segundosEntrada,
        horasSalida, minutosSalida, segundosSalida,
        horasTotal, minutosTotal, segundosTotal;
    float totalMin, precioTarifa = -1;

    cout << "Introduce la hora de entrada: ";
    cin >> horasEntrada;

    cout << "Introduce los minutos de entrada: ";
    cin >> minutosEntrada;

    cout << "Introduce los segundos de entrada: ";
    cin >> segundosEntrada;

    cout << "Introduce la hora de salida: ";
    cin >> horasSalida;

    cout << "Introduce los minutos de salida: ";
    cin >> minutosSalida;

    cout << "Introduce los segundos de salida: ";
    cin >> segundosSalida;

    horasTotal = horasSalida - horasEntrada;
    minutosTotal = minutosSalida - minutosEntrada;
    segundosTotal = segundosSalida - segundosEntrada;

    totalMin = ((horasTotal*CONVERSION) + minutosTotal + (segundosTotal/CONVERSION));

    if(totalMin > 660)
        precioTarifa = TARIFA5;

    if(totalMin >= 0 && totalMin <= 30)
        precioTarifa = totalMin * TARIFA1;

    if(totalMin >= 31 && totalMin <= 90)
        precioTarifa = totalMin * TARIFA2;

    if(totalMin >= 91 && totalMin <= 120)
        precioTarifa = totalMin * TARIFA3;

    if(totalMin >= 121 && totalMin <= 660)
        precioTarifa = totalMin * TARIFA4;

    cout << "El precio a pagar es: " << precioTarifa << "€";

}
