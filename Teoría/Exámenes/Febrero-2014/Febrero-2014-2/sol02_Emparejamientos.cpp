/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Examen Febrero 2014
// Pregunta 2
//
// 31 de Enero de 2014
//
/*
	ENUNCIADO: 

	 Se dispone de un conjunto de cadenas de caracteres con los nombres de 
	 varios equipos de tenis de mesa participantes en un torneo. Se desea 
	 crear un vector que contenga todos los emparejamientos posibles. 
	 Por ejemplo, si se parte del conjunto {Albolote, Motril, Baza, La Zubia}, 
	 debe construirse el siguiente vector:

		{{Albolote, Motril}, {Albolote, Baza}, {Albolote, La Zubia},
		 {Motril, Baza}, {Motril, La Zubia}, {Baza, La Zubia} }

	Defina los tipos de datos y m\ódulos necesarios para resolver el problema 
	planteado. Tenga en cuenta que el número de equipos puede ser cualquiera 
	(no sólo 4 como en el ejemplo), el orden de los emparejamientos no tiene 
	porqué ser el anterior, sólo puede usar el tipo "string" para representar 
	el nombre de cada equipo y no es necesario crear el programa principal.

*/
/*********************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////
/* 
	Clase MiVectorCadenas para mantener una colección de string

	Esta clase no es estrictamente necesaria para resolver el problema 
	que nos ocupa. Podría haberse empleado directamente un vector de la 
	STL para guardar las cadenas y acceder a este almacenamiento a través 
	de los métodos sobe objetos de la STL (ver función main()).
*/

class MiVectorCadenas 
{

private:

	vector <string> vector_privado;

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiVectorCadenas (void) {}

	/*****************************************************************/
	// Métodos de lectura (Get)  

	int TotalUtilizados (void) 
	{
		return (vector_privado.size());
	}

	int Capacidad (void) 
	{
		return (vector_privado.capacity());
	}

	/*****************************************************************/
	// Añade un elemento al vector

	void Aniade(string nuevo)
	{
		vector_privado.push_back(nuevo);
	}

	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no está definido.

	string Elemento(int indice)
	{
		return (vector_privado[indice]);
	}

	/*****************************************************************/
	// Elimina todos los elementos

	void Limpia (void) 
	{
		vector_privado.clear();
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////
/*
	Clase importante, ya que la colección qe se debe calcular es una 
	colección de parejas de datos de tipo "string". 
	esta es una solución natural y directa aunque también hubiera 
	sido aceptable un "struct".
*/

class Pareja
{

private: 

	string elemento1;
	string elemento2;

public: 

	/*****************************************************************/
	// Constructor sin argumentos: pareja "vacía" (con cadenas vacías)

	Pareja (void) 
	{
		SetPareja ("", "");			
	}
	
	/*****************************************************************/
	// Constructor con argumentos.
	// Recibe los dos elementos de la pareja

	Pareja (string valor1, string valor2) 
	{
		SetPareja (valor1, valor2);			
	}

	/*****************************************************************/
	// Método de escritura
	
	void SetPareja (string valor1, string valor2) 
	{
		elemento1 = valor1;
		elemento2 = valor2;
	}

	/*****************************************************************/
	// Métodos de lectura

	string GetPrimero (void)
	{
		return (elemento1);
	}
	string GetSegundo (void)
	{
		return (elemento2);
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

class MiVectorParejas
{

private:

	vector <Pareja> vector_privado;

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiVectorParejas (void) {}

	/*****************************************************************/
	// Constructor a partir de un objeto MiVectorCadenas
	// Construye un vector de parejas con todas las parejas posibles 
	// tomando los elementos del vector que recibe

	MiVectorParejas (MiVectorCadenas un_vector_de_cadenas) 
	{
		string primer_elemento, segundo_elemento;  

		// "num_elementos" es el número de elementos en el vector que 
		// se emplea para generar las parejas

		int num_elementos = un_vector_de_cadenas.TotalUtilizados();


		for (int primero = 0; primero <num_elementos-1; primero++) {

			primer_elemento = un_vector_de_cadenas.Elemento(primero);

			// Calcular todas las parejas que incluyen a "primer_elemento"

			for (int segundo = primero+1; segundo<num_elementos; segundo++) {

				segundo_elemento = un_vector_de_cadenas.Elemento(segundo);

				Pareja pareja_nueva (primer_elemento, segundo_elemento);
				Aniade (pareja_nueva);

				// Las dos instrucciones anteriores pueden resumirse en: 
				// Aniade (Pareja (primer_elemento, segundo_elemento));

			} // for segundo

		} // for primero

	}

	/*****************************************************************/
	// Constructor a partir de un vector de la STL de datos string
	// Construye un vector de parejas con todas las parejas posibles 
	// tomando los elementos del vector que recibe

	MiVectorParejas (vector <string> un_vector_de_cadenas) 
	{
		string primer_elemento, segundo_elemento;  

		// "num_elementos" es el número de elementos en el vector que 
		// se emplea para generar las parejas

		int num_elementos = un_vector_de_cadenas.size();

		for (int primero = 0; primero <num_elementos-1; primero++) {

			primer_elemento = un_vector_de_cadenas.at(primero);

			// Calcular todas las parejas que incluyen a "primer_elemento"

			for (int segundo = primero+1; segundo<num_elementos; segundo++) {

				segundo_elemento = un_vector_de_cadenas.at(segundo);

				Pareja pareja_nueva (primer_elemento, segundo_elemento);
				Aniade (pareja_nueva);

				// Las dos instrucciones anteriores pueden resumirse en: 
				// Aniade (Pareja (primer_elemento, segundo_elemento));

			} // for segundo

		} // for primero

	}

	/*****************************************************************/

	// Métodos de lectura (Get)  

	int TotalUtilizados (void) 
	{
		return (vector_privado.size());
	}

	int Capacidad (void) 
	{
		return (vector_privado.capacity());
	}

	/*****************************************************************/
	// Añade un elemento al vector

	void Aniade(Pareja nuevo)
	{
		vector_privado.push_back(nuevo);
	}

	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no está definido.

	Pareja Elemento(int indice)
	{
		return (vector_privado[indice]);
	}

	/*****************************************************************/
	// Elimina todos los elementos

	void Limpia (void) 
	{
		vector_privado.clear();
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////


/*********************************************************************/
/*********************************************************************/

int main()
{

/*
	// Con un objeto MiVectorCadenas:

	MiVectorCadenas equipos;

	equipos.Aniade("Albolote");
	equipos.Aniade("Motril");
	equipos.Aniade("Baza");
	equipos.Aniade("La Zubia");
	equipos.Aniade("Maracena");

	int num_equipos = equipos.TotalUtilizados();

	cout << "Formando emparejamientos con " 
		 << num_equipos << " equipos." << endl; 
	cout << "Los equipos son: " << endl << endl;

	for (int pos=0; pos<num_equipos; pos++)
			cout << equipos.Elemento(pos) << endl;
	cout << endl << endl; 

*/
	// Con un vector de la STL: 

	vector <string> equipos;

	equipos.push_back ("Albolote");
	equipos.push_back ("Motril");
	equipos.push_back ("Baza");
	equipos.push_back ("La Zubia");
	equipos.push_back ("Maracena");

	int num_equipos = equipos.size();

	cout << "Formando emparejamientos con " 
		  << num_equipos << " equipos." << endl; 
	cout << "Los equipos son: " << endl << endl;

	for (int pos=0; pos<num_equipos; pos++)
		cout << equipos.at(pos) << endl; 
	cout << endl << endl; 


	// Creación del vector de parejas. Da igual si los equipos están en: 
	//	1) objeto MiVectorCadenas
	//	2) vector de la STL
	// porque el constructor de la clase MiVectorParejas está sobrecargado.

	MiVectorParejas emparejamientos (equipos);


	// Mostrar el resultado

	int num_parejas = emparejamientos.TotalUtilizados();

	cout << "Se han formado un total de " 
		 << num_parejas << " emparejamientos." << endl;
	cout << "Los emparejamientos son: " << endl << endl;

	for (int pos=0; pos<num_parejas; pos++) {

		Pareja una_pareja = emparejamientos.Elemento (pos);

		cout << "("  << una_pareja.GetPrimero() 
			 << ", "  << una_pareja.GetSegundo() << ")" 
			 << endl;
	}

	cout << endl << endl; 

	system ("pause");

	return (0);
} 

/*********************************************************************/
/*********************************************************************/
