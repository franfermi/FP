/*
(Examen Febrero 2009) Sgeún un etsduio de una uivenrsdiad ignlsea, no ipmotra el
odren en el que las ltears etsan ersciats, la úicna csoa ipormtnate es que la pmrirea y
la útlima ltera etsén ecsritas en la psioción cocrrtea. El rsteo peuden estar ttaolmntee
mal y aún pordás lerelo sin pobrleams. Etso es pquore no lemeos cada ltera por sí
msima snio la paalbra cmoo un tdoo. Diremos que dos palabras son similares si la
primera letra de ambas palabras es igual, la última letra de ambas palabras también
es igual y el resto de las letras son las mismas pero no están necesariamente en
las mismas posiciones. De esta forma, las palabras ttalomntee y totalmente son sim-
ilares. Declare en el main dos objetos de la clase SecuenciaCaracteres y asígneles
algunos caracteres de prueba. Implemente en el main un algoritmo que compruebe si
los dos objetos son similares según el criterio anterior. Si lo necesita, puede añadir los
métodos que estime oportunos a la clase SecuenciaCaracteres.
*/
//NO FUNCIONA
#include <iostream>

using namespace std;

class SecuenciaCaracteres{
    private:
        static const int TAMANIO = 50;
        char vector_privado[TAMANIO];
        int total_utilizados;
    public:
        SecuenciaCaracteres()
        :total_utilizados(0) {
        }
        int TotalUtilizados(){
            return total_utilizados;
        }
        int Capacidad(){
            return TAMANIO;
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
        int getTAMANIO(){
            return TAMANIO;
        }
};

int main()
{
    const char FIN = '#';
    SecuenciaCaracteres sec1, sec2;
    char texto;
    bool iguales = true;
    int num_apa;

    cout << "Introduce caracteres al vector desordenado, (# para finalizar): ";
    texto = cin.get();

    while(texto != FIN && sec1.TotalUtilizados() < sec1.getTAMANIO()){
        sec1.Aniade(texto);
        texto = cin.get();
    }

    cout << "Introduce caracteres al vector ordenado, (# para finalizar): ";
    texto = cin.get();

    while(texto != FIN && sec2.TotalUtilizados() < sec2.getTAMANIO()){
        sec2.Aniade(texto);
        texto = cin.get();
    }

    //Se muestra por pantalla el texto que contiene ambos objetos
    cout << "\n-----------------------------------------------" << endl;
    for(int i=0; i<sec1.TotalUtilizados(); i++)
        cout << sec1.Elemento(i);

    for(int i=0; i<sec2.TotalUtilizados(); i++)
        cout << sec2.Elemento(i);
    cout << "\n-----------------------------------------------" << endl;

    int i, j = 0;
    int contPalabra = 0;
    while(contPalabra < sec1.TotalUtilizados() && iguales){
        SecuenciaCaracteres palabra1, palabra2;

        for(i=contPalabra; i < sec1.TotalUtilizados() && sec1.Elemento(i) != ' '; i++)
            palabra1.Aniade(sec1.Elemento(i)); //Almacenamos cada palabra hasta el espacio en blanco

        for(j=contPalabra; j < sec2.TotalUtilizados() && sec2.Elemento(j) != ' '; j++)
            palabra2.Aniade(sec2.Elemento(j)); //Almacenamos cada palabra hasta el espacio en blanco

        int tamP1 = palabra1.TotalUtilizados();
        int tamP2 = palabra2.TotalUtilizados();

        cout << tamP1 << " " << tamP2 << endl;  //En la segunda palabra siempre me cuenta un caracter más

        if(tamP1 == tamP2){
            if(palabra1.Elemento(0) == palabra2.Elemento(0) &&
                    palabra1.Elemento(sec1.TotalUtilizados()-1) == palabra2.Elemento(sec2.TotalUtilizados()-1))
                iguales = true;
            else
                iguales = false;
        }else
            iguales = false;

        if(iguales)
            cout << "Son iguales";
        else
            cout << "No son iguales";

        contPalabra = i+1; //Para que la siguiente palabra la cuente despues del espacio
    }
}
