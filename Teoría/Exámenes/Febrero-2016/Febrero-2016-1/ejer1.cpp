#include <iostream>

using namespace std;

class SecuenciaCaracteres{
    private:
        static const int MAX = 50;
        char vector_privado[MAX];
        int util_vector;
    public:
        SecuenciaCaracteres(){
            util_vector = 0;
        }
        int TotalUtilizados(){
            return util_vector;
        }
        int Capacidad(){
            return MAX;
        }
        char Elemento(int pos){
            return vector_privado[pos];
        }
        void Aniade(char nuevo){
            if(util_vector < MAX){
                vector_privado[util_vector] = nuevo;
                util_vector++;
            }
        }
};

class Descodifica{
    private:
        static const int MAX = 20;
        char vector_privado[MAX];
        int util_vector;
    public:
        Descodifica(){
            util_vector=0;
        }
        int TotalUtilizados(){
            return util_vector;
        }
        char Elemento(int pos){
            return vector_privado[pos];
        }
        void Aniade(char nuevo){
            if(util_vector < MAX){
                vector_privado[util_vector] = nuevo;
                util_vector++;
            }
        }
        void Mensaje_Descodificado(SecuenciaCaracteres sec){
        /*
            int pos = 0;
            int pos_init, pos_end;

            while((pos<sec.TotalUtilizados()) && (sec.Elemento(pos)==' '))
                pos++;

            while(pos<sec.TotalUtilizados()){
                pos_init = pos;
                Aniade(sec.Elemento(pos_init));

                while((pos<sec.TotalUtilizados()) && (sec.Elemento(pos)!=' '))
                    pos++;

                if(pos < sec.TotalUtilizados()){
                    pos_end = pos-1;
                    if(pos_end-pos_init>=1)
                        Aniade(sec.Elemento(pos_end));
                     while((pos<sec.TotalUtilizados()) && (sec.Elemento(pos)==' '))
                        pos++;
                }
            }*/
            char anterior=' ';
            int pos, pos_init;

            for(pos=0; pos<sec.TotalUtilizados(); pos++){
                if(sec.Elemento(pos)!=' '){
                    if(anterior == ' '){
                        Aniade(sec.Elemento(pos));
                        pos_init = pos;
                    }
                }
                else{ // == ' '
                    if((anterior != ' ') && (pos-pos_init > 1))
                        Aniade(anterior);
                }
                anterior = sec.Elemento(pos);
            }
        }
        void Mostrar(){
            for(int i=0; i<util_vector; i++)
                cout << Elemento(i);
        }
};

int main()
{
    SecuenciaCaracteres sec;
    Descodifica desco;

    sec.Aniade('H');
    sec.Aniade('i');
    sec.Aniade('d');
    sec.Aniade('r');
    sec.Aniade('o');
    sec.Aniade('g');
    sec.Aniade('e');
    sec.Aniade('n');
    sec.Aniade('o');
    sec.Aniade(' ');
    sec.Aniade('l');
    sec.Aniade('i');
    sec.Aniade('m');
    sec.Aniade('p');
    sec.Aniade('i');
    sec.Aniade('a');
    sec.Aniade(' ');

    desco.Mensaje_Descodificado(sec);
    desco.Mostrar();
}
