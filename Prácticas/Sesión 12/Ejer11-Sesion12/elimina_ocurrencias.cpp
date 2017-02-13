/*
[Elimina ocurrencias]. Sobre la clase SecuenciaCaracteres , añada el método
EliminaOcurrencias para eliminar todas las apariciones de un determinado ca-
rácter a_borrar . Por ejemplo, después de eliminar el carácter 'o' de la secuencia
{'S','o','Y',' ','y','o'} , ésta debe quedarse con {'S','Y',' ','y'} .
Un primer algoritmo para resolver este problema sería el siguiente (en ejercicios pos-
teriores se verán métodos más eficientes):
Recorrer todas las componentes de la secuencia
Si la componente es igual al carácter a_borrar, eliminarla
(desplazando hacia la izda las componentes que hay a su dcha)
Queremos implementarlo llamando al método Elimina (que borra un único carácter)
La implementación de este método se ha visto en clase de teoría.
class SecuenciaCaracteres{
    .........
    void EliminaOcurrenciasERROR(){
    for (int i = 0; i < total_utilizados; i++)
    if (vector_privado[i] == a_borrar)
    Elimina(i);
    }
};

El anterior código tiene un fallo. ¿Cuál?
-El fallo sería que solo borra la primera aparición del elemento a borrar si está de forma consecutiva.
Una solución simple pero efectiva es:
Si encontramos una ocurrencia la eliminamos y volvemos a iniciar el bucle a una posición anterior
a la cual se ha encontrado la ocurrencia ya que el método Elimina() los desplaza a la izquierda.
*/

#include <iostream>
using namespace std;

class SecuenciaCaracteres{
private:
    static const int TAMANIO = 50;
    char vector_privado[TAMANIO];
    int total_utilizados;

public:
    SecuenciaCaracteres()
        :total_utilizados(0){
    }

    int TotalUtilizados(){
        return total_utilizados;
    }

    int Capacidad(){
        return TAMANIO;
    }

    void EliminaTodos(){
        total_utilizados = 0;
    }

    void Aniade(char nuevo){
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    void Modifica(int posicion, char nuevo){
        if (posicion >= 0 && posicion < total_utilizados)
            vector_privado[posicion] = nuevo;
    }

    char Elemento(int indice){
        return vector_privado[indice];
    }

    void Elimina(int pos){
        int i;
        total_utilizados--;
        for(i=pos; i<total_utilizados; i++)
            vector_privado[i] = vector_privado[i+1];
    }

    void EliminaOcurrencias(char a_borrar){
        for(int i=0; i<total_utilizados; i++)
            if(vector_privado[i] == a_borrar){
                Elimina(i);
                i=i-1;
            }
    }
};

int main(){
   const char TERMINADOR = '#';
   char caracter, a_eliminar;
   SecuenciaCaracteres secuencia;
   int utilizados_en_secuencia;
   int capacidad_secuencia;
   int total_introducidos;

   capacidad_secuencia = secuencia.Capacidad();
   total_introducidos = 0;
   cin >> caracter;

   while (caracter != TERMINADOR && total_introducidos < capacidad_secuencia){
      secuencia.Aniade(caracter);
      total_introducidos++;
      cin >> caracter;
   }

   cout << "Introduce el caracter a eliminar: ";
   cin >> a_eliminar;

   secuencia.EliminaOcurrencias(a_eliminar);
   utilizados_en_secuencia = secuencia.TotalUtilizados();

   for (int i=0; i < utilizados_en_secuencia; i++)
     cout << secuencia.Elemento(i);
}
