/*
Se quiere construir un programa para leer los datos necesarios del ejercicio 11 de la
subida salarial.
Supondremos que sólo hay tres empleados y que están identificados con un código
(1, 2 y 3). Además, el salario por hora es el mismo para todos los empleados. Éste
será el primer valor que se leerá (de tipo double ) Después de haber leído este dato,
se leerán los datos de los casos atendidos por los empleados en el siguiente orden:
en primer lugar, el código del empleado, a continuación el número de segundos que
ha durado la atención telefónica, en tercer lugar un 1 si el caso se resolvió de forma
satisfactoria y un 0 en caso contrario; finalmente, un valor entero entre 0 y 5 con el
grado de satisfacción del usuario.
Cuando nos encontremos el terminador -1 como primer dato (código del empleado)
se detendrá la introducción de datos. Supondremos que siempre se introduce al me-
nos el primer valor (el salario), pudiendo ser ya el siguiente dato leído el terminador.
*/
#include <iostream>

using namespace std;

int main()
{
    double salarioHora, satisfaccion, satisfaccion_emp1, satisfaccion_emp2,
            satisfaccion_emp3, media_satisfaccion1, media_satisfaccion2,
            media_satisfaccion3, mayor_satisfaccion;
    int horas, num_segundos, numEmpleados = 3, codEmpleado,
        resolucion, num_casos=0, num_casos1=0, num_casos2=0, num_casos3=0;

    cout << "Introduce el salario por hora: ";
    cin >> salarioHora;

    cout << "Introduce el código del empleado (1-3): ";
    cin >> codEmpleado;

    while(codEmpleado != -1){
        cout << "Introduce el número de seg de la atención telefónica: ";
        cin >> num_segundos;

        do{
            cout << "Introduce la resolución de la llamada (0-1): ";
            cin >> resolucion;
        }while(resolucion < 0 || resolucion > 1);

        do{
            cout << "Introduce el grado de satisfacción del usuario (0-5): ";
            cin >> satisfaccion;
        }while(satisfaccion < 0 || satisfaccion > 5);

        if(codEmpleado == 1){
            satisfaccion_emp1 += satisfaccion;
            num_casos1++;
        }else if(codEmpleado == 2){
            satisfaccion_emp2 += satisfaccion;
            num_casos2++;
            }else{
                satisfaccion_emp3 += satisfaccion;
                num_casos3++;
            }
        num_casos++;

        cout << "Introduce el código del empleado (1-3): ";
        cin >> codEmpleado;
    }

    //Introducir las condiciones de si las satisfacciones
    //y los numeros de casos son igual a 0
    media_satisfaccion1 = satisfaccion_emp1 / num_casos1;
    media_satisfaccion2 = satisfaccion_emp2 / num_casos2;
    media_satisfaccion3 = satisfaccion_emp3 / num_casos3;

    if(satisfaccion_emp1 > satisfaccion_emp2 && satisfaccion_emp1 > satisfaccion_emp3){
        codEmpleado = 1;
        mayor_satisfaccion = media_satisfaccion1;
    }
    else if(satisfaccion_emp2 > satisfaccion_emp1 && satisfaccion_emp2 > satisfaccion_emp3){
        codEmpleado = 2;
        mayor_satisfaccion = media_satisfaccion2;
    }
        else{
            codEmpleado = 3;
            mayor_satisfaccion =  media_satisfaccion3;
        }

    cout << "Número de casos: " << num_casos << endl;
    cout << "El empleado con mayor grado de satisfacción: " << codEmpleado << endl;
    cout << "El grado medio de satisfacción del emplado es: " << mayor_satisfaccion << endl;
}
