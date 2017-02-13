#include <iostream>
#include <string>

using namespace std;

class CuentaCorriente{
private:
 double saldo;
 string iban;
// comprobacion de restriccion evita que se duplique código
// utilizado dentro de la propia clase
 void Set_Saldo(double cantidad){
 if (cantidad >= 0)
     saldo = cantidad;
 }
public:
// constructor sin argumentos
CuentaCorriente()
 :saldo(0), iban("ES37 BNM"){
}
// constructor con 2 argumentos estable TODOS los valores
CuentaCorriente(string identificador_cuenta,double cantidad)
 :iban(identificador_cuenta),saldo(0){
 Set_Saldo(cantidad);
}
// establece iban, no realiza ningun control
void Set_Iban(string identificador_cuenta){
  iban = identificador_cuenta;
}
// devuelve la cadena
string Get_Iban(){
  return iban;
}
// devuelve el valor del saldo un double
double Get_Saldo(){
  return saldo;
}
// incrementa el saldo en la cantidad indicada
// si esta es correcta
void Ingresa(double cantidad){
   if (cantidad > 0)
       Set_Saldo(saldo + cantidad);
}
// decrementa el saldo en la cantidad indicada
// si esta es correcta
void Retira(double cantidad){
   if (cantidad > 0)
       Set_Saldo(saldo - cantidad);
}
// realiza un ingreso del porcentaje a la cuenta
void AplicaInteresPorcentual(int tanto_porciento){
   Ingresa (saldo * tanto_porciento / 100.0);
}
}; // CuentaCorriente
int main(){

 const string MSGINTROIBAN = "Introduce una cadena: ";
 const string MSGINTROQ = "Introduce una cantidad: ";
 const string MSGSALDOACTUAL = "El saldo en la cuenta es: ";

 double ingreso;
 double retirada;
 string identificador_cuenta;

 // 2 objetos se llama a sus respectivos constructores 
 CuentaCorriente unaCuenta;
 CuentaCorriente otraCuenta("ES37000000001", 120);

// test de la clase

 cout << MSGINTROIBAN;
 cin >> identificador_cuenta; // iban = "ES37012345678912345"
 unaCuenta.Set_Iban(identificador_cuenta);
 cout << "Iban una " << unaCuenta.Get_Iban() << endl;
 cout << MSGSALDOACTUAL<<  unaCuenta.Get_Saldo()<< endl;

 cout << "Iban otra " << otraCuenta.Get_Iban() << endl;
 cout << MSGSALDOACTUAL<<  otraCuenta.Get_Saldo()<< endl;

 cout << MSGINTROQ;
 cin >> ingreso; // ingreso = 300
// unaCuenta. Set_Saldo(ingreso);<- error compilacion

 unaCuenta.Ingresa(-ingreso); // saldo = 0 
 cout << MSGSALDOACTUAL<<  unaCuenta.Get_Saldo();

 unaCuenta.Ingresa(ingreso); //  saldo = 0 + 300
 cout << MSGSALDOACTUAL<<  unaCuenta.Get_Saldo()<< endl;

 cout << MSGINTROQ;
 cin >> retirada; // retirada = 500
 unaCuenta.Retira(retirada); // saldo = 300
 cout << MSGSALDOACTUAL<<  unaCuenta.Get_Saldo()<< endl;
 
 unaCuenta.Retira(ingreso); // saldo = 300
  cout << MSGSALDOACTUAL<<  unaCuenta.Get_Saldo()<< endl;

}
 
