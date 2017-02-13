#include <iostream>

using namespace std;

class Matriz{

 private:
  static const int FIL = 30 , COL = 20;
  char matriz[FIL][COL];
  int util_fil , util_col;

 public:

  Matriz(int col){

   util_fil = 0;
   util_col = col;

  }

  void Mostrar () {

   for (int i = 0 ; i < util_fil ; i++){

    for (int j = 0 ; j < util_col ; j++)
     cout << matriz[i][j] << " ";
    cout << endl;

   }

  }

  void Histograma(char vocales[] , int frecuencias[]){

   int max_frec = 0;

   for(int i = 0 ; i <  5; i++){

    if (frecuencias[i] > max_frec)
     max_frec = frecuencias[i];

   }

   util_fil = max_frec;

   for (int i = 0 ; i < util_fil ; i++){

    for (int j = 0 ; j < util_col ; j++)
     matriz[i][j] = ' ';

   }

   for (int i = max_frec ; i > 0 ; i--){

    for (int j = 0 ; j < util_col ; j++){

     if(frecuencias[j] == i){

      matriz[max_frec - i][j] = '*';
      frecuencias[j]--;

     }

    }

   }

  }


};

int main () {

 char vocales[5] = {'a' , 'e' , 'i' , 'o' , 'u'};
 int frecuencias[5] = {6 , 7 , 3 , 4 , 2};
 Matriz tabla(5);
 tabla.Histograma(vocales , frecuencias);
 tabla.Mostrar();
}
