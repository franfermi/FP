/*
Responda razonadamente a la siguiente pregunta: ¿El hecho de realizar la asignación
salario_final = salario_base; hace que ambas variables estén ligadas
durante todo el programa y que cualquier modificación posterior de salario_base
afecte a salario_final?
*/
#include <iostream>

using namespace std;

int main()
{
    int salario_base; //Salario base
    int salario_final; //Salario final
    int incremento; //Incremento del salario

    salario_base = 1000;
    salario_final = salario_base;

    incremento = 200;
    salario_final = salario_final + incremento;

    salario_base = 3500;

    cout << "\nSalario base: " << salario_base;
    cout << "\nSalario final: " << salario_final;

    /*
    -No hace que ambas variables estén ligadas durante todo el programa
    simplemente en la inicialización de salario_final se le asigna en valor
    de la inicialización de salario_base.
    */
}
