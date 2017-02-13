////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

// Examen de Febrero 2015

#include <iostream>
#include <cmath>
using namespace std;


////////////////////////////////////////////////////////////////////////////
// La clase SecuenciaReales no se ped�a que se implementase. S�lo que se pusieran las cabeceras

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




//////////////////////////////////////////////////////////////////////////////
// Top_k
//////////////////////////////////////////////////////////////////////////////




class SecuenciaEnteros{
private:
   static const int TAMANIO = 100000;
   int vector_privado[TAMANIO];
   int total_utilizados;
   
   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      int intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }  
   
public:
   SecuenciaEnteros()
      :total_utilizados(0) {
   }
   int TotalUtilizados(){
      return total_utilizados;
   }
   int Capacidad(){
      return TAMANIO;
   }
   void Aniade(int nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   int Elemento(int indice){
      return vector_privado[indice];
   }
   void EliminaTodos(){
      total_utilizados = 0;
   }
   
   void Modifica(int indice_componente, int nuevo){
		if (indice_componente >= 0  &&  indice_componente < total_utilizados)
			vector_privado[indice_componente] = nuevo;
	}	

   // Ordenaci�n de Menor a Mayor
   void Ordena_por_Insercion(){
      int izda, i;
      int a_desplazar;

      for (izda = 1; izda < total_utilizados; izda++){
         a_desplazar = vector_privado[izda];

         for (i = izda; i>0 && a_desplazar < vector_privado[i-1]; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[i] = a_desplazar;
      }
   }
   
   ///////////////////////////////////////////////////////////////////////////
   /*
   SOLUCI�N B�SICA DE Topk (se puede sacar la m�xima nota)  
   
   Topk_OrdenandoTodo
   
   Versi�n 1.
      Crear una copia de los datos en una secuencia local top
      Ordenar top de mayor a menor
      Construir top_k con los k primeros elementos de top
   
   Versi�n 2.
      Crear una copia de los datos en una secuencia local top
      Ordenar top de menor a mayor 
      Construir top_k con los k �ltimos elementos de top
   
   En la versi�n 1 tendr�amos que usar el mismo algoritmo de ordenaci�n visto en clase
   y simplemente cambiar < por > en el sitio adecuado. 
   Por ejemplo, si usamos el m�todo Ordena_por_Insercion, bastar�a cambiar 
      a_desplazar < vector_privado[i-1];
   por
      a_desplazar > vector_privado[i-1];
   
   En la versi�n 2 usamos el mismo algoritmo de ordenaci�n visto en clase
   y as� no repetimos c�digo muy similar.
   */
   
   
   // Prec: k>0
   SecuenciaEnteros Topk_OrdenandoTodo(int k){
      SecuenciaEnteros top;
      SecuenciaEnteros top_k;
      
      for (int i=0; i<total_utilizados; i++)
         top.Aniade(vector_privado[i]);
      
		top.Ordena_por_Insercion();        // De menor a mayor

      int tope = total_utilizados - k;
      
      for (int i=total_utilizados - 1; i >= tope; i--)
      	top_k.Aniade(top.Elemento(i));
      
      return top_k;
   }
   
    
   /*
      // La siguiente declaraci�n crear�a directamente una copia con los datos actuales:
		// SecuenciaEnteros topk(*this); // *this  devuelve una copia del objeto "actual" (impl�cito) 
   */
 
   
   ///////////////////////////////////////////////////////////////////////////
   //   AMPLIACI�N. VERSIONES MEJORADAS DE Topk
   ///////////////////////////////////////////////////////////////////////////


   // ------------------------------------------------------------------------
   // Versi�n de Topk_OrdenandoTodo usando menos memoria local
   // ------------------------------------------------------------------------
   
   /*
   En el m�todo Topk_OrdenandoTodo se han usado dos objetos de tipo Secuencia: top y top_k
   Ambos objetos tienen como dato miembro privado un vector de enteros tan grande como
   indique la constante privada TAMANIO, por lo que podr�a desbordarse la memoria.
   
   Veamos varias alternativas que pasan por no usar top_k sino trabajar �nicamente sobre top:
      	
			a)	
	         Invertir top
	         Truncar top para dejar �nicamente los k primeros
	         
               top.Invierte();
               top.Trunca(k);
	        
			  	Esta opci�n es ineficiente con valores de k peque�os ya que invierte todo el vector 
	           
			b)
	      	Ir intercambiando top[i] con top[ultima-i] hasta un total de k veces
	      	Truncar top para dejar �nicamente los k primeros      
            Si k es grande hay que parar cuando lleguemos a la mitad de la secuencia.   		
      */
   
   // Prec: k>0
   SecuenciaEnteros Topk_OrdenandoTodoEficienteMemoria(int k){
      SecuenciaEnteros top;
      
      for (int i=0; i<total_utilizados; i++)
         top.Aniade(vector_privado[i]);
      
		top.Ordena_por_Insercion();  

      int izda = 0;
      int dcha = total_utilizados - 1;
      
		for (int i=0; i < k && izda < dcha; i++){
			top.IntercambiaComponentes_en_Posiciones(izda, dcha);
			izda++;
			dcha--;
		}
		
      top.Trunca(k);
      
      return top;
   }
  


   // ------------------------------------------------------------------------
   // Versi�n de Topk especialmente eficiente para valores de k peque�os
   // ------------------------------------------------------------------------
   
   /*                
      
      Hay muchos problemas en los que s�lo estamos interesados en obtener 
      los k valores mayores con k un n�mero peque�o (p.e, b�squeda de outliers en Estad�stica)
      Por lo tanto, es una p�rdida de tiempo tener que ordenar todo el vector
      para luego quedarnos s�lo con los k primeros.

      Posibles soluciones:
      
      a) Aplicamos una modificaci�n del algoritmo de Selecci�n.
         
         Algoritmo topk (Selecci�n):
         
            Crear una copia de todo el vector original en top_k
            Recorrer k veces top_k (izda=0; izda<k)
               Buscar la posici�n -pos_maximo- del m�ximo de top_k entre izda y el final
               Intercambiar las componentes izda y pos_maximo
                     
      
      b) Aplicamos una modificaci�n del algoritmo de Inserci�n.
      
         Algoritmo topk (Inserci�n):
         
            Crear top_k vac�o
            Recorrer los k primeros elementos del vector
               Insertar ordenadamente en top_k cada uno de ellos
            Recorrer el resto de elementos del vector
               Insertar ordenadamente en top_k cada uno de ellos
               Eliminar el �ltimo
      
      �Qu� pasar�a con estos algoritmos cuando k es grande?
      
      Cuando k es igual al total de utilizados el algoritmo a) equivale a la ordenaci�n
      por Selecci�n y el b) a la ordenaci�n por Inserci�n. Como la ordenaci�n por Selecci�n
      es m�s lenta en m�s situaciones que la ordenaci�n por inserci�n, lo mejor ser�a optar
      por la soluci�n b)
   */
   
   // Prec: k>0
   SecuenciaEnteros Topk_Insertando(int k){
      SecuenciaEnteros top_k;
      
      if (total_utilizados > 0){         
         for (int i=0; i<k; i++)
            top_k.InsertaOrd_Descendente(vector_privado[i]);
         
         for (int i=k; i< total_utilizados; i++){
            top_k.InsertaOrd_Descendente(vector_privado[i]);
            top_k.EliminaUltimo();
         }
      }
      
      return top_k;
   }

   // Prec: La secuencia debe estar ordenada de mayor a menor
   void InsertaOrd_Descendente(int nuevo){
      if (total_utilizados < TAMANIO){         
         int i;
         for (i = total_utilizados; i > 0  &&  vector_privado[i-1] < nuevo; i--)
            vector_privado[i] = vector_privado[i-1];
         
         vector_privado[i] = nuevo;
         total_utilizados++;
      }
   }
   
   void Trunca(int tamanio_nuevo){
      if (tamanio_nuevo >= 0 && tamanio_nuevo < total_utilizados)
         total_utilizados = tamanio_nuevo;
   }
   
   void EliminaUltimo(){
      Trunca(total_utilizados - 1);
   }
};



//////////////////////////////////////////////////////////////////////////////
// Promedio Relativo
//////////////////////////////////////////////////////////////////////////////



class MatrizRectangularReales{
private:
   static const int MAX_FIL = 50;
   static const int MAX_COL = 40;
   double matriz_privada[MAX_FIL][MAX_COL];
   int util_fil;
   const int util_col;
public:
   // Prec: 0 < numero_de_columnas <= MAX_COL(40)
   MatrizRectangularReales(int numero_de_columnas)
      :util_fil(0), util_col(numero_de_columnas)
   { 
   }
   MatrizRectangularReales(SecuenciaReales primera_fila)
      :util_fil(0), util_col(primera_fila.TotalUtilizados())
   { 
   }
   int CapacidadFilas(){
      return MAX_FIL;
   }
   int FilasUtilizadas(){
      return util_fil;
   }
   int ColUtilizadas(){
      return util_col;
   }
   double Elemento(int fila, int columna){
      return matriz_privada[fila][columna];
   }
   SecuenciaReales Fila(int indice_fila){
      SecuenciaReales fila;

      for (int col = 0; col < util_col; col++)
         fila.Aniade(matriz_privada[indice_fila][col]);

      return fila;
   }
   
   void Aniade(SecuenciaReales fila_nueva){
      int numero_columnas_nueva;

      if (util_fil < MAX_FIL){
         numero_columnas_nueva = fila_nueva.TotalUtilizados();

         if (numero_columnas_nueva == util_col){
            for (int col = 0; col < util_col ; col++)
               matriz_privada[util_fil][col] = fila_nueva.Elemento(col);

            util_fil++;
         }
      }
   }
   
   MatrizRectangularReales PromedioRelativo(){
      /*
      Algoritmo Matriz sim�trica suavizada por la media
      
         Recorrer las filas -i- de la matriz
         	Crear una fila nueva vac�a 
            A�adirle los valores (j,i) de la suavizada
            A�adirle el elemento de la diagonal principal. 
            Recorrer el resto de las columnas 
					A�adirle la media aritm�tica de los valores que hay desde la columna hasta el final
				A�adir la fila a la matriz resultado
      */
      MatrizRectangularReales suavizada(util_col);
      SecuenciaReales fila_nueva;
      
      if (util_fil == util_col){
         for (int i=0; i<util_fil; i++){            
            for (int j=0; j<i; j++)
               fila_nueva.Aniade(suavizada.Elemento(j,i));
               
            fila_nueva.Aniade(matriz_privada[i][i]);
            SecuenciaReales fila_original = Fila(i);
            
            for (int j=i+1; j<util_col; j++)              
               fila_nueva.Aniade(fila_original.Media(j, util_col-1));    // El m�todo Media lo situamos en la clase SecuenciaReales
            
            suavizada.Aniade(fila_nueva);
            fila_nueva.EliminaTodos();
         }
      }
      
      return suavizada;
   }
   
   MatrizRectangularReales PromedioRelativo_vs2(){
      /*
      Esta versi�n implementa el mismo algoritmo pero accede directamente a la matriz privada
      de la MatrizRectangular que estamos construyendo.
      Las dos versiones ser�an correctas.
      */
      
      MatrizRectangularReales suavizada(util_col);
      
      if (util_fil == util_col){
         for (int i=0; i<util_fil; i++){            
            suavizada.matriz_privada[i][i] = matriz_privada[i][i];
            
            for (int j=i+1; j<util_col; j++){
               double media = 0;
               
               for (int k=j; k<util_col; k++)
                  media = media + matriz_privada[i][k];          // Trabajamos directamente con las matrices de corchetes => Calculamos aqu� la Media
               
               media = media / (util_col - j);               
               suavizada.matriz_privada[i][j] = suavizada.matriz_privada[j][i] = media;
            }
         }
      }
      
      suavizada.util_fil = util_fil;
      
      return suavizada;
   }
};



//////////////////////////////////////////////////////////////////////////////
// Intervalo
//////////////////////////////////////////////////////////////////////////////


/*
   Para establecer el tipo de los extremos del intervalo (abierto/cerrado), lo l�gico
   es usar sendos bool:
         bool es_cerrado_inferior, 
              es_cerrado_superior;
   Ahora bien, en el constructor ser�a deseable marcar el tipo de intervalo
   con un char '(', '[', ')', ']' pues es muy intuitivo.
   PERO dentro de la clase no compararemos con los caracteres espec�ficos sino
   con los bool correspondientes.
                 
            
   Para establecer que un intervalo es vac�o podr�amos optar por alguna de estas alternativas:

   -  Asignar al extremos inferior un valor espec�fico igual al extremo superior (por ejemplo 0)
      y establecer los extremos del intervalo abiertos.
     
      En vez de trabajar con tantas variables, simplemente podr�amos hacer lo siguiente:
        
   -  Asignar al extremo inferior un valor estrictamente mayor que el extremo superior
   
      Otra posibilidad es usar un dato miembro expl�cito:
         bool es_vacio;           
*/


class Intervalo{
private:
   double inferior, superior;
   bool es_cerrado_inferior;
   bool es_cerrado_superior;
   
   void SetVacio(){
      inferior = 1;
      superior = 0;
   }
   
   bool SonIguales(double uno, double otro){
   	return fabs(uno - otro) <= 1e-6;
	}
	
	bool EsCorrecto(bool es_cerrado_izda, double extremo_inferior, double extremo_superior, bool es_cerrado_dcha){
      if (SonIguales(extremo_inferior, extremo_superior))
   		return es_cerrado_izda && es_cerrado_dcha;
   	else
      	return extremo_inferior < extremo_superior;
	}
	
	void SetValores(bool es_cerrado_izda, double extremo_inferior, double extremo_superior, bool es_cerrado_dcha){
      if (EsCorrecto (extremo_inferior, extremo_superior, es_cerrado_izda, es_cerrado_dcha)){
         inferior = extremo_inferior;
         superior = extremo_superior;
         es_cerrado_inferior = es_cerrado_izda;
         es_cerrado_superior = es_cerrado_dcha;
      }
      else
         SetVacio();
	}
	
public:
   Intervalo(){
      SetVacio();
   }
   
   Intervalo(bool es_cerrado_izda, double extremo_inferior, double extremo_superior, bool es_cerrado_dcha){
      SetValores(extremo_inferior, extremo_superior, es_cerrado_izda, es_cerrado_dcha);  
   }
   
   Intervalo(double extremo_inferior, double extremo_superior, char tipo_inferior, char tipo_superior){
      /*
      Debemos construir los condicionales para que los caracteres (,),[,] est�n en una �nica sentencia.
      Esto facilita la modificaci�n futura del c�digo.
      */
      bool caracteres_correctos = true;

      if (tipo_inferior == '(')
         es_cerrado_inferior = false;
      else if (tipo_inferior == '[')
         es_cerrado_inferior = true;
      else
         caracteres_correctos = false;
         
      if (caracteres_correctos){
         if (tipo_superior == ')')
            es_cerrado_superior = false;
         else if (tipo_superior == ']')
            es_cerrado_superior = true;
         else
            caracteres_correctos = false;
      }
      
      if (caracteres_correctos)
         SetValores(extremo_inferior, extremo_superior, es_cerrado_inferior, es_cerrado_superior);
   }      
   
   bool EsVacio(){
   	if (SonIguales(inferior, superior))
   		return !(es_cerrado_inferior && es_cerrado_superior);
   	else
      	return inferior > superior;
   }
   
   double ExtremoSuperior(){
      return superior;
   }
   
   double ExtremoInferior(){
      return inferior;
   }
   
   bool EsCerradoInferior(){
      return es_cerrado_inferior;
   }
   
   bool EsCerradoSuperior(){
      return es_cerrado_superior;
   }
   
   bool Contiene(double real){
      bool contiene = false;
      
      if (inferior < real && real < superior)
         contiene = true;
      else if (es_cerrado_inferior && SonIguales(inferior , real))
         contiene = true;
      else if (es_cerrado_superior && SonIguales(superior , real))
         contiene = true;
         
      return contiene;
      
      /*
      // Otra forma (pero no permite el uso de SonIguales):
      
      if (es_cerrado_inferior)
         contiene =  inferior <= real;
      else
         contiene =  inferior < real;
      
      if (es_cerrado_superior)
         contiene = contiene && superior >= real; 
      else
         contiene = contiene && superior > real; 
      */
   }
   
   SecuenciaReales Contenidos (SecuenciaReales secuencia){
      SecuenciaReales contenidos;
      int tope = secuencia.TotalUtilizados();
      
      for (int i=0; i<tope; i++){
         double valor = secuencia.Elemento(i);
         
         if (Contiene(valor))
            contenidos.Aniade(valor);
      }
      
      return contenidos;
   }
};

//////////////////////////////////////////////////////////////////////////////


int main(){
   
   SecuenciaEnteros secuencia_ordenada_de_menor_a_mayor;
   SecuenciaEnteros secuencia_ordenada_de_mayor_a_menor;
   SecuenciaEnteros topk;
   SecuenciaEnteros secuencia;
   

//   secuencia.Aniade(4);
//   secuencia.Aniade(2);
//   secuencia.Aniade(-3);
//   secuencia.Aniade(8);
//   secuencia.Aniade(10);
//   secuencia.Aniade(0);
//   secuencia.Aniade(6);
//   secuencia.Aniade(4);
   
   const int MAX = 100000;
   
   for (int i=1; i<=MAX; i++)
      secuencia_ordenada_de_menor_a_mayor.Aniade(i);
   
   for (int i=MAX; i>0; i--)
      secuencia_ordenada_de_mayor_a_menor.Aniade(i);
   
   secuencia = secuencia_ordenada_de_menor_a_mayor;
   //  secuencia = secuencia_ordenada_de_mayor_a_menor;
   
   cout << "Empiezo";
   // topk = secuencia.Topk_OrdenandoTodo(3);                        //  Se desborda la memoria porque necesita dos vectores locales
   // topk = secuencia.Topk_OrdenandoTodoEficienteMemoria(3);        // Tarda bastante tiempo 
   // topk = secuencia.Topk_Insertando(3);                           // Va muy r�pido
   //topk = secuencia.Topk_OrdenandoTodoEficienteMemoria(secuencia.TotalUtilizados());  // Va muy r�pido con secuencia_ordenada_de_menor_a_mayor pero lento con secuencia_ordenada_de_mayor_a_menor (Tarda el mismo tiempo que con k=3) 
   topk = secuencia.Topk_Insertando(secuencia.TotalUtilizados());  // Va muy r�pido con secuencia_ordenada_de_mayor_a_menor pero lento con secuencia_ordenada_de_menor_a_mayor - tan lento como el anterior m�todo con la otra secuencia-
   cout << "Termino";
   
   
   // Para k peque�o funciona mucho mejor Topk_Insertando
   // Para k grande, dependiendo de c�mo est� el vector va mejor Topk_OrdenandoTodoEficienteMemoria o Topk_Insertando
   //    lo cual es l�gico ya que el primero ordena de menor a mayor mientras que el segundo lo hace al rev�s.
   
   
   int tope = topk.TotalUtilizados();
        
   for (int i=0; i<tope; i++)
      cout << topk.Elemento(i) << " ";
   
   
   
   ///////////////////////////////////////////////////////////////////////////////////////
   
   /*
   SecuenciaReales fila;
   MatrizRectangularReales matriz(3);
   
   fila.Aniade(3.4);
   fila.Aniade(2.5);
   fila.Aniade(1.4);
   matriz.Aniade(fila);
   fila.EliminaTodos();
   fila.Aniade(2.4);
   fila.Aniade(4.5);
   fila.Aniade(3.4);   
   matriz.Aniade(fila);
   fila.EliminaTodos();
   fila.Aniade(3.3);
   fila.Aniade(2.6);
   fila.Aniade(1.8);
   matriz.Aniade(fila);
   fila.EliminaTodos();
   
   MatrizRectangularReales suavizada(matriz.PromedioRelativo_vs2());
   
   int tope_fil = suavizada.FilasUtilizadas(), tope_col = suavizada.ColUtilizadas();
   
   for (int i=0; i<tope_fil; i++){
      for (int j=0; j<tope_col; j++)
         cout << suavizada.Elemento(i,j) << " ";
      
      cout << "\n";
   }  
   
   */
   
   
   ///////////////////////////////////////////////////////////////////////////////////////   
   
   // Intervalo uno('[', 0 , 2 ,')');  --> [0,2) 
   // Constructor muy intuitivo, aunque desgraciadamente, C++ aceptar�a tambi�n 
   // Intervalo uno(0 , 2 ,'[', ')');  
   // ya que har�a las transformaciones de tipo necesarias. 
   // En cualquier caso, si hemos programado bien el constructor, al no pasar un car�cter v�lido
   // como par�metro a los tipos de los extremos, el intervalo se quedar�a en vac�o.
   
   Intervalo uno('[', 0 , 2 ,')');        
   Intervalo otro(true, -1, 1, true);     // [-1,1] 
   Intervalo vacio;

   SecuenciaReales varios_reales, contenidos;
   
   varios_reales.Aniade(-1.2);
   varios_reales.Aniade(0);
   varios_reales.Aniade(1);
   varios_reales.Aniade(2);
   
   contenidos = uno.Contenidos(varios_reales);
   
   for (int i=0; i<contenidos.TotalUtilizados(); i++)
      cout << contenidos.Elemento(i) << " ";
   
	
   cout << "\n\n";
   system ("pause");
}

