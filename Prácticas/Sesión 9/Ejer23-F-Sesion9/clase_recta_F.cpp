/*
f ) Política de acceso a los datos miembro
Suprima ahora el método SetCoeficientes . De esta forma, una vez creado
el objeto (pasándole los datos apropiados en el constructor) ya no podremos
modificar los datos miembro. Esto es útil en aquellas situaciones en las que no
queremos permitir que el estado del objeto cambie, una vez se ha creado.
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
        }

        Recta(float a, float b, float c){
            this->A = a;
            this->B = b;
            this->C = c;
        }

        float GetA(){
            return this->A;
        }

        float GetB(){
            return this->B;
        }

        float GetC(){
            return this->C;
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

    Recta obj_recta1(a1, b1, c1); //Constructor por parámetros
    Recta obj_recta2(a2, b2, c2); //Constructor por parámetros
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
