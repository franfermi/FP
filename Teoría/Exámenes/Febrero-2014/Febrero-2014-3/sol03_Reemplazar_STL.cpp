
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
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////

class MiVectorCaracteres 
{

private:

	vector <char> vector_privado;

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiVectorCaracteres() { }

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 

	int TotalUtilizados()
	{
		return vector_privado.size();
	}

	int Capacidad()
	{
		return vector_privado.capacity();
	}

	/*****************************************************************/
	// Añade un elemento al vector
	
	void Aniade(char nuevo)
	{
		vector_privado.push_back(nuevo);
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
	// Reemplaza una parte de la cadena por otra nueva

	void Reemplazar (int pos, int n, MiVectorCaracteres nueva_cad)
	{

		if ((0 <= pos) && (pos < TotalUtilizados()) && (n > 0)) 
		{
			vector <char> tmp; 

			for (int p=0; p<pos; p++) 
				tmp.push_back (Elemento(p));

			int num_caracteres_nueva = nueva_cad.TotalUtilizados();

			for (int pos_nueva=0; pos_nueva<num_caracteres_nueva; pos_nueva++) 
				tmp.push_back (nueva_cad.Elemento(pos_nueva));
			
			// Saltar "n" y seguir copiando

			int num_caracteres = TotalUtilizados();

			for (int p=pos+n; p<num_caracteres; p++) 
				tmp.push_back (Elemento(p));

			// Reestablecer el objeto implícito copiando en él lo que 
			// hemos montado sobre el objeto temporal "tmp"

			vector_privado = tmp;
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
 
