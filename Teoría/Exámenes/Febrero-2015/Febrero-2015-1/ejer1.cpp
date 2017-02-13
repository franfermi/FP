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
            int max, aux;
            for(int i=0; i<TotalUtilizados()-1; i++){
                max = i;
                for(int j=i+1; j<TotalUtilizados(); j++){
                    if(vector_enteros[max] < vector_enteros[j]){
                        max = j;
                    }
                }
                aux = vector_enteros[max];
                vector_enteros[max] = vector_enteros[i];
                vector_enteros[i] = aux;
            }
        }
        SecuenciaEnteros Topk(int k){
            SecuenciaEnteros tmp;

            for(int i=0; i<TotalUtilizados(); i++)
                tmp.Aniade(vector_enteros[i]);

            tmp.OrdenarPorSeleccion();

            if(k < TotalUtilizados()){
                for(int i=k; i<TotalUtilizados(); i++)
                    tmp.util_vector--;
            }

            return tmp;
        }
        void Mostrar(){
            for(int i=0; i<TotalUtilizados(); i++)
                cout << Elemento(i) << " ";
        }
};

int main()
{
    SecuenciaEnteros sec;
    int k;

    sec.Aniade(4);
    sec.Aniade(2);
    sec.Aniade(-3);
    sec.Aniade(8);
    sec.Aniade(10);
    sec.Aniade(0);
    sec.Aniade(6);
    sec.Aniade(4);

    cout << "Sin ordenar" << endl;
    sec.Mostrar();

    cout << "\nOrdenado" << endl;
    SecuenciaEnteros secOrdenado(sec);
    secOrdenado.OrdenarPorSeleccion();
    secOrdenado.Mostrar();

    cout << "\nIntroduce el valor de k: ";
    cin >> k;
    cout << "\n---TopK---" << endl;
    SecuenciaEnteros topK;
    topK = sec.Topk(k);
    topK.Mostrar();
}
