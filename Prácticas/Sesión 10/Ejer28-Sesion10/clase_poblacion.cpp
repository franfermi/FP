/*
Recupere la solución del ejercicio 10 de esta relación de problemas (población con
funciones). Re-escríbalo para que los cómputos relacionados con la población estén
encapsulados en una clase. La lectura de los valores en los rangos adecuados se hará
con las mismas funciones que ya se definieron en ese ejercicio. Modifique apropiada-
mente el programa principal.
*/
#include <iostream>
#include <cmath>

using namespace std;

class Poblacion{
    private:
        long long poblacion_inicial;
    public:
        long long getPoblacionInicial(){
            return this->poblacion_inicial;
        }

        void setPoblacionInicial(long long pobl_inicial){
            this->poblacion_inicial = pobl_inicial;
        }

        int LeeIntRango(){
            int tasa;

            do{
                cout << "Introduce la tasa: ";
                cin >> tasa;
            }while(tasa < 0 || tasa > 1000);

            return tasa;
        }

        float LeeIntMayorIgualQue(){
            int anios;

            do{
                cout << "Introduce los años: ";
                cin >> anios;
            }while(anios < 0);

            return anios;
        }

        long long PoblacionFinal(double tasa_global, long long pobl_inicial, float anios){
            long long pobl_final;

            pobl_final = pobl_inicial * pow(tasa_global, anios);

            return pobl_final;
        }

        float TotalAnios(long long pobl_doble, long long pobl_inicial, double tasa_global){
            float anios;

            while(pobl_doble < (pobl_inicial*2)){
                pobl_doble *= tasa_global;
                anios++;
            }

            return anios;
        }

        long long PoblacionFinalDoble(long long pobl_doble, long long pobl_inicial, double tasa_global){
            long long pobl_final_doble;

            pobl_final_doble = pobl_doble;

            while(pobl_final_doble < (pobl_inicial*2)){
                pobl_final_doble *= tasa_global;
            }

            return pobl_final_doble;
        }
};

int main()
{
    Poblacion pobl;
    long long poblacion_inicial, poblacion_final, poblacion_doble;
    int tasa_natalidad, tasa_mortalidad, tasa_migracion, tasa_global;
    double variacion_tasa_global;
    float anios, cont_anios;

    do{
        cout << "Introduce la población inicial: ";
        cin >> poblacion_inicial;
    }while(poblacion_inicial < 0);
    pobl.setPoblacionInicial(poblacion_inicial);

    tasa_natalidad = pobl.LeeIntRango();
    tasa_mortalidad = pobl.LeeIntRango();
    tasa_migracion = pobl.LeeIntRango();

    anios = pobl.LeeIntMayorIgualQue();

    tasa_global = tasa_natalidad - tasa_mortalidad + tasa_migracion;
    variacion_tasa_global = 1 + tasa_global / 1000.0;
    poblacion_final = pobl.PoblacionFinal(variacion_tasa_global, pobl.getPoblacionInicial(), anios);

    poblacion_doble = poblacion_final;

    cont_anios = anios + pobl.TotalAnios(poblacion_doble, pobl.getPoblacionInicial(), variacion_tasa_global);

    poblacion_doble = pobl.PoblacionFinalDoble(poblacion_doble, pobl.getPoblacionInicial(), variacion_tasa_global);

    cout << "La población final pasados " << anios << " años es de: " << poblacion_final << endl;
    cout << "Años que tienen que pasar para doblar la población: " << cont_anios << endl;
    cout << "La población transcurridos " << cont_anios << " años es: " << poblacion_doble;
}

