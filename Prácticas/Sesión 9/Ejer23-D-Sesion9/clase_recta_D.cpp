/*
d) Política de acceso a los datos miembros
En vez de usar un método para asignar un valor a cada dato miembro, defina un
único método SetCoeficientes para asignar los tres a la misma vez.
Observe que los métodos permiten definir la política de acceso a los datos miem-
bro. Si tengo previsto cambiar por separado los coeficientes de la recta, usaré
métodos de asignación individuales. En caso contrario, usaré un único método
que modifique a la misma vez todos los datos miembro. Incluso pueden dejarse
en la clase ambos tipos de métodos para que así el cliente de la clase pueda usar
los que estime oportunos en cada momento. Por ahora, mantenga únicamente el
método de asignación en bloque SetCoeficientes .
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

        float GetB(){
            return this->B;
        }

        float GetC(){
            return this->C;
        }

        void SetCoeficientes(float a, float b, float c){
            this->A = a;
            this->B = b;
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

    obj_recta1.SetCoeficientes(a1, b1, c1);
    obj_recta2.SetCoeficientes(a2, b2, c2);
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
