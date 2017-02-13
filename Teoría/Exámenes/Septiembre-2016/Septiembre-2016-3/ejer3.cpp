#include <iostream>

using namespace std;

class Conjunto{
    private:
        static const int NMAX=500;
        bool vector[NMAX];
        int n;
    public:
        Conjunto(){
            n=0;
            for(int i=0; i<NMAX; i++)
                vector[i]=false;
        }
        void Aniade(int valor){
            if(valor < NMAX){
                vector[valor]=true;
            }
            if(valor > n)
                n=valor;
        }
        bool Elemento(int elemento){
            return vector[elemento];
        }
        int Cardinal(){
            int cont=0;
            for(int i=0; i<=n; i++){
                if(vector[i]==true)
                    cont++;
            }
            return cont;
        }
        Conjunto Interseccion(Conjunto A){
            Conjunto inter;
            for(int i=0; i<=n; i++){
                if(vector[i]==true && A.vector[i]==true){
                    inter.Aniade(i);
                }
            }
            return inter;
        }
        void Mostrar(){
            for(int i=0; i<=n; i++){
                if(vector[i]==true)
                    cout << i << " ";
            }
        }
};

int main()
{
    Conjunto cj1, cj2, cjInterseccion;
    int cardinal=0;

    cj1.Aniade(2);
    cj1.Aniade(3);
    cj1.Aniade(4);
    cj1.Aniade(5);
    cj1.Aniade(6);

    cout << "Conjunto 1:" << endl;
    cj1.Mostrar();

    cout << "\nPertenece a 2 al conjunto: " << endl;
    if(cj1.Elemento(7))
        cout << "SI";
    else
        cout << "NO";

    cout << "\nCardinal conjunto 1:" << endl;
    cardinal = cj1.Cardinal();
    cout << cardinal;

    cout << "\nInterseccion: " << endl;
    cj2.Aniade(5);
    cj2.Aniade(6);
    cj2.Aniade(7);
    cj2.Aniade(8);

    cjInterseccion = cj1.Interseccion(cj2);
    cjInterseccion.Mostrar();
}
