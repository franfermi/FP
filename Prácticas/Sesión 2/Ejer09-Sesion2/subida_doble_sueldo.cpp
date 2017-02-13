/*
Recupere la solución del ejercicio 4 (Subir sueldo usando la variable
salario_final) Además de mostrar el salario con la subida del 2% se quiere
mostrar el salario resultante de subirle otro 3% adicional (además de la subida del 2%)
El programa debe mostrar los salarios resultantes de ambas subidas.
*/
#include <iostream>

using namespace std;

int main()
{
    const float INCREMENTO1 = 1.02, INCREMENTO2 = 1.03;
    float salario_base;
    float salario_final;

    //Muestra por pantalla
    cout << "Introduce el salario base: ";
    //Se introduce por teclado el salario base
    cin >> salario_base;

    //Se calcula el salario final según su salario base por el incremento
    salario_final = salario_base * INCREMENTO1;
    //Muestra por pantalla
    cout << "\nEl salario con el primer incremento es: " << salario_final;

    salario_final = salario_final * INCREMENTO2;
    //Se muestra el salario final según el salario con el primer incremento por el segundo incremento
    cout << "\nEl salario con el segundo incremento es: " << salario_final;
}
