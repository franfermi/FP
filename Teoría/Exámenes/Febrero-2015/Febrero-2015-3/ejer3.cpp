#include <iostream>

using namespace std;

class SecuenciaReales{
private:
   static const int TAMANIO = 100;
   double vector_privado[TAMANIO];
   int total_utilizados;

public:
   SecuenciaReales()
      :total_utilizados(0) {
   }
   int TotalUtilizados(){
      return total_utilizados;
   }
   int Capacidad(){
      return TAMANIO;
   }
   void Aniade(double nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   double Elemento(int indice){
      return vector_privado[indice];
   }
   void EliminaTodos(){
      total_utilizados = 0;
   }

   void Modifica(int indice_componente, double nuevo){
		if (indice_componente >= 0  &&  indice_componente < total_utilizados)
			vector_privado[indice_componente] = nuevo;
	}

	double Media(int izda, int dcha){
	   double media = 0;

	   for (int i=izda; i<=dcha; i++)
         media = media + vector_privado[i];

	   return media / (dcha - izda + 1);
	}
};


class TablaRectangularReales{
    private:
        static const int FILAS = 30;
        static const int COLS = 40;
        double matriz[FILAS][COLS];
        int util_fil, util_col;
    public:
        TablaRectangularReales(int col){
            util_fil=0;
            util_col=col;
        }
        int Util_fil(){
            return util_fil;
        }
        int Util_col(){
            return util_col;
        }
        void AniadeFila(SecuenciaReales fila){
            if(util_fil < FILAS){
                int tam = fila.TotalUtilizados();
                if(tam == util_col){
                    for(int col=0; col<util_col; col++)
                        matriz[util_fil][col] = fila.Elemento(col);
                    util_fil++;
                }
            }
        }
        TablaRectangularReales PromedioRelativo(){
            TablaRectangularReales suavizada(util_col);
            double valor_medio;
            int cont;

              if (util_fil == util_col){
                 for (int i=0; i<util_fil; i++){
                    suavizada.matriz[i][i] = matriz[i][i];

                    for (int j=i+1; j<util_col; j++){
                       double media = 0;

                       for (int k=j; k<util_col; k++)
                          media = media + matriz[i][k];          // Trabajamos directamente con las matrices de corchetes => Calculamos aquí la Media

                       media = media / (util_col - j);
                       suavizada.matriz[i][j] = suavizada.matriz[j][i] = media;

                    }
                 }

              }

            suavizada.util_fil = util_fil;
            return suavizada;
        }
        void Muestra(){
            for(int i=0; i<util_fil; i++){
                for(int j=0; j<util_col; j++)
                    cout << matriz[i][j] << " ";
                cout << endl;
            }
        }
};

int main()
{
    SecuenciaReales fila;
    int n;
    cout << "Introduce el número de filas: ";
    cin >> n;

    TablaRectangularReales tabla(n), tabla_suavizada(n);
    fila.Aniade(3.4);
    fila.Aniade(2.5);
    fila.Aniade(1.4);
    tabla.AniadeFila(fila);
    fila.EliminaTodos();
    fila.Aniade(2.4);
    fila.Aniade(4.5);
    fila.Aniade(3.4);
    tabla.AniadeFila(fila);
    fila.EliminaTodos();
    fila.Aniade(3.3);
    fila.Aniade(2.6);
    fila.Aniade(1.8);
    tabla.AniadeFila(fila);
    fila.EliminaTodos();

    cout << "Tabla original" << endl;
    tabla.Muestra();

    cout << "\nTabla suavizada" << endl;
    tabla_suavizada = tabla.PromedioRelativo();
    tabla_suavizada.Muestra();
}
