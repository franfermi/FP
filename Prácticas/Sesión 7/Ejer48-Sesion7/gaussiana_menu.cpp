#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main()
{
    const float PI = 3.1416;
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

                do{
                    cout << "Introduce la desviación típica: ";
                    cin >> desv_tipica;
                }while(desv_tipica < 0);

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
                            gaussiana = 1/(desv_tipica*(sqrt(2*PI)))*exp(-0.5*pow((abscisa-media)/desv_tipica, 2));
                            cout << "El resultado de la función gaussiana es: " << gaussiana << endl;
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
