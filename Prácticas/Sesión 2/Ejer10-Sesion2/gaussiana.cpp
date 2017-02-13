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
    cout << "Introduce la desviaci�n t�pica: ";
    cin >> desv_tipica;
    cout << "Introduce el valor de abscisa: ";
    cin >> abscisa;

    //C�lculo de la funci�n gaussiana
    gaussiana = 1/(desv_tipica*(sqrt(2*PI)))*exp(-0.5*pow((abscisa-media)/desv_tipica, 2));

    cout << "El resultado de la funci�n gaussiana es: " << gaussiana;
}
