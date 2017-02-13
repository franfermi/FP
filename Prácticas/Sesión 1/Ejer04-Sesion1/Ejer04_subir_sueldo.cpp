/*
Construya un programa para leer el valor de una variable salario_base de tipo
double, la incremente un 2% e imprima el resultado en pantalla. Para realizar este
cómputo, multiplique por 1.02 el valor original. Para resolver este ejercicio tiene varias
alternativas:
    a) Directamente hacer el cómputo 1.02 * salario_base dentro de la sentencia
    cout
    b) Introducir una variable salario_final, asignarle la expresión anterior y mostrar
    su contenido en la sentencia cout
    c) Modificar la variable original salario_base con el resultado de incrementarla
    un 2%.
*/
#include <iostream>

using namespace std;

int main()
{
    const float INCREMENTO = 1.02;
    float salario_base;
    float salario_final;

    //Muestra por pantalla
    cout << "Introduce el salario base: ";
    //Se introduce por teclado el salario base
    cin >> salario_base;

    // a)
    //Muestra por pantalla el salario final y en la misma instrucción se realiza el incremento
    cout << "\nEl salario final es: " << salario_base * INCREMENTO;

    // b)
    //Se calcula el salario final según su salario base por el incremento
    salario_final = salario_base * INCREMENTO;
    //Muestra por pantalla
    cout << "\nEl salario final es: " << salario_final;

    //c)
    //Se calcula el salario base según el propio salario base por el incremento
    salario_base = salario_base * INCREMENTO;
    //Se muestra el salario final
    cout << "\nEl salario final es: " << salario_base;

}
