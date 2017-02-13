#include <iostream>

using namespace std;

class SecuenciaEnteros{
    private:
        static const int MAX = 50;
        int vector_enteros[MAX];
        int util_vector;
    public:
        SecuenciaEnteros(){
            util_vector=0;
        }
        int TotalUtilizados(){
            return util_vector;
        }
        int Capacidad(){
            return MAX;
        }
        void Aniade(int nuevo){
            if(util_vector < MAX){
                vector_enteros[util_vector] = nuevo;
                util_vector++;
            }
        }
        int Elemento(int pos){
            return vector_enteros[pos];
        }
        void OrdenarPorSeleccion(){
            int min, aux;
            for(int i=0; i<util_vector-1; i++){
                min = i;
                for(int j=i+1; j<util_vector; j++){
                    if(vector_enteros[min] > vector_enteros[j]){
                        min = j;
                    }
                }
                aux = vector_enteros[min];
                vector_enteros[min] = vector_enteros[i];
                vector_enteros[i] = aux;
            }
        }
        SecuenciaEnteros BusquedaHaciaArriba(int p, int n){
            SecuenciaEnteros busHaciaArriba;
            int num_elementos = n;
            int pos;
            if(n < util_vector){
                OrdenarPorSeleccion();
                for(int i=0; i<util_vector && n>0; i++){
                    if(vector_enteros[i] >= p){
                        busHaciaArriba.Aniade(Elemento(i));
                        n--;
                    }
                }
            }
            return busHaciaArriba;
        }
        void Mostrar(){
            for(int i=0; i<TotalUtilizados(); i++)
                cout << Elemento(i) << " ";
        }
};

int main()
{
    SecuenciaEnteros sec;

    sec.Aniade(12);
    sec.Aniade(0);
    sec.Aniade(4);
    sec.Aniade(2);
    sec.Aniade(7);
    sec.Aniade(6);
    sec.Aniade(19);
    sec.Aniade(28);
    sec.Aniade(14);
    sec.Aniade(21);
    sec.Aniade(9);
    sec.Aniade(14);
    sec.Aniade(2);
    sec.Aniade(11);
    sec.Aniade(14);

    SecuenciaEnteros secOrdenados;
    secOrdenados = sec.BusquedaHaciaArriba(15, 5);
    secOrdenados.Mostrar();
}
