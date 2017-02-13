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

/*********************************************************************/
/*********************************************************************/

struct ParejaEquipos
{
	string Equipo1;  
	string Equipo2;  
};

/*********************************************************************/
/*********************************************************************/

vector <ParejaEquipos> CreaEmparejamientos (vector <string> equipos)
{
	vector <ParejaEquipos> tmp;

	string primer_elemento, segundo_elemento;  

	// "num_elementos" es el número de elementos en el vector que 
	// se emplea para generar las parejas

	int num_elementos = equipos.size();

	for (int primero = 0; primero <num_elementos-1; primero++) {

		primer_elemento = equipos.at(primero);

		// Calcular todas las parejas que incluyen a "primer_elemento"

		for (int segundo = primero+1; segundo<num_elementos; segundo++) {

			segundo_elemento = equipos.at(segundo);

			ParejaEquipos pareja_nueva;
			pareja_nueva.Equipo1 = primer_elemento;
			pareja_nueva.Equipo2 = segundo_elemento;

			tmp.push_back (pareja_nueva);

		} // for segundo

	} // for primero

	return (tmp);
}


/*********************************************************************/
/*********************************************************************/

int main()
{

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


	// Creación del vector de parejas. 

	vector <ParejaEquipos> emparejamientos = CreaEmparejamientos (equipos);

	// Mostrar el resultado

	int num_parejas = emparejamientos.size();

	cout << "Se han formado un total de " 
		 << num_parejas << " emparejamientos." << endl;
	cout << "Los emparejamientos son: " << endl << endl;

	for (int pos=0; pos<num_parejas; pos++) {

		ParejaEquipos una_pareja = emparejamientos.at(pos);

		cout << "("   << una_pareja.Equipo1 
			 << ", "  << una_pareja.Equipo2 << ")" << endl;
	}

	cout << endl << endl; 

	system ("pause");

	return (0);
} 

/*********************************************************************/
/*********************************************************************/
 
