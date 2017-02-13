/*
Realice un programa que nos pida una longitud cualquiera dada en metros. El programa
deberá calcular e imprimir en pantalla el equivalente de dicha longitud en pulgadas,
pies, yardas y millas. Para el cálculo, utilice la siguiente tabla de conversión del sistema
métrico:
    1 pulgada= 25,4 milímetros
    1 pie = 30,48 centímetros
    1 yarda = 0,9144 metros
    1 milla = 1609,344 metros
*/
#include <iostream>

using namespace std;

int main()
{
    float metros, pulgada, pie, yarda, milla;

    cout << "Introduce la longitud en metros: ";
    cin >> metros;

    //Conversiones
    pulgada = (metros * 1000) / 25.4;
    pie = (metros * 100) / 30.48;
    yarda = metros / 0.9144;
    milla = metros / 1609.344;

    cout << "Conversión de " << metros << " metro/s:\n" << pulgada << " pulgadas\n"
         << pie << " pies\n" << yarda << " yardas\n" << milla << " millas\n";
}
