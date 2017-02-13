////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

// Examen de Febrero 2015

#include <iostream>
#include <cmath>
using namespace std;


////////////////////////////////////////////////////////////////////////////
// La clase SecuenciaReales no se pedía que se implementase. Sólo que se pusieran las cabeceras

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

   // Ordenación de Menor a Mayor
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
   SOLUCIÓN BÁSICA DE Topk (se puede sacar la máxima nota)  
   
   Topk_OrdenandoTodo
   
   Versión 1.
      Crear una copia de los datos en una secuencia local top
      Ordenar top de mayor a menor
      Construir top_k con los k primeros elementos de top
   
   Versión 2.
      Crear una copia de los datos en una secuencia local top
      Ordenar top de menor a mayor 
      Construir top_k con los k últimos elementos de top
   
   En la versión 1 tendríamos que usar el mismo algoritmo de ordenación visto en clase
   y simplemente cambiar < por > en el sitio adecuado. 
   Por ejemplo, si usamos el método Ordena_por_Insercion, bastaría cambiar 
      a_desplazar < vector_privado[i-1];
   por
      a_desplazar > vector_privado[i-1];
   
   En la versión 2 usamos el mismo algoritmo de ordenación visto en clase
   y así no repetimos código muy similar.
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
      // La siguiente declaración crearía directamente una copia con los datos actuales:
		// SecuenciaEnteros topk(*this); // *this  devuelve una copia del objeto "actual" (implícito) 
   */
 
   
   ///////////////////////////////////////////////////////////////////////////
   //   AMPLIACIÓN. VERSIONES MEJORADAS DE Topk
   ///////////////////////////////////////////////////////////////////////////


   // ------------------------------------------------------------------------
   // Versión de Topk_OrdenandoTodo usando menos memoria local
   // ------------------------------------------------------------------------
   
   /*
   En el método Topk_OrdenandoTodo se han usado dos objetos de tipo Secuencia: top y top_k
   Ambos objetos tienen como dato miembro privado un vector de enteros tan grande como
   indique la constante privada TAMANIO, por lo que podría desbordarse la memoria.
   
   Veamos varias alternativas que pasan por no usar top_k sino trabajar únicamente sobre top:
      	
			a)	
	         Invertir top
	         Truncar top para dejar únicamente los k primeros
	         
               top.Invierte();
               top.Trunca(k);
	        
			  	Esta opción es ineficiente con valores de k pequeños ya que invierte todo el vector 
	           
			b)
	      	Ir intercambiando top[i] con top[ultima-i] hasta un total de k veces
	      	Truncar top para dejar únicamente los k primeros      
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
   // Versión de Topk especialmente eficiente para valores de k pequeños
   // ------------------------------------------------------------------------
   
   /*                
      
      Hay muchos problemas en los que sólo estamos interesados en obtener 
      los k valores mayores con k un número pequeño (p.e, búsqueda de outliers en Estadística)
      Por lo tanto, es una pérdida de tiempo tener que ordenar todo el vector
      para luego quedarnos sólo con los k primeros.

      Posibles soluciones:
      
      a) Aplicamos una modificación del algoritmo de Selección.
         
         Algoritmo topk (Selección):
         
            Crear una copia de todo el vector original en top_k
            Recorrer k veces top_k (izda=0; izda<k)
               Buscar la posición -pos_maximo- del máximo de top_k entre izda y el final
               Intercambiar las componentes izda y pos_maximo
                     
      
      b) Aplicamos una modificación del algoritmo de Inserción.
      
         Algoritmo topk (Inserción):
         
            Crear top_k vacío
            Recorrer los k primeros elementos del vector
               Insertar ordenadamente en top_k cada uno de ellos
            Recorrer el resto de elementos del vector
               Insertar ordenadamente en top_k cada uno de ellos
               Eliminar el último
      
      ¿Qué pasaría con estos algoritmos cuando k es grande?
      
      Cuando k es igual al total de utilizados el algoritmo a) equivale a la ordenación
      por Selección y el b) a la ordenación por Inserción. Como la ordenación por Selección
      es más lenta en más situaciones que la ordenación por inserción, lo mejor sería optar
      por la solución b)
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
      Algoritmo Matriz simétrica suavizada por la media
      
         Recorrer las filas -i- de la matriz
         	Crear una fila nueva vacía 
            Añadirle los valores (j,i) de la suavizada
            Añadirle el elemento de la diagonal principal. 
            Recorrer el resto de las columnas 
					Añadirle la media aritmética de los valores que hay desde la columna hasta el final
				Añadir la fila a la matriz resultado
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
               fila_nueva.Aniade(fila_original.Media(j, util_col-1));    // El método Media lo situamos en la clase SecuenciaReales
            
            suavizada.Aniade(fila_nueva);
            fila_nueva.EliminaTodos();
         }
      }
      
      return suavizada;
   }
   
   MatrizRectangularReales PromedioRelativo_vs2(){
      /*
      Esta versión implementa el mismo algoritmo pero accede directamente a la matriz privada
      de la MatrizRectangular que estamos construyendo.
      Las dos versiones serían correctas.
      */
      
      MatrizRectangularReales suavizada(util_col);
      
      if (util_fil == util_col){
         for (int i=0; i<util_fil; i++){            
            suavizada.matriz_privada[i][i] = matriz_privada[i][i];
            
            for (int j=i+1; j<util_col; j++){
               double media = 0;
               
               for (int k=j; k<util_col; k++)
                  media = media + matriz_privada[i][k];          // Trabajamos directamente con las matrices de corchetes => Calculamos aquí la Media
               
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
   Para establecer el tipo de los extremos del intervalo (abierto/cerrado), lo lógico
   es usar sendos bool:
         bool es_cerrado_inferior, 
              es_cerrado_superior;
   Ahora bien, en el constructor sería deseable marcar el tipo de intervalo
   con un char '(', '[', ')', ']' pues es muy intuitivo.
   PERO dentro de la clase no compararemos con los caracteres específicos sino
   con los bool correspondientes.
                 
            
   Para establecer que un intervalo es vacío podríamos optar por alguna de estas alternativas:

   -  Asignar al extremos inferior un valor específico igual al extremo superior (por ejemplo 0)
      y establecer los extremos del intervalo abiertos.
     
      En vez de trabajar con tantas variables, simplemente podríamos hacer lo siguiente:
        
   -  Asignar al extremo inferior un valor estrictamente mayor que el extremo superior
   
      Otra posibilidad es usar un dato miembro explícito:
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
      Debemos construir los condicionales para que los caracteres (,),[,] estén en una única sentencia.
      Esto facilita la modificación futura del código.
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
   // topk = secuencia.Topk_Insertando(3);                           // Va muy rápido
   //topk = secuencia.Topk_OrdenandoTodoEficienteMemoria(secuencia.TotalUtilizados());  // Va muy rápido con secuencia_ordenada_de_menor_a_mayor pero lento con secuencia_ordenada_de_mayor_a_menor (Tarda el mismo tiempo que con k=3) 
   topk = secuencia.Topk_Insertando(secuencia.TotalUtilizados());  // Va muy rápido con secuencia_ordenada_de_mayor_a_menor pero lento con secuencia_ordenada_de_menor_a_mayor - tan lento como el anterior método con la otra secuencia-
   cout << "Termino";
   
   
   // Para k pequeño funciona mucho mejor Topk_Insertando
   // Para k grande, dependiendo de cómo esté el vector va mejor Topk_OrdenandoTodoEficienteMemoria o Topk_Insertando
   //    lo cual es lógico ya que el primero ordena de menor a mayor mientras que el segundo lo hace al revés.
   
   
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
   // Constructor muy intuitivo, aunque desgraciadamente, C++ aceptaría también 
   // Intervalo uno(0 , 2 ,'[', ')');  
   // ya que haría las transformaciones de tipo necesarias. 
   // En cualquier caso, si hemos programado bien el constructor, al no pasar un carácter válido
   // como parámetro a los tipos de los extremos, el intervalo se quedaría en vacío.
   
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

