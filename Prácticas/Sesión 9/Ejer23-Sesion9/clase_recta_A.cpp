/*
a) Definición de la clase y creación de objetos
Defina la clase Recta . En este apartado utilice únicamente datos miembro públi-
cos. Cree un programa principal que haga lo siguiente:
• Defina dos objetos de la clase Recta .
• Lea seis reales desde teclado.
• Le asigne los tres primeros a los coeficientes de una recta y los otros tres a
la segunda recta.
• Calcule e imprima la pendiente de cada recta aplicando la fórmula:
pendiente = - A / B
*/
#include <iostream>

using namespace std;

class Recta{
public:
    float A, B, C;
    float x, y;
};

int main()
{
    Recta obj_recta1;
    Recta obj_recta2;
    float pendiente1, pendiente2;

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

    pendiente1 = -obj_recta1.A / obj_recta1.B;
    pendiente2 = -obj_recta2.A / obj_recta2.B;

    cout << "La pendiente de la recta 1 es: " << pendiente1 << endl;
    cout << "La pendiente de la recta 2 es: " << pendiente2 << endl;

}
