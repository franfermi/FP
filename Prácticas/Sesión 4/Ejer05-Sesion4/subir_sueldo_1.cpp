/*
Queremos gestionar la nómina de los empleados de un centro de atención telefónica.
Construya un programa que lea el salario por hora (dato de tipo real) de un empleado,
el número de horas trabajadas durante el mes actual (dato de tipo entero) el número
de casos resueltos de forma satisfactoria (dato de tipo entero) y el grado medio de
satisfacción de los usuarios de los servicios telefónicos con el empleado en cuestión
(real entre 0 y 5).
Se quiere aplicar una subida salarial en función de varios factores. En ejercicios suce-
sivos se irán planteando distintas posibilidades. La primera que se quiere implementar
es la siguiente:
Se aplicará una subida del 4% a los empleados que han resuelto más de 30 casos.
    Más de 30 casos resueltos:              +4%
Imprima el salario final en pantalla.
Ejemplo de entrada: 8.5 150 32 5 −− Salida correcta: 1326
Ejemplo de entrada: 7.5 130 24 3 −− Salida correcta: 975
*/
#include <iostream>

using namespace std;

int main()
{
    double salarioHora, salario, satisfaccion, subida;
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

    if(casos_resueltos > 30){
        subida = (salario * 4) / 100;
        salario += subida;
    }

    cout << "El salario final es de : " << salario;
}
