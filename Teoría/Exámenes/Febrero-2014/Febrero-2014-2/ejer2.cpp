#include <iostream>
#include <vector>

using namespace std;

struct Parejas{
    string pareja1;
    string pareja2;
};

vector <Parejas> Emparejamientos(vector <string> equipos){
    vector <Parejas> tmp;
    string parej1, parej2;
    int num_elementos = equipos.size();

    for(int i=0; i<num_elementos-1; i++){
        parej1 = equipos.at(i);
        for(int j=i+1; j<num_elementos; j++){
            parej2 = equipos.at(j);
            Parejas n_pareja;
            n_pareja.pareja1 = parej1;
            n_pareja.pareja2 = parej2;
            tmp.push_back(n_pareja);
        }
    }
    return tmp;
}

int main()
{
    vector <string> equipos;
    vector <Parejas> parejas;

    equipos.push_back("Albolote");
    equipos.push_back("Motril");
    equipos.push_back("Baza");
    equipos.push_back("La zubia");

    int num_equipos = equipos.size();

    cout << "\nLos equipos son: " << endl;
    for(int i=0; i<num_equipos; i++)
        cout << equipos.at(i) << endl;

    cout << "\nLos emparejamientos son: " << endl;
    parejas = Emparejamientos(equipos);

    for(int i=0; i<parejas.size(); i++){
        cout << "{" << parejas.at(i).pareja1 << ", " <<
                parejas.at(i).pareja2 << "} ";
    }
    cout << endl;
}
