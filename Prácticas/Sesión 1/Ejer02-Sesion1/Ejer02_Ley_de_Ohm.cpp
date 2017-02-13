/*
Cree un programa que pida un valor de intensidad y resistencia e imprima el voltaje
correspondiente, según la Ley de Ohm:
    voltaje = intensidad * resistencia
*/
#include <iostream>

using namespace std;

int main()
{
    float voltaje;
    float resistencia;
    float intensidad;

    //Muestra por pantalla
    cout << "Introduce la intensidad: ";
    //Se introduce por teclado el valor de la intensidad
    cin >> intensidad;

    //Muestra por pantalla
    cout << "Introduce la resistencia: ";
    //Se introduce por teclado el valor de la resistencia
    cin >> resistencia;

    //Cálculo de la ley de Ohm
    voltaje = intensidad * resistencia;

    //Muestra por pantalla el voltaje obtenido
    cout << "El voltaje es: " << voltaje << "V" << endl;
}
