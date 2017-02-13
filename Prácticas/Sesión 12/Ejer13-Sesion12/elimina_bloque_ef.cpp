/*
[Elimina bloque, versión eficiente]. Resuelva el ejercicio 12 pero de una forma eficiente.
Para ello, implemente el siguiente algoritmo:
    Para borrar el bloque entre izda y dcha:
        Calcular num_a_borrar como dcha - izda + 1
        Recorrer las componentes -i- de la secuencia
        entre las posiciones dcha+1 hasta el final
            Colocar la componente -i- en la posición
            i - num_a_borrar
        Actualizar total_utilizados
Este algoritmo resuelve el problema con un único bucle mientras que la versión inefi-
ciente recurría a dos bucles anidados.
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

    void EliminaBloque(int pos_izq, int pos_dcha){
        int num_a_borrar;
        num_a_borrar = pos_dcha - pos_izq + 1;
        //Iniciamos el bucle en la posición siguiente a la derecha del bloque
        for(int i=pos_dcha+1; i<total_utilizados; i++)
            //Asignamos a la posición anterior a la izquierda del bloque,
            //los elementos que están a la derecha del bloque
            vector_privado[i - num_a_borrar] = vector_privado[i];
        //Actualizamos el total_utilizados restandole los numeros a borrar
        total_utilizados -= num_a_borrar;
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

