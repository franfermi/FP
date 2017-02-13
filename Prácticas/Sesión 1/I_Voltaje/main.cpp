#include <iostream>

using namespace std;

int main()
{
    float voltaje;
    float resistencia;
    float intensidad;

    cout << "Introduce la intensidad: ";
    cin >> intensidad;

    cout << "Introduce la resistencia: ";
    cin >> resistencia;

    voltaje = intensidad * resistencia;

    cout << "El voltaje es: " << voltaje << "V" << endl;
}
