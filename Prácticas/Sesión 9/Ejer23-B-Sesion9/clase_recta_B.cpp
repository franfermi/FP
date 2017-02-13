/*
b) Métodos públicos
En vez de calcular la pendiente en el programa principal, vamos a ponerlo como
un método de la clase y así lo reutilizaremos todas las veces que necesitemos.
Añada un método para el cálculo de la pendiente y modifique el main para tener
en cuenta este cambio.
¿Añadimos pendiente como dato miembro de la recta? La respuesta es que
no ¿Por qué?
Añada también los siguiente métodos:
• Obtener la ordenada ( y ) dado un valor de abscisa x , aplicando la fórmula:
(-C -xA) / B
• Obtener la abscisa ( x ) dado un valor de ordenada y , aplicando la fórmula:
(-C -yB) / A
En la función main lea un valor de abscisa e imprima la ordenada según la recta.
A continuación lea un valor de ordenada e imprima la abscisa que le corresponde.
Hágalo sólo con la primera recta.
*/
#include <iostream>

using namespace std;

class Recta{
public:
    float A, B, C;
    float x, y;
    float Pendiente(float a, float b){
        float pendiente;
        pendiente = -a / b;

        return pendiente;
    }

    float Ordenada_Y(float a, float b, float c, float x){
        float ordenada_y;
        ordenada_y = (-c * (-x*a)) / b;

        return ordenada_y;
    }

    float Abscisa_X(float a, float b, float c, float y){
        float abscisa_x;
        abscisa_x = (-c * (-y*a)) / b;

        return abscisa_x;
    }
};

int main()
{
    Recta obj_recta1;
    Recta obj_recta2;
    float pendiente1, pendiente2;
    float abscisa_x, ordenada_y;

    cout << "Introduce el coeficiente A de la primera recta: ";
    cin >> obj_recta1.A;

    cout << "Introduce el coeficiente B de la primera recta: ";
    cin >> obj_recta1.B;

    cout << "Introduce el coeficiente C de la primera recta: ";
    cin >> obj_recta1.C;

    cout << "Introduce el coeficiente A de la segunda recta: ";
    cin >> obj_recta2.A;

    cout << "Introduce el coeficiente B de la segunda recta: ";
    cin >> obj_recta2.B;

    cout << "Introduce el coeficiente C de la segunda recta: ";
    cin >> obj_recta2.C;

    cout << "Introduce un valor de abscisa: ";
    cin >> obj_recta1.x;

    cout << "Introduce ordenada y: ";
    cin >> obj_recta1.y;

    pendiente1 = obj_recta1.Pendiente(obj_recta1.A, obj_recta1.B);
    pendiente2 = obj_recta2.Pendiente(obj_recta2.A, obj_recta2.B);
    ordenada_y = obj_recta1.Ordenada_Y(obj_recta1.A, obj_recta1.B, obj_recta1.C, obj_recta1.x);
    abscisa_x = obj_recta1.Abscisa_X(obj_recta1.A, obj_recta1.B, obj_recta1.C, obj_recta1.y);

    cout << "La pendiente de la recta 1 es: " << pendiente1 << endl;
    cout << "La pendiente de la recta 2 es: " << pendiente2 << endl << endl;

    cout << "La ordenada de Y es: " << ordenada_y << endl;
    cout << "La abscisa de X es: " << abscisa_x << endl;

}
