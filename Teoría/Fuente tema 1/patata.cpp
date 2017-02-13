#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
  
   int entrada;
   char caracter = 'A';
   entrada = caracter;
   cout << " A es entrada " << entrada << endl;
   caracter = '3';
   entrada = caracter - '0';
   cout << " el número es entrada " << entrada << endl;
   entrada = atoi("3");
}
 
