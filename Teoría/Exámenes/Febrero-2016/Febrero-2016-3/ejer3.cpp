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
        void Mostrar(){
            for(int i=0; i<TotalUtilizados(); i++)
                cout << Elemento(i) << " ";
        }
};

class TablaRectangularEnteros{
    private:
        static const int FIL = 20, COL = 30;
        int matriz[FIL][COL];
        int util_fil, util_col;
    public:
        TablaRectangularEnteros(int col){
            util_fil=0;
            util_col=col;
        }
        TablaRectangularEnteros(SecuenciaEnteros fila){
            util_fil=0;
            util_col=fila.TotalUtilizados();
            Aniade(fila);
        }
        int UtilFil(){
            return util_fil;
        }
        int UtilCol(){
            return util_col;
        }
        int Elemento(int i, int j){
            return matriz[i][j];
        }
        void Aniade(SecuenciaEnteros fila){
            int col = fila.TotalUtilizados();

            if(util_fil < FIL && col == util_col){
                for(int i=0; i<col; i++)
                    matriz[util_fil][i] = fila.Elemento(i);
                util_fil++;
            }
        }
        SecuenciaEnteros SeleccionDireccional(int i, int j, int dx, int dy){
            SecuenciaEnteros secDireccional;
            int fila=i;
            int col=j;

            while(fila < util_fil && col < util_col){
                secDireccional.Aniade(matriz[fila][col]);
                fila+=dy;
                col+=dx;
            }
            return secDireccional;
        }
};

int main()
{
    TablaRectangularEnteros matriz(5);
    SecuenciaEnteros seleccion1(matriz.SeleccionDireccional(0, 0, 1, 2));

    seleccion1.Mostrar();

    SecuenciaEnteros seleccion2(matriz.SeleccionDireccional(1, 3, 0, 1));

    seleccion2.Mostrar();

}
