#include <iostream>

using namespace std;

class MiVectorCaracteres{
    private:
        static const int MAX = 50;
        char vector_privado[MAX];
        int util_vector;
    public:
        MiVectorCaracteres(){
            util_vector = 0;
        }
        int TotalUtilizados(){
            return util_vector;
        }
        char Elemento(int pos){
            return vector_privado[pos];
        }
        void Modifica(int pos, char nuevo){
            vector_privado[pos] = nuevo;
        }
        void Limpia(){
            util_vector = 0;
        }
        void Aniade(char nuevo){
            if(util_vector < MAX){
                vector_privado[util_vector] = nuevo;
                util_vector++;
            }
        }
        void Elimina(int pos){
            if(pos >= 0 && pos < util_vector){
                int tope = util_vector-1;
                for(int i=pos; i<tope; i++)
                    vector_privado[i] = vector_privado[i+1];
                util_vector--;
            }
        }
        void Reemplazar(int pos, int n, MiVectorCaracteres cad){
            int num_caracteres = TotalUtilizados();
            int num_caracteres_cad = cad.TotalUtilizados();
            bool OK = pos >= 0 && pos < util_vector && n > 0;
            bool cabe = (num_caracteres - n + num_caracteres_cad) < MAX;

            if(OK && cabe){
                MiVectorCaracteres tmp;

                for(int i=0; i<pos; i++)
                    tmp.Aniade(Elemento(i));

                for(int i=0; i<num_caracteres_cad; i++)
                    tmp.Aniade(cad.Elemento(i));

                for(int i=pos+n; i<num_caracteres; i++)
                    tmp.Aniade(Elemento(i));

                Limpia();

                int tam = tmp.TotalUtilizados();
                for(int i=0; i<tam; i++)
                    Aniade(tmp.Elemento(i));
            }
        }
        void Mostrar(){
            for(int i=0; i<TotalUtilizados(); i++)
                cout << Elemento(i);
            cout << endl;
        }
};

int main()
{
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

	cout << "Cadena original: " << endl;
	cad.Mostrar();

	MiVectorCaracteres nueva_cad;
	nueva_cad.Aniade('o');
	nueva_cad.Aniade('s');
	nueva_cad.Aniade(' ');
	nueva_cad.Aniade('d');
	nueva_cad.Aniade('e');
	nueva_cad.Aniade(' ');
	nueva_cad.Aniade('l');
	nueva_cad.Aniade('a');

	cout << "Cadena nueva: " << endl;
	nueva_cad.Mostrar();

    MiVectorCaracteres otra_nueva_cad;
	otra_nueva_cad.Aniade('e');
	otra_nueva_cad.Aniade('n');

    cout << "Cadena nueva 2: " << endl;
	otra_nueva_cad.Mostrar();

	cad.Reemplazar(9, 2, nueva_cad);
	cad.Mostrar();

	cad.Reemplazar(12, 5, otra_nueva_cad);
	cad.Mostrar();
}
