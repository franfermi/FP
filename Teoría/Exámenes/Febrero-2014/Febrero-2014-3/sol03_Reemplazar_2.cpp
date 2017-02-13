/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Examen Febrero 2014
// Pregunta 3
//
// 31 de Enero de 2014
//
/*
	ENUNCIADO: 

	Existe un método para la clase "string" de C++, denominado "replace", 
	que cambia  "n" caracteres de una cadena "cad1", empezando en una 
	determinada posición  "pos", por los caracteres presentes en una 
	segunda cadena  "cad2". La llamada al método es:  
		cad1.replace(pos, n, cad2) 
		
	Ejemplos del funcionamiento de "replace" son:

	string cad1="Fundamental Programación";
	cad1.replace(9,2,"os de la");   // "al" -> "os de la"
									// Ahora cad1 tiene 
									//		"Fundamentos de la Programación"
	cad1.replace(12,5,"en");        // "de la" -> "en"
									// Ahora cad1 tiene 
											"Fundamentos en Programación"
	
	Realizar un módulo llamado  "reemplazar" con la misma funcionalidad que
	"replace", para trabajar con cadenas de caracteres, pero con la 
	restricción de que NO SE PUEDE utilizar la clase "string".

*/
/*********************************************************************/

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////

class MiVectorCaracteres 
{

private:

	static const int TAMANIO = 50;
	char vector_privado[TAMANIO];
	int total_utilizados;

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiVectorCaracteres() 	{
		total_utilizados = 0;
	}

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 

	int TotalUtilizados()
	{
		return total_utilizados;
	}

	int Capacidad()
	{
		return TAMANIO;
	}

	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no está definido.

	char Elemento(int indice)
	{
		return vector_privado[indice];
	}

	/*****************************************************************/
	// Elimina todos los elementos

	void Limpia ()
	{
		total_utilizados = 0;
	}

	/*****************************************************************/
	// Añade un elemento al vector
	// PRE: hay espacio para el nuevo elemento.
	// Si no lo hay, no hace nada.
	
	void Aniade(char nuevo)
	{
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/*****************************************************************/
	// Eliminar el elemento que se encuentre en la posición dada por 
	// "indice_componente".
	// Realiza un borrado físico (con desplazamiento y sustitución).
	// PRE: la posición dada por "posicion" es correcta.
	// Si no es correcta, no hace nada.

	void Elimina (int posicion) 
	{
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posición a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((posicion >= 0) && (posicion < total_utilizados)) {

			int tope = total_utilizados-1; // posición del último 
    
			for (int i = posicion ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];  
    
			total_utilizados--;    
		}
	}

	/*****************************************************************/
	// Inserta a partir de una posición dada un nuevo vector
	// PRE: hay espacio para el nuevo subvector "nuevo".
	// PRE: La posición "pos" es correcta 
	//		0 <= pos < TotalUtilizados() 
	// Si no se cumplen no hace nada.
	
	void InsertaMiVectorCaracteres(int pos, MiVectorCaracteres nuevo)
	{
		int num_caracteres = TotalUtilizados();
		int num_caracteres_nuevo = nuevo.TotalUtilizados();

		bool pos_OK = ((0 <= pos) && (pos < TotalUtilizados())); 
		bool cabe = (num_caracteres+num_caracteres_nuevo < Capacidad());

		if (pos_OK && cabe)
		{
	
			for (int n=num_caracteres-1; n>=pos; n--) 
				vector_privado[n+num_caracteres_nuevo] = vector_privado[n];

			for (int n=0; n<num_caracteres_nuevo; n++) 
				vector_privado[pos+n] = nuevo.Elemento(n);
			
			total_utilizados += num_caracteres_nuevo;
		}
	}

	/*****************************************************************/
	// Borra una parte del vector, dadas la posición inicial "pos" y 
	// el número de elementos a borrar "num_elementos"
	// PRE: La posición "pos" es correcta 
	//		0 <= pos < TotalUtilizados() 
	// PRE: El número de elementos es correcto
	//		num_elementos >= 0
	// Si no se cumplen no hace nada.
	
	void EliminaSubVectorCaracteres(int pos, int num_elementos)
	{
		bool pos_OK = ((0 <= pos) && (pos < TotalUtilizados())); 

		if (pos_OK && (num_elementos >= 0))
		{
			int num_caracteres = TotalUtilizados();

			for (int n=pos; n<num_caracteres-num_elementos; n++)
				vector_privado[n] = vector_privado[n+num_elementos];

			total_utilizados -= num_elementos;
		}

	}

	/*****************************************************************/
	// Reemplaza una parte de la cadena por otra nueva
	// PRE: Hay espacio para la nueva cadena resultante del 
	//		"corte e inserción". Si no, no se hace nada. 

	void Reemplazar (int pos, int n, MiVectorCaracteres nueva_cad)
	{
		int num_caracteres = TotalUtilizados();
		int num_caracteres_nueva = nueva_cad.TotalUtilizados();

		bool args_OK = ((0 <= pos) && (pos < TotalUtilizados()) && (n > 0)); 
		bool cabe = (num_caracteres-n+num_caracteres_nueva < Capacidad());

		if (args_OK && cabe)
		{
			EliminaSubVectorCaracteres(pos, n);
			InsertaMiVectorCaracteres (pos, nueva_cad);
		}
	}

	/*****************************************************************/

};


///////////////////////////////////////////////////////////////////////

class ImpresorMiVectorCaracteres 
{

private:

public:

	/*****************************************************************/
	// Constructor sin argumentos. 

	ImpresorMiVectorCaracteres (void) { }

	/*****************************************************************/
	// Método general de escritura 
	
	void MuestraMiVectorCaracteres (MiVectorCaracteres v)
	{
		int num_caracteres = v.TotalUtilizados();
		for (int pos=0; pos<num_caracteres; pos++)
			cout << v.Elemento (pos);
		cout << endl << endl; 
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////


/*********************************************************************/
/*********************************************************************/

int main()
{ 
	ImpresorMiVectorCaracteres impresor_cadenas;

	// Iniciar y rellenar cad

	MiVectorCaracteres cad;
	cad.Aniade('F');
	cad.Aniade('u');
	cad.Aniade('n');
	cad.Aniade('d');
	cad.Aniade('a');
	cad.Aniade('m');
	cad.Aniade('e');
	cad.Aniade('n');
	cad.Aniade('t');
	cad.Aniade('a');
	cad.Aniade('l');
	cad.Aniade(' ');
	cad.Aniade('P');
	cad.Aniade('r');
	cad.Aniade('o');
	cad.Aniade('g');
	cad.Aniade('r');
	cad.Aniade('a');
	cad.Aniade('m');
	cad.Aniade('a');
	cad.Aniade('c');
	cad.Aniade('i');
	cad.Aniade('ó');
	cad.Aniade('n');

	cout << "cadena original cad: " << endl; 
	impresor_cadenas.MuestraMiVectorCaracteres (cad);


	// Iniciar y rellenar nueva_cad

	MiVectorCaracteres nueva_cad;
	nueva_cad.Aniade('o');
	nueva_cad.Aniade('s');
	nueva_cad.Aniade(' ');
	nueva_cad.Aniade('d');
	nueva_cad.Aniade('e');
	nueva_cad.Aniade(' ');
	nueva_cad.Aniade('l');
	nueva_cad.Aniade('a');

	cout << "nueva_cad: " << endl; 
	impresor_cadenas.MuestraMiVectorCaracteres (nueva_cad);


	// Iniciar y rellenar otra_nueva_cad

	MiVectorCaracteres otra_nueva_cad;
	otra_nueva_cad.Aniade('e');
	otra_nueva_cad.Aniade('n');

	cout << "otra_nueva_cad: " << endl; 
	impresor_cadenas.MuestraMiVectorCaracteres (otra_nueva_cad);


	// Reemplazar (Ejemplo 1)

	cad.Reemplazar(9, 2, nueva_cad);

	cout << "Ejecucion de cad.Reemplazar (9,2,nueva_cad): " << endl; 
	impresor_cadenas.MuestraMiVectorCaracteres (cad);


	// Reemplazar (Ejemplo 2)

	cout << "Ejecucion de cad.Reemplazar (12,5,otra_nueva_cad): " << endl; 
	
	cad.Reemplazar(12, 5, otra_nueva_cad);

	impresor_cadenas.MuestraMiVectorCaracteres (cad);


	cout << endl << endl; 

	system ("pause");

	return (0);
} 

/*********************************************************************/
/*********************************************************************/
