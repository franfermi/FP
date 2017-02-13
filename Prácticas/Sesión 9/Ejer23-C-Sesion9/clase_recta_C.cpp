/*
c) Datos miembro privados
Cambie ahora los datos miembro públicos y póngalos privados. Tendrá que añadir
métodos para asignar y ver los valores de los datos miembro. Añada métodos
para asignar un valor a cada uno de los tres datos miembro. Modifique el main
para tener en cuenta estos cambios.
*/
#include <iostream>

using namespace std;

class Recta{
    private:
        float A, B, C;
        float x, y;
    public:
        Recta(){
            A = B = C = 0;
            x = y = 0;
        }

        float GetA(){
            return this->A;
        }

        void SetA(float a){
            this->A = a;
        }

        float GetB(){
            return this->B;
        }

        void SetB(float b){
            this->B = b;
        }

        float GetC(){
            return this->C;
        }

        void SetC(float c){
            this->C = c;
        }

        float GetX(){
            return this->x;
        }

        void SetX(float x){
            this->x = x;
        }

        float GetY(){
            return this->y;
        }

        void SetY(float y){
            this->y = y;
        }

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
    float pendiente1, pendiente2, a1, b1, c1, a2, b2, c2, x1, y1;
    float abscisa_x, ordenada_y;

    cout << "Introduce el coeficiente A de la primera recta: ";
    cin >> a1;

    cout << "Introduce el coeficiente B de la primera recta: ";
    cin >> b1;

    cout << "Introduce el coeficiente C de la primera recta: ";
    cin >> c1;

    cout << "Introduce el coeficiente A de la segunda recta: ";
    cin >> a2;

    cout << "Introduce el coeficiente B de la segunda recta: ";
    cin >> b2;

    cout << "Introduce el coeficiente C de la segunda recta: ";
    cin >> c2;

    cout << "Introduce un valor de abscisa: ";
    cin >> x1;

    cout << "Introduce ordenada y: ";
    cin >> y1;

    obj_recta1.SetA(a1);
    obj_recta1.SetB(b1);
    obj_recta1.SetC(c1);
    obj_recta2.SetA(a2);
    obj_recta2.SetB(b2);
    obj_recta2.SetC(c2);
    obj_recta1.SetX(x1);
    obj_recta1.SetY(y1);


    pendiente1 = obj_recta1.Pendiente(obj_recta1.GetA(), obj_recta1.GetB());
    pendiente2 = obj_recta2.Pendiente(obj_recta2.GetA(), obj_recta2.GetB());
    ordenada_y = obj_recta1.Ordenada_Y(obj_recta1.GetA(), obj_recta1.GetB(), obj_recta1.GetC(), obj_recta1.GetX());
    abscisa_x = obj_recta1.Abscisa_X(obj_recta1.GetA(), obj_recta1.GetB(), obj_recta1.GetC(), obj_recta1.GetY());

    cout << "La pendiente de la recta 1 es: " << pendiente1 << endl;
    cout << "La pendiente de la recta 2 es: " << pendiente2 << endl << endl;

    cout << "La ordenada de Y es: " << ordenada_y << endl;
    cout << "La abscisa de X es: " << abscisa_x << endl;

}
