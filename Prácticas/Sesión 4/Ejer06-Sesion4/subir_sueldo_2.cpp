/*
Recupere la solución del ejercicio 5 sobre el cómputo de la nómina de los trabajadores
de un centro de atención telefónica. Implemente ahora el siguiente criterio para la
subida salarial. Se aplicará una subida del 4% a los empleados que han resuelto más
de 30 casos y una subida del 2% si el grado de satisfacción media de los usuarios
es mayor o igual que 4.0 . Ambas subidas son compatibles, es decir, si un trabajador
cumple las dos condiciones, se le aplicarán ambas subidas.
Resuelva este ejercicio considerando que la nueva subida del 2% se realiza sobre el
salario inicial y no sobre el resultado de haber aplicado, en su caso, la otra subida del
4% .
    Más de 30 casos resueltos:      +4%
    Grado de satisfacción >= 4:     +2%
*/
#include <iostream>

using namespace std;

int main()
{
    double salarioHora, salario, satisfaccion, subida, subida2;
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

    if(casos_resueltos > 30 && !(satisfaccion >= 4.0)){
        subida = (salario * 4) / 100;
        salario += subida;
    }

    if(satisfaccion >= 4.0 && !(casos_resueltos > 30)){
        subida = (salario * 2) / 100;
        salario += subida;
    }

    if(casos_resueltos > 30 && satisfaccion >= 4.0){
        subida = (salario * 4) / 100;
        subida2 = (salario * 2) / 100;
        salario += subida + subida2;
    }

    cout << "El salario final es de : " << salario;
}
