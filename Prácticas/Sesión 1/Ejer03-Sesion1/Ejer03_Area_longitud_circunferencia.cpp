/*
Cree un programa que nos pida la longitud del radio y calcule el área del círculo y la
longitud de la circunferencia correspondientes. Finalmente, el programa mostrará en
pantalla los resultados. Recuerde que:
    long. circunf = 2PIr área circ = PIr2
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const float PI = 3.1415927;
    float radio = 0;
    float long_circunferencia = 0; //Longitud de la cincunferencia
    float area_circulo = 0; //Área del circulo

    //Muestra por pantalla
    cout << "Introduce la longitud del radio: ";
    //Se introduce el radio por taclado
    cin >> radio;

    //Cálculo de la longitud de la circunferencia
    long_circunferencia = 2 * (PI*radio);
    //Cálculo del área del círculo
    area_circulo = PI * pow(radio,2);

    //Muestra por pantalla
    cout << "\nÁrea del círculo: " << area_circulo;
    cout << "\nLongitud de la circunferencia: " << long_circunferencia;
}
