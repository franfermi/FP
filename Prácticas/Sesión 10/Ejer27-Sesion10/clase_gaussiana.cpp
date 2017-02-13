/*
Recupere la solución del ejercicio 8 de esta relación de problemas sobre la función
gaussiana. En vez de trabajar con funciones, plantee la solución con una clase. Debe
diseñar la clase teniendo en cuenta que la función matemática gaussiana viene deter-
minada unívocamente por el valor de la esperanza y la desviación, es decir, son estos
dos parámetros lo que distinguen a una función gaussiana de otra.
*/
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

class Gaussiana{
    private:
        float esperanza;
        float desviacion;
    public:
        float getEsperanza(){
            return this->esperanza;
        }

        void setEsperanza(float esperanza){
            this->esperanza = esperanza;
        }

        float getDesviacion(){
            return this->desviacion;
        }

        void setDesviacion(float desviacion){
            this->desviacion = desviacion;
        }

        float Potencia(float base, int exponente){
            float resultado=1, i;

            for(i=0; i<exponente; i++)
                resultado = resultado * base;

            return resultado;
        }

        float GaussianaCDF(float abscisa, float media, float desviacion){
            const float PI = 3.1416, b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782,
                            b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
            float gaussiana, area;

            gaussiana = 1/(desviacion*(sqrt(2*PI)))*exp(-0.5*pow((abscisa-media)/desviacion, 2));

            area = 1 - gaussiana * (b1*Potencia(1/(1+b0*abscisa),1) + b2*Potencia(1/(1+b0*abscisa),2)
                            + b3*Potencia(1/(1+b0*abscisa),3) + b4*Potencia(1/(1+b0*abscisa),4)
                                   + b5*Potencia(1/(1+b0*abscisa),5));

            return area;
        }
};

int main()
{
    Gaussiana gauss;
    float media, desv_tipica, abscisa, gaussiana, valor_min, valor_max, incremento;
    int op, op2;
    bool volver_atras = false;

    do{
        while(op != 1 && op != 2){
            cout << "1. Introducir parámetros de la función (esperanza y desviación)" << endl;
            cout << "2. Salir del programa" << endl;
            cin >> op;
        }
        volver_atras = false;
        system("clear");

        switch(op){
            case 1:
                cout << "Introduce la media: ";
                cin >> media;
                gauss.setEsperanza(media);

                do{
                    cout << "Introduce la desviación típica: ";
                    cin >> desv_tipica;
                }while(desv_tipica < 0);
                gauss.setDesviacion(desv_tipica);

                system("clear");

                while(op2 != 1 && op2 != 2){
                    cout << "1. Introducir rango de valores de abscisas" << endl;
                    cout << "2. Volver al menú anterior (el menú principal)" << endl;
                    cin >> op2;
                }

                system("clear");

                switch(op2){
                    case 1:
                        cout << "Introduce un valor mínimo: ";
                        cin >> valor_min;

                        do{
                            cout << "Introduce un valor máximo: ";
                            cin >> valor_max;
                        }while(valor_max < valor_min);

                        cout << "Introduce el incremento: ";
                        cin >> incremento;

                        abscisa = valor_min;

                        system("clear");

                        while(abscisa <= valor_max){
                            //Cálculo de la función gaussiana
                            gaussiana = gauss.GaussianaCDF(abscisa, gauss.getEsperanza(), gauss.getDesviacion());
                            cout << "CDF(" << abscisa << ")=" << gaussiana << endl;
                            abscisa +=  incremento;
                        }
                        break;
                    case 2:
                        volver_atras = true;
                        op = op2 = 0;
                        break;
                }
                break;
            case 2:
                cout << "Bye" << endl;
                return 0;
        }
    }while(volver_atras == true);
}
