/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Examen Febrero 2014
// Pregunta 4
//
// 31 de Enero de 2014
//
/*
	ENUNCIADO: 

	Una matriz rectangular contiene valores enteros que representan medidas 
	tomadas sobre una determinada regi�n. Se supone que todos los valores 
	deben ser positivos aunque por problemas de captaci�n y registro algunos 
	de ellos son negativos.

	Es preciso corregir estos valores err�neos y se propone sustituirlos por 
	el valor promedio de sus OCHO vecinos m�s cercanos espacialmente. Debe 
	considerar que entre estos vecinos pudieran haber valores negativos,
	y en este caso NO intervendr�n en el c�lculo del valor promedio:

		Si hubiera un s�lo valor negativo en la vecindad, se sumar�n los 
		valores de los 7 vecinos v�lidos y la suma se dividir� entre 7.
		Si hubiera dos valores negativos en la vecindad, se sumar�n los 
		valores de los 6 vecinos v�lidos y la suma se dividir\'a entre 6. 
		... Si no hubiera ning�n valor v�lido, se sustituir� por un cero.

	Implemente un m�dulo para que dada una matriz rectangular como las 
	descritas, devuelva OTRA matriz rectangular corregida. 
	La matriz original NO se modifica.

	Para la implementaci�n debe considerar:
		1.- La matriz puede ser muy grande.
		2.- El algoritmo debe ser simple y claro.
		3.- Para simplificar, las casillas de los bordes NO se modifican,
			aunque S� se usan para efectuar las correcciones oportunas. 
			En definitiva, la primera y la �ltima fila as� como la primera 
			y la �ltima columna son iguales entre la matriz original y la 
			corregida.
*/
/*********************************************************************/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

///////////////////////////////////////////////////////////////////////

class MiMatrizRectangularEnteros
{

private:

	vector <vector <int>> matriz_privada;

	int filas_utilizadas;
	int cols_utilizadas;

public:

	/*****************************************************************/
	// Constructor a)
	// Recibe "numero_de_columnas" que indica el n�mero de columnas 
	// que deben tener TODAS las filas.

	MiMatrizRectangularEnteros (int numero_de_columnas)
		: filas_utilizadas(0), 
		  cols_utilizadas(numero_de_columnas)
	{
	}

	/*****************************************************************/
	// Constructor b)
	// Recibe un vector STL. La longitud de dicho vector (num. de casillas) 
	// es el valor que se usa como "numero_de_columnas"

	MiMatrizRectangularEnteros (vector <int> primera_fila)
		: filas_utilizadas(0), cols_utilizadas (primera_fila.size())
	{
		Aniade(primera_fila);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero m�ximo de filas

	int CapacidadFilas()
	{
		return matriz_privada.capacity();
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero m�ximo de columnas

	int CapacidadColumnas()
	{
		return (matriz_privada[0]).capacity();
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de filas usadas

	int FilasUtilizadas()
	{
		return matriz_privada.size();
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de columnas usadas

	int ColumnasUtilizadas()
	{
		return (matriz_privada[0]).size();
	}

	/*****************************************************************/
	// M�todos de acceso a los valores de la matriz.
	// PRE: la posici�n dada por (fila, columna) es v�lida

	int GetElemento(int fila, int columna)
	{
		return matriz_privada[fila][columna];
	}

	void SetElemento(int fila, int columna, int valor)
	{
		if ((0<=fila) && (fila<filas_utilizadas) && 
			(0<=columna) && (columna<cols_utilizadas))
		matriz_privada[fila][columna] = valor;
	}

	/*****************************************************************/
	// Devuelve una fila completa, en forma de un vector de la STL
	// PRE: la fila dada por "indice_fila" es v�lida

	vector <int> Fila (int indice_fila)
	{
		return (matriz_privada[indice_fila]);
	}

	/*****************************************************************/
	// A�ade una fila completa. La fila se porporciona en forma de un 
	// vector de la STL. 
	// PRE: el n�mero de casillas de "fila_nueva" es igual a "col_utilizadas"

	void Aniade(vector <int> fila_nueva)
	{
		if (fila_nueva.size() == cols_utilizadas){
			matriz_privada.push_back(fila_nueva);
			filas_utilizadas++;
		}
	}

	/*****************************************************************/
	// Modifica las casilla con valor negativo cambiando ese valor por 
	// el promedio de sus ocho vecinos. 
	// Si alguno de los vecinos fuera negativo no entra en el promedio. 
	// Si todos fueran negativos, se sustituye por un cero. 
	// El m�todo devuelve OTRA matriz. 

	MiMatrizRectangularEnteros CorrigePorPromedio (void)
	{
		int num_fils = FilasUtilizadas();
		int num_cols = ColumnasUtilizadas();

		// Hacer una copia de la matriz para calcular el promedio en base 
		// a los valores originales de la matriz.
		// Proponemos esta soluci�n para usar los m�todos disponibles en la 
		// clase MiMatrizRectangularEnteros y no tener que a�adir nuevos 
		// m�todos.
		// SUGERENCIA: En este sentido, piense en escribir un m�todo privado 
		// llamado Copia() que hiciera esta tarea. 

		MiMatrizRectangularEnteros tmp (num_cols); 

		for (int f=0; f<num_fils; f++) {
			vector <int> fila = Fila (f);
			tmp.Aniade (fila);
		}

		// Fin de copia: la matriz impl�cita y la matriz "tmp" son id�nticas.


		// Recorrido por filas de la matriz impl�cita (sin procesar los bordes)
		// buscando valores negativos, para su correcci�n.

		for (int fila=1; fila<=num_fils-2; fila++) {

			for (int col=1; col<=num_cols-2; col++) {

				// Procesamiento de la casilla [fila][col]

				// Se corregir� si su contenido es negativo

				if (GetElemento(fila,col) < 0) {

					int cont_validos = 0; // Contador v�lidos
					int suma_validos = 0; // Acumulador v�lidos

					// Recorrer la 8-vecindad: desde la fila anterior 
					// a "fila" hasta la posterior, y desde la columna 
					// anterior a "col" hasta la posterior

					for (int f=fila-1; f<=fila+1; f++) {

						for (int c=col-1; c<=col+1; c++) {

							// El valor de la casilla (f,c) intervine 
							// �nicamente si es v�lido (positivo o cero)
							//
							// No es preciso hacer una distinci�n especial para
							// la casilla (fila,col)--> Sabemos que es negativo
							// por lo que nunca interviene para el valor medio. 
							// Hacer esta distinci�n oscurecer�a el algoritmo.

							int valor_f_c = GetElemento(f,c);
							if (valor_f_c >= 0) {
								cont_validos++;
								suma_validos += valor_f_c;
							}

						} // for c

					} // for f

					if (suma_validos > 0)
						// Sutituir por el valor promedio 
						tmp.SetElemento(fila,col, suma_validos/cont_validos);
					else
						// Sutituir por cero
						tmp.SetElemento(fila,col, 0);

				} // if (GetElemento(fila,col) < 0 


			} // for col 

		} // for fila

		return (tmp); 
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

class LectorMatrizRectangular
{

private:

	int filas_lector;
	int cols_lector;

public: 

	/*****************************************************************/
	// Constructor con argumentos. 

	LectorMatrizRectangular (int num_filas, int num_cols) 
		: filas_lector (num_filas), cols_lector (num_cols) 
	{ }

	/*****************************************************************/
	// M�todo general de lectura 
	
	MiMatrizRectangularEnteros LeeMatrizRectangularEnteros ()
	{
	
		MiMatrizRectangularEnteros tmp (cols_lector);

		cout << endl;

		for (int f=0; f<filas_lector; f++) {

			cout << "FILA " << f << endl;

			vector <int> una_fila; 
			int un_valor; 

			for (int c=0; c<cols_lector; c++) {

				cout << "Elemento de la columna " << c << " : ";
				cin >> un_valor;

				una_fila.push_back (un_valor);

			} // for c

			tmp.Aniade (una_fila);

		} // for f

		return (tmp);
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

class ImpresorMatrizRectangular
{
private:

public: 

	/*****************************************************************/
	// Constructor sin argumentos. 

	ImpresorMatrizRectangular (void) { }

	/*****************************************************************/
	// M�todo general de escritura 
	
	void MuestraMatrizRectangularEnteros (MiMatrizRectangularEnteros m)
	{
		cout << endl;

		int num_filas = m.FilasUtilizadas();
		int num_cols  = m.ColumnasUtilizadas();

		for (int f=0; f<num_filas; f++) {

			cout << "FILA " << f << endl;

			for (int c=0; c<num_cols; c++) {
		
				cout << setw(3) << m.GetElemento (f,c); 	

			} // for c

			cout << endl;

		} // for f

		cout << endl;
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////


int main()
{
	// Lee y filtra las dimensiones de la matriz y crea el objeto matriz

	int filas, cols; 

	do {
		cout << "Num. filas: "; 
		cin >> filas;
	} while (filas <=0);

	do {
		cout << "Num. columnas: "; 
		cin >> cols;
	} while (cols <=0);


	// Crea y rellena la matriz con valores estrictamente positivos y la muestra
	
	LectorMatrizRectangular		lector_matrices_rectangulares (filas, cols);
	ImpresorMatrizRectangular	escritor_matrices_rectangulares;

	MiMatrizRectangularEnteros m = 
			lector_matrices_rectangulares.LeeMatrizRectangularEnteros ();

	escritor_matrices_rectangulares.MuestraMatrizRectangularEnteros (m);


	// Crea una matriz para guardar el resultado, llama al m�todo 
	// CorrigePorPromedio() y muestra la matriz resultado 
	
	MiMatrizRectangularEnteros corregida = m.CorrigePorPromedio();

	escritor_matrices_rectangulares.MuestraMatrizRectangularEnteros(corregida);


	system ("pause");

	return (0);
} 
