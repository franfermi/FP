/*
Responda razonadamente a la siguiente pregunta: �El hecho de realizar la asignaci�n
salario_final = salario_base; hace que ambas variables est�n ligadas
durante todo el programa y que cualquier modificaci�n posterior de salario_base
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
    -No hace que ambas variables est�n ligadas durante todo el programa
    simplemente en la inicializaci�n de salario_final se le asigna en valor
    de la inicializaci�n de salario_base.
    */
}
