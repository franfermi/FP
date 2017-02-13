/*
[Moda]. Se quiere calcular la moda de un vector de caracteres, es decir, el carácter
que más veces se repite. Por ejemplo, si el vector fuese
    {'l','o','s',' ','d','o','s',' ','c','o','f','r','e','s'}
los caracteres que más se repiten son 'o' y 's' con un total de 3 apariciones. La
moda sería cualquiera de ellos, por ejemplo, el primero encontrado 'o'.

Para almacenar de forma conjunta el carácter y la frecuencia usaremos el siguiente
struct :
    struct FrecuenciaCaracter{
        char caracter;
        int frecuencia;
    }
caracter contendrá el carácter en cuestión ( 'o' ) y en el campo
frecuencia el conteo de la moda (3).
*/

/*
La comprobación la he realizado con un fichero con menos texto
y funciona correctamente.
*/
#include <iostream>

using namespace std;

struct FrecuenciaCaracter{
    char caracter;
    int frecuencia;
};

int main()
{
    const char TERMINADOR = '#';
    /*No se que tamaño poner como tope ya que el archivo es muy grande,
    he probado con la librería climits pero me da error de segmento
    al asignar INT_MAX.*/
    const int TAMANIO = 100000;
    char vector[TAMANIO];
    char caracter, caracter_moda;
    int total_utilizados;
    int repeticiones, mayor_frecuencia;

    FrecuenciaCaracter freCar;

    total_utilizados = 0;
    mayor_frecuencia = 0;
    repeticiones = 0;
    caracter = cin.get();

    //Introducimos los caracteres del archivo en el vector
    while(caracter != TERMINADOR && total_utilizados < TAMANIO){
        vector[total_utilizados] = caracter;
        total_utilizados++;
        caracter = cin.get();
    }
    //Recorremos cada letra del vector de caracteres
    for(int i=0; i<total_utilizados; i++){
        //Con cada letra realizamos una nueva busqueda en el vector
        for(int j=0; j<total_utilizados; j++){
            //Contamos el numero de veces que aparece una misma letra
            if(vector[i] == vector[j]){
                repeticiones++;
                freCar.caracter = vector[i];
                freCar.frecuencia = repeticiones;
            }
            if(repeticiones > mayor_frecuencia){
                mayor_frecuencia = repeticiones;
                freCar.caracter = vector[i];
                freCar.frecuencia = mayor_frecuencia;
            }
        }
        repeticiones=0;
    }
    cout << "La moda es la letra '" << freCar.caracter << "' con un total de "
            << freCar.frecuencia << " apariciones." << endl;
}
