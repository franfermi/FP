#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
  
 char ch, ch2;
 cout << "Introduce un caracter:";
 cin >> ch;
 ch2= ch + ('A'-'a');
 cout << "\n" << ch2<< endl;
 cout << "Introduce un caracter:";
 cin >> ch;
 ch2 = toupper(ch);
 cout << "\n" << ch2 << endl;
}
 
