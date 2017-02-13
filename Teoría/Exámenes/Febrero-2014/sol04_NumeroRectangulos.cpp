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

	Cree una funci�n recursiva llamada NumeroRectangulos que determine
	cu�ntos rect�ngulos inscritos caben en un rect�ngulo, con la restricci�n
	de que sus �reas sean superior o igual a un valor dado. Todos los 
	rect�ngulos inscritos comparten la esquina inferior izquierda, aunque 
	las longitudes de sus lados se reducen a la mitad. 
	Por ejemplo, dado el rect�ngulo de la figura la funci�n devolver� 2 si 
	el �rea m�nima es 10. Observe que devolver� 3 si el �rea m�nima fuera 2. 
	Se deja al alumno la elecci�n de los par�metros de la funci�n con la 
	salvedad de que {\bf no se pasen longitudes de lados}.
	Se valorar� el dise�o correcto de la funci�n. 
	Indique la llamada a NumeroRectangulos desde main.


	     (10,15)                    (30,15)
           |--------------------------|
		   |                          |
		   |                          |
           |           (20, 10)       |
    (10,10)|-------------|            |
           |             |            |
           |------|      |            |
           |      |      |            |
           |------|------|------------| 
	     (10,5)        (20,5)       (30,5)

*/
/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/
// Funci�n recursiva que calcula cu�ntos rect�ngulos inscritos caben 
// en un rect�ngulo (dado por las coordenadas de las esquinas inferior 
// izquierda y superior derecha) con la restricci�n de que sus �reas 
// sean superior o igual a un valor dado. 
// Todos los rect�ngulos inscritos comparten la esquina inferior 
// izquierda, pero las longitudes de sus lados se reducen a la mitad. 

int NumeroRectangulos (double eii_x, double eii_y, 
					   double esd_x, double esd_y, 
					   double area_minima)
{
	// Calcular la esquina superior derecha de un nuevo rect�ngulo  
	// (la esquina inferior izquierda no va a cambiar) 

	double nueva_esd_x = (esd_x + eii_x) / 2;
	double nueva_esd_y = (esd_y + eii_y) / 2;

	// �rea del nuevo rect�ngulo
	double nueva_area = (nueva_esd_x - eii_x) * (nueva_esd_y - eii_y);


	if (nueva_area >= area_minima)	// Caso general --> seguir
		return (1 + NumeroRectangulos (eii_x, eii_y, 
			                           nueva_esd_x, nueva_esd_y, 
									   area_minima));
	else // Caso base --> terminar
		return (0);
}

/*********************************************************************/
int main (void)
{

	double eii_x, eii_y; // Coordenadas de la esquina inferior izquierda 
	double esd_x, esd_y; // Coordenadas de la esquina superior derecha 
	double area_minima;  // Area m�mima de los rect�ngulos inscritos

	// Lectura de las coordenadas
	// NOTA: No se hacen comprobaciones 

	cout << "Coordenadas de la esquina inferior izquierda." << endl;
	cout << "   Abscisa: ";
	cin >> eii_x;
	cout << "   Ordenada: ";
	cin >> eii_y;

	cout << "Coordenadas de la esquina superior derecha." << endl;
	cout << "   Abscisa: ";
	cin >> esd_x;
	cout << "   Ordenada: ";
	cin >> esd_y;

	do {
		cout << "Area m�mima de los rect�ngulos inscritos: ";
		cin >> area_minima;
	} while (area_minima < 0); 


	while (area_minima > 0) {

		int num_rectangulos = 
			NumeroRectangulos (eii_x, eii_y, esd_x, esd_y, area_minima);

		cout << "El numero de rectangulos inscritos es = " 
			 << num_rectangulos << endl; 

		do {
			cout << "Area m�mima de los rect�ngulos inscritos: ";
			cin >> area_minima;
		} while (area_minima < 0); 

	} // while (area_minima > 0)

	cout << endl << endl; 
	system ("pause");

	return (0);
}

/*********************************************************************/
 
