#include <iostream>
#include <cmath>

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

class Intervalo{
    private:
        double inferior, superior;
        bool es_cerrado_inferior;
        bool es_cerrado_superior;
        bool es_vacio;
    public:
        Intervalo(){
            es_vacio = true;
        }
        Intervalo(char tipo_inf, double inf, double sup, char tipo_sup){
            bool tipos_correctos = true;

            if(tipo_inf == '(')
                es_cerrado_inferior = false;
            else if(tipo_inf == '[')
                es_cerrado_inferior = true;
            else
                tipos_correctos = true;

            if(tipos_correctos){
                if(tipo_sup == ')')
                    es_cerrado_superior = false;
                else if(tipo_sup == ']')
                    es_cerrado_superior = true;
                else
                    tipos_correctos = true;
            }

            if(tipos_correctos){
                inferior = inf;
                superior = sup;
                if(fabs(inferior - superior) > 1e-6)
                    es_vacio = false;
            }
        }
        double getInferior(){
            return inferior;
        }
        double getSuperior(){
            return superior;
        }
        bool CerradoInferior(){
            return es_cerrado_inferior;
        }
        bool CerradoSuperior(){
            return es_cerrado_superior;
        }
        bool Vacio(){
            return es_vacio;
        }
        bool Contiene(double num){
            bool contiene = false;

            if (es_cerrado_inferior)
                contiene =  inferior <= num;
            else
                contiene =  inferior < num;

            if (es_cerrado_superior)
                contiene = contiene && superior >= num;
            else
                contiene = contiene && superior > num;

            return contiene;
        }
        SecuenciaReales Contenidos(SecuenciaReales sec){
            SecuenciaReales contenidos;
            int tope = sec.TotalUtilizados();
            for(int i=0; i<tope; i++){
                double valor = sec.Elemento(i);
                if(Contiene(valor))
                    contenidos.Aniade(valor);
            }
            return contenidos;
        }

};

int main()
{
    SecuenciaReales sec, secIntervalo;
    Intervalo inter('[', 1, 9, ')');

    sec.Aniade(1);
    sec.Aniade(2);
    sec.Aniade(18);
    sec.Aniade(5);
    sec.Aniade(13);
    sec.Aniade(9);

    secIntervalo = inter.Contenidos(sec);
    for(int i=0; i<secIntervalo.TotalUtilizados(); i++)
        cout << secIntervalo.Elemento(i) << " ";
}
