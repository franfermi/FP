#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const float PI = 3.1416;
    float media, desv_tipica, abscisa, gaussiana;

    //Se introducen por teclado los valores
    cout << "Introduce la media: ";
    cin >> media;
    cout << "Introduce la desviación típica: ";
    cin >> desv_tipica;
    cout << "Introduce el valor de abscisa: ";
    cin >> abscisa;

    //Cálculo de la función gaussiana
    gaussiana = 1/(desv_tipica*(sqrt(2*PI)))*exp(-0.5*pow((abscisa-media)/desv_tipica, 2));

    cout << "El resultado de la función gaussiana es: " << gaussiana;
}
