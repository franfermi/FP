#include <iostream>
#include <cmath>

using namespace std;

static const double PI = 3.1416;

class Punto2D{
    private:
        double x=0;
        double y=0;
    public:
        Punto2D(){}
        Punto2D(double abscisaPunto, double ordenadaPunto){
            x = abscisaPunto;
            y = ordenadaPunto;
        }
        void setCoordenadas(double abscisaPunto, double ordenadaPunto){
            x = abscisaPunto;
            y = ordenadaPunto;
        }
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
};

class PoligonoRegular{
    private:
        Punto2D centro;
        int num_lados;
        double longitud;
    public:
        PoligonoRegular(){
            centro.setCoordenadas(0.0, 0.0);
            num_lados = 3;
            longitud = 1;
        }
        PoligonoRegular(int lados, double longi){
            centro.setCoordenadas(0.0, 0.0);
            num_lados = lados;
            longitud = longi;
        }
        PoligonoRegular(int lados, double longi, Punto2D p){
            centro.setCoordenadas(p.getX(), p.getY());
            num_lados = lados;
            longitud = longi;
        }
        Punto2D getCentro(){
            return centro;
        }
        int getLados(){
            return num_lados;
        }
        double getLongitud(){
            return longitud;
        }
        double getRadio(){
            return (longitud / (2.0*sin(PI/num_lados)));
        }
        double Perimetro(){
            return longitud * num_lados;
        }
        double Area(){
            return ((num_lados/2.0) * pow(getRadio(),2) * sin((2.0*PI)/num_lados));
        }
        bool Es_mayor(PoligonoRegular otro){
            return Area() > otro.Area();
        }
        PoligonoRegular PoligonoInscrito(int k){
            double longitud = getRadio() * sqrt(2*(1-cos((2*PI)/(k*num_lados))));
            PoligonoRegular polIns(num_lados*k, longitud, centro);

            return polIns;
        }
};

int main()
{
    Punto2D p;
    PoligonoRegular poligono1;
    PoligonoRegular poligono2(6, 4, p);

    if(poligono1.Es_mayor(poligono2)){
        cout << "Poligono1 > poligono2" << endl;
    }else
        cout << "Poligono2 > poligono1" << endl;

    PoligonoRegular poligono3(poligono1.PoligonoInscrito(2));
    cout << "Area: " << poligono3.Area() << endl;
}
