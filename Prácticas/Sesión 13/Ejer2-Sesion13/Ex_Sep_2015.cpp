/*
(Examen Septiembre 2015) Buscaminas es un juego muy conocido cuyo objetivo es
encontrar todas las minas existentes en un tablero rectangular, sin abrir ninguna. Si el
jugador abre una mina, pierde la partida.
Se pide definir la clase TableroBuscaMinas conteniendo lo siguiente:
a) Para representar el tablero se trabajará con una matriz de datos 50x30 en la que
todas las filas tienen el mismo número de columnas y los datos son de tipo bool.
Contendrá un valor true en caso de haber una mina en la casilla especificada y false
en caso contrario. Esta matriz será un dato miembro de la clase y al principio, todos
los valores estarán a false.
b) Un método para incluir una mina en una determinada casilla.
c) Un método que reciba las coordenadas (i, j) de una casilla y devuelva un valor
entero que indique el número de minas que rodean a la misma (será un número entre
0 y 8). En caso de que la casilla contenga una mina, se devolverá el valor −1 .

Hay que tener especial cuidado con las casillas que hay en los bordes de la matriz ya
que la casilla en la posición [0][0] , por ejemplo, sólo tiene tres vecinos rodeándola.
Incluya un pequeño programa de prueba para asignar algunas minas y obtener las
minas que hay alrededor de algunas casillas.
*/
#include <iostream>

using namespace std;

class MatrizEnteros{
    private:
        static const int FIL = 50;
        static const int COL = 30;
        int tablero[FIL][COL];
        int util_fil, util_col;
    public:
        //Constructor por defecto, inicializa todas las casillas a false
        MatrizEnteros(int f, int c){
            util_fil=f;
            util_col=c;
            for(int i=0; i<util_fil; i++)
                for(int j=0; j<util_col; j++)
                    tablero[i][j] = 0;
        }
        //Obtiene el número de filas
        int getFil(){
            return util_fil;
        }
        //Obtiene el número de columnas
        int getCol(){
            return util_col;
        }
        //Modifica una fila dada
        void setFil(int fil){
            this->util_fil = fil;
        }
        //Modifica una columna dada
        void setCol(int col){
            this->util_col = col;
        }
        int Elemento(int i, int j){
            return tablero[i][j];
        }
        void Modifica(int i, int j, int valor){
            tablero[i][j]=valor;
        }
        //Inserta una mina en una coordenada dada
        void InsertarMina(int i, int j){
            tablero[i][j] = -1;
        }
        //Comprueba las minas que hay alrededor de una cooordenada dada
        int MinasAlrededor(int i, int j){
            int minas;
            if(tablero[i][j]) //Si la misma posición dada tiene mina
                minas = -1;
            else{
                for(int k=i-1; k<=i+1; k++)
                    for(int l=j-1; l<=j+1; l++)
                        if(k>=0 && k<util_fil && l>=0 && l<util_col)
                            if(tablero[k][l])
                                minas++;
            }
            return minas;
        }
        //Muestra el contenido del tablero
        void MostrarTablero(){
            for(int i=0; i<util_fil; i++){
                for(int j=0; j<util_col; j++)
                    cout << tablero[i][j] << " | ";
                cout << endl;
            }
        }
};

class TableroBuscaMinas{
    private:
        static const int FIL = 50;
        static const int COL = 30;
        bool tablero[FIL][COL];
        int util_fil, util_col;
    public:
        //Constructor por defecto, inicializa todas las casillas a false
        TableroBuscaMinas(int f, int c){
            util_fil=f;
            util_col=c;
            for(int i=0; i<util_fil; i++)
                for(int j=0; j<util_col; j++)
                    tablero[i][j] = false;
        }
        //Obtiene el número de filas
        int getFil(){
            return util_fil;
        }
        //Obtiene el número de columnas
        int getCol(){
            return util_col;
        }
        //Modifica una fila dada
        void setFil(int fil){
            this->util_fil = fil;
        }
        //Modifica una columna dada
        void setCol(int col){
            this->util_col = col;
        }
        char Elemento(int i, int j){
            return tablero[i][j];
        }
        //Inserta una mina en una coordenada dada
        void InsertarMina(int i, int j){
            tablero[i][j] = true;
        }
        //Comprueba las minas que hay alrededor de una cooordenada dada
        int MinasAlrededor(int i, int j){
            int minas;
            if(tablero[i][j]) //Si la misma posición dada tiene mina
                minas = -1;
            else{
                for(int k=i-1; k<=i+1; k++)
                    for(int l=j-1; l<=j+1; l++)
                        if(k>=0 && k<util_fil && l>=0 && l<util_col)
                            if(tablero[k][l])
                                minas++;
            }
            return minas;
        }
        MatrizEnteros Solucion(){
            MatrizEnteros sol(util_fil, util_col);
            int adyacentes=0;
            for(int i=0; i<util_fil; i++){
                for(int j=0; j<util_col; j++){
                    if(tablero[i][j])
                        sol.Modifica(i, j, -1);
                    else{
                        adyacentes=MinasAlrededor(i, j);
                        sol.Modifica(i, j, adyacentes);
                    }
                    adyacentes=0;
                }
            }
            return sol;
        }
        //Muestra el contenido del tablero
        void MostrarTablero(){
            for(int i=0; i<util_fil; i++){
                for(int j=0; j<util_col; j++)
                    cout << tablero[i][j] << " | ";
                cout << endl;
            }
        }
};

int main()
{
    const int FIN = -1;
    int ncol, nfil, coord_i, coord_j, opcion, minas;

    cout << "Introduce el número de filas: ";
    cin >> nfil;

    cout << "Introduce el número de columnas: ";
    cin >> ncol;
    //Modificamos las columnas y filas del tablero con las introducidas
    TableroBuscaMinas miTablero(nfil, ncol);

    cout << "\nBuscaminas de " << nfil << "x" << ncol << endl;
    //Menú del juego
    do{
        cout << "\nAcciones a realizar: ";
        cout << "\n1.Insertar mina en el tablero.";
        cout << "\n2.Consultar las minas de alrededor.";
        cout << "\n3.Mostrar solución.";
        cout << "\n-1.Salir." << endl;
        cin >> opcion;
    }while((opcion <= 0 || opcion > 3) && opcion != FIN);

    while(opcion != FIN){
        switch(opcion){
            case 1: //Inserta una mina en el tablero, indicando la posición a insertar
                do{
                    cout << "\nIntroduce minas en el tablero dando la posición (i,j) o -1 para salir: ";
                    cin >> coord_i >> coord_j;
                    //Se comprueba que las coordenadas son validas
                    if((coord_i >= 0 && coord_i <= nfil && coord_i != FIN) && (coord_j >= 0 && coord_j <= ncol && coord_j != FIN))
                        miTablero.InsertarMina(coord_i, coord_j);
                }while(coord_i != FIN && coord_j != FIN);
                break;
            case 2:
                do{ //Consulta las minas que se encuentran alrededor de la posición dada
                    cout << "\nIntroduce la posición (i,j) para consultar o -1 para salir: ";
                    cin >> coord_i >> coord_j;
                    if((coord_i >= 0 && coord_i <= nfil && coord_i != FIN) && (coord_j >= 0 && coord_j <= ncol && coord_j != FIN)){
                        minas = miTablero.MinasAlrededor(coord_i, coord_j);
                        cout << "\nHay " << minas << " mina/s alrededor." << endl;
                    }
                }while(coord_i != FIN && coord_j != FIN);
                break;
            case 3: //Muestra el contenido en ese momento del tablero
                cout << endl;
                MatrizEnteros miTableroInt(miTablero.getFil(), miTablero.getCol());
                miTableroInt = miTablero.Solucion();
                miTableroInt.MostrarTablero();
                cout << endl;
                break;
        }

        do{
            cout << "\nAcciones a realizar: ";
            cout << "\n1.Insertar mina en el tablero.";
            cout << "\n2.Consultar las minas de alrededor.";
            cout << "\n3.Mostrar tablero.";
            cout << "\n-1.Salir." << endl;
            cin >> opcion;
        }while((opcion <= 0 || opcion > 3) && opcion != FIN);
    }
    cout << "\nFin del juego!";
}
