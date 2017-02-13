/*
Modifique la solución del ejercicio 6 para que también aplique una subida del 3% a los
que han resuelto entre 20 y 30 casos:
Entre 20 y 30 casos resueltos:       +3%
Más de 30 casos resueltos:           +4%
Grado de satisfacción >= 4:          +2%
*/
#include <iostream>

using namespace std;

int main()
{
    double salarioHora, salarioI, salario, satisfaccion, subida, subida2;
    int horas, casos_resueltos;

    cout << "Introduce el salario por hora: ";
    cin >> salarioHora;

    cout << "Introduce el número de horas: ";
    cin >> horas;

    cout << "Introduce el número de casos resueltos: ";
    cin >> casos_resueltos;

    cout << "Introduce el grado de satisfacción: ";
    cin >> satisfaccion;

    salario = salarioHora * horas;
    salarioI = salario;


    if(casos_resueltos > 30){
        subida = (salario * 4) / 100;

        if (satisfaccion >= 4.0){
            subida2 = (salarioI * 2) / 100;
            salario += subida + subida2;
        }else
            salario += subida;

    }else if(casos_resueltos >= 20 && casos_resueltos <= 30){
        subida = (salario * 3) / 100;

        if (satisfaccion >= 4.0){
            subida2 = (salarioI * 2) / 100;
            salario += subida + subida2;
        }else
            salario += subida;
    }



    cout << "El salario final es de : " << salario;
}

