/*
[Elimina bloque, versión ineficiente]. Sobre la clase SecuenciaCaracteres , añada
el método EliminaBloque para que borre todos los caracteres que haya entre dos
posiciones. Por ejemplo, después de eliminar el bloque que hay entre las posiciones
1 y 3 de la secuencia {'S','o','Y',' ','y','o'} , ésta debe quedarse con
{'S','y','o'} .
Un primer algoritmo para resolver este problema sería el siguiente (en ejercicios pos-
teriores se verán métodos más eficientes):
    Para borrar el bloque entre izda y dcha:
        Recorrer cada componente -i- de la secuencia
        entre las posiciones izda y dcha
            Eliminar dicha componente -i-
Para eliminar una posición llame al método Elimina (que borra un único carácter) La
implementación de este método se ha visto en clase de teoría.
Construya un programa que lea caracteres hasta el terminador # . A continuación lea
dos enteros que representen las posiciones izquierda (≥ 0) y derecha (entre izquierda
y la última componente de la secuencia) (use las funciones LeeIntMayorIgualQue
y LeeIntRango de los ejercicios 4 y 5 de esta relación de problemas) e imprima la
secuencia resultante de quitar el bloque de caracteres.
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

    int LeeIntMayorIgualQue(){
        int a_leer;

        do{
          cout << "Introduce la posición izquierda: ";
          cin >> a_leer;
       }while (a_leer < 0);

       return a_leer;
    }

    int LeeIntRango(int min, int max) {
       int a_leer;

       do{
          cout << "Introduce la posición derecha: ";
          cin >> a_leer;
       }while (min > a_leer || max < a_leer);

       return a_leer;
    }

    void Elimina(int pos){
        int i;
        total_utilizados--;
        for(i=pos; i<total_utilizados; i++)
            vector_privado[i] = vector_privado[i+1];
    }

    void EliminaBloque(int pos_izq, int pos_dcha){
        int i, diferencia;
        i = pos_izq, diferencia = pos_dcha - pos_izq;
        while(diferencia >= 0){
            Elimina(i);
            diferencia--;
        }
    }
};

int main(){
    const char TERMINADOR = '#';
    char caracter;
    SecuenciaCaracteres secuencia;
    int utilizados_en_secuencia;
    int capacidad_secuencia;
    int total_introducidos;
    int izq, dcha;

    capacidad_secuencia = secuencia.Capacidad();
    total_introducidos = 0;
    cin >> caracter;

    while (caracter != TERMINADOR && total_introducidos < capacidad_secuencia){
        secuencia.Aniade(caracter);
        total_introducidos++;
        cin >> caracter;
    }

    izq = secuencia.LeeIntMayorIgualQue();
    dcha = secuencia.LeeIntRango(izq, total_introducidos);

    secuencia.EliminaBloque(izq, dcha);
    utilizados_en_secuencia = secuencia.TotalUtilizados();

    for (int i=0; i < utilizados_en_secuencia; i++)
        cout << secuencia.Elemento(i);
}
