/*
Recupere la definición del registro CoordenadasPunto2D del ejercicio 47 de esta
relación de problemas y la solución al ejercicio 3 (Circunferencia) de la relación de
problemas I.
Cree ahora una clase llamada Circunferencia . Para establecer el centro, se usará
un dato miembro que ha de ser de tipo CoordenadasPunto2D .
Añada métodos para obtener la longitud de la circunferencia y el área del círculo inte-
rior.
*/
#include <iostream>
#include <cmath>

using namespace std;

const float PI = 3.1415927;

struct CoordenadasPunto2D{
    float x;
    float y;
};

class Circunferencia{
    private:
        CoordenadasPunto2D coordenadas;
    public:
        float GetX(){
            return this->coordenadas.x;
        }

        void SetX(float x){
            this->coordenadas.x = x;
        }

        float GetY(){
            return this->coordenadas.y;
        }

        void SetY(float y){
            this->coordenadas.y = y;
        }

        float LongitudCircunferencia(float radio){
            float longitud;
            longitud = 2 * (PI*radio);

            return longitud;
        }

        float AreaCirculo(float radio){
            float area;
            area = PI * pow(radio,2);
        }

        bool ContienePunto(float x1, float y1, float x2, float y2, float radio){
            bool contiene = false;
            if((pow(x1-x2, 2)) + (pow(y1-y2, 2)) <= pow(radio, 2))
                contiene = true;

            return contiene;
        }

        float Datos(){
            float dato;
            cout << "Introduce dato: " << endl;
            cin >> dato;

            return dato;
        }
};

int main()
{
    float x1, x2, y1, y2;
    float area_circulo = 0, radio = 0, long_circunferencia = 0;
    bool contienePunto = false;
    Circunferencia cir;

    cout << "-Centro-" << endl;
    x1 = cir.Datos();
    y1 = cir.Datos();
    cout << "\n-Radio-" << endl;
    radio = cir.Datos();
    cout << "\n-Coordenadas punto-" << endl;
    x2 = cir.Datos();
    y2 = cir.Datos();

    long_circunferencia = cir.LongitudCircunferencia(radio);
    area_circulo = cir.AreaCirculo(radio);
    contienePunto = cir.ContienePunto(x1, y1, x2, y2, radio);

    cout << "\nÁrea del círculo: " << area_circulo;
    cout << "\nLongitud de la circunferencia: " << long_circunferencia;

    if(contienePunto)
        cout << "\nEl punto está dentro";
    else
        cout << "\nEl punto no está dentro";
}
