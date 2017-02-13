#include <iostream>
#include <vector>

using namespace std;

class MiMatrizRectangularEnteros{
    private:
        static const int MAX_FIL = 40;
        static const int MAX_COL = 50;
        int matriz_privada[MAX_FIL][MAX_COL];
        int util_fil;
        int util_col;
    public:
        MiMatrizRectangularEnteros(){
            util_col=util_fil=0;
        }

        MiMatrizRectangularEnteros(int col){
            util_fil = 0;
            util_col = col;
        }

        MiMatrizRectangularEnteros(int fil, int col){
            util_fil = fil;
            util_col = col;
        }

        int getUtilFilas(){
            return util_fil;
        }

        int getUtilColumnas(){
            return util_col;
        }

        int Elemento(int fil, int col){
            return matriz_privada[fil][col];
        }

        vector <int> Fila(int fila){
            vector <int> fil;
            for(int col=0; col<util_col; col++)
                fil.push_back(matriz_privada[fila][col]);
            return fil;
        }

        void Aniade(vector <int> fila_nueva){
            int num_columnas;
            if(util_fil < MAX_FIL){
                num_columnas = fila_nueva.size();
                if(num_columnas == util_col){
                    for(int col=0; col<num_columnas; col++)
                        matriz_privada[util_fil][col] = fila_nueva.at(col);
                    util_fil++;
                }
            }
        }

        MiMatrizRectangularEnteros CorrigePorPromedio(){
            int num_fils = getUtilFilas();
            int num_cols = getUtilColumnas();
            MiMatrizRectangularEnteros tmp(num_fils, num_cols);

            for(int f=0; f<num_fils; f++)
                for(int c=0; c<num_cols; c++)
                    tmp.matriz_privada[f][c] = matriz_privada[f][c];

            for(int fila=1; fila<num_fils-1; fila++){
                for(int col=1; col<num_cols-1; col++){
                    if(matriz_privada[fila][col] < 0){
                        int cont_validos = 0;
                        int suma_validos = 0;
                        for(int f=fila-1; f<=fila+1; f++){
                            for(int c=col-1; c<=col+1; c++){
                                if(matriz_privada[f][c] >= 0){
                                    cont_validos++;
                                    suma_validos+=matriz_privada[f][c];
                                }
                            }
                        }
                        if(suma_validos > 0)
                            tmp.matriz_privada[fila][col] = suma_validos/cont_validos;
                        else
                            tmp.matriz_privada[fila][col] = 0;
                    }
                }
            }
            return tmp;
        }
};

MiMatrizRectangularEnteros LeeMatriz(int fil, int col){
    MiMatrizRectangularEnteros tmp(col);

    for(int f=0; f<fil; f++){
        cout << "\nFila " << f << endl;
        vector <int> una_fila;
        int valor;
        for(int c=0; c<col; c++){
            cout << "Columna " << c << ": ";
            cin >> valor;
            una_fila.push_back(valor);
        }
        tmp.Aniade(una_fila);
    }
    return tmp;
}

void MuestraMatriz(MiMatrizRectangularEnteros m){
    int num_filas = m.getUtilFilas();
    int num_cols = m.getUtilColumnas();

    for(int f=0; f<num_filas; f++){
        for(int c=0; c<num_cols; c++){
            cout << m.Elemento(f,c) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int filas, cols;
    MiMatrizRectangularEnteros m;

    do{
        cout << "Num. filas: ";
        cin >> filas;
    }while(filas <= 0);

    do{
        cout << "Num. columnas: ";
        cin >> cols;
    }while(cols <= 0);

    m = LeeMatriz(filas, cols);
    MuestraMatriz(m);

    cout << "\nCorrección..." << endl;
    m = m.CorrigePorPromedio();
    MuestraMatriz(m);
}
