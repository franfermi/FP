#include <iostream>

using namespace std;

int main()
{
    bool letraSi, edadSi, adivineSi, anioSi;
    char letra;
    short edad;
    short adivine;
    int anio;

    cout << "Introduce letra: ";
    cin >> letra;

    cout << "Introduce edad: ";
    cin >> edad;

    cout << "Introduce adivine: ";
    cin >> adivine;

    cout << "Introduce anio: ";
    cin >> anio;

    /*
    Escriba una expresión lógica que sea verdadera si una variable de tipo carácter llama-
    da letra es una letra minúscula y falso en otro caso.
    */
    letraSi = letra >= 'a' && letra <= 'z';
    /*
    Escriba una expresión lógica que sea verdadera si una variable de tipo entero llamada
    edad es menor de 18 o mayor de 65.
    */
    edadSi = edad < 18 || edad > 65;
    /*
    Escriba una expresión lógica que sea verdadera si una variable de tipo entero llamada
    adivine está entre 1 y 100.
    */
    adivineSi = adivine >= 1 && adivine <= 100;
    /*
    Escriba una expresión lógica que sea verdadera si un año es bisiesto. Los años bisies-
    tos son aquellos que o bien son divisibles por 4 pero no por 100, o bien son divisibles
    por 400.
    */
    anioSi = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;

    cout << letraSi << " " << edadSi << " " << adivineSi
        << " " << anioSi;
}
