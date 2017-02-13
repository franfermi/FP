#include <iostream>

using namespace std;

class SecuenciaCaracteres{
    private:
        static const int MAX = 50;
        char vector_privado[MAX];
        int util_vector;
    public:
        SecuenciaCaracteres(){
            util_vector = 0;
        }
        int TotalUtilizados(){
            return util_vector;
        }
        char Elemento(int pos){
            return vector_privado[pos];
        }
        void Aniade(char nuevo){
            if(util_vector < MAX){
                vector_privado[util_vector] = nuevo;
                util_vector++;
            }
        }
        void Mostrar(){
            for(int i=0; i<TotalUtilizados(); i++)
                cout << Elemento(i);
            cout << endl;
        }
};

class SecuenciaEnteros{
    private:
        static const int MAX = 50;
        int vector_privado[MAX];
        int util_vector;
    public:
        SecuenciaEnteros(){
            util_vector = 0;
        }
        int TotalUtilizados(){
            return util_vector;
        }
        int Elemento(int pos){
            return vector_privado[pos];
        }
        void Aniade(char nuevo){
            if(util_vector < MAX){
                vector_privado[util_vector] = nuevo;
                util_vector++;
            }
        }
        void Mostrar(){
            int num=0;
            for(int i=0; i<TotalUtilizados(); i++){
                cout << Elemento(i);
                num++;
                if(num % 2==0)
                    cout << " ";
                else
                    cout << ",";
            }
            cout << endl;
        }
};

class MatrizChar{
    private:
        static const int FIL=100, COL=50;
        char matriz[FIL][COL];
        int util_fil, util_col;
    public:
        MatrizChar(){
            util_fil=util_col=0;
        }
        MatrizChar(int i, int j){
            util_fil=i;
            util_col=j;
        }
        char Elemento(int i, int j){
            return matriz[i][j];
        }
        void Modifica(int i, int j, char nuevo){
            matriz[i][j]=nuevo;
        }
        SecuenciaEnteros Buscar(char valor){
            SecuenciaEnteros sec;
            for(int i=0; i<util_fil; i++){
                for(int j=0; j<util_col; j++){
                    if(matriz[i][j]==valor){
                        sec.Aniade(i);
                        sec.Aniade(j);
                    }
                }
            }
            return sec;
        }
        SecuenciaCaracteres ComponerPalabra(int fila, char valor){
            SecuenciaCaracteres sec;
            for(int i=0; i<util_col; i++){
                if(matriz[fila][i] != valor){
                    sec.Aniade(matriz[fila][i]);
                }
            }
            return sec;
        }
        void Mostrar(){
            for(int i=0; i<util_fil; i++){
                for(int j=0; j<util_col; j++){
                    cout << matriz[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    MatrizChar matriz(2, 5);
    SecuenciaEnteros sec;
    SecuenciaCaracteres sec2, sec3;

    char valor;

    for(int i=0; i<2; i++){
        for(int j=0; j<5; j++){
            cin >> valor;
            matriz.Modifica(i, j, valor);
        }
    }

    cout << "Matriz original" << endl;
    matriz.Mostrar();

    cout << "Buscar" << endl;
    cin >> valor;

    sec = matriz.Buscar(valor);
    sec.Mostrar();

    cout << "Componer" << endl;
    sec2 = matriz.ComponerPalabra(0, valor);
    sec2.Mostrar();
}
