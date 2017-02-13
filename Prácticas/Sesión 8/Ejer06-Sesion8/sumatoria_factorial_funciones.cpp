/*
Reescriba la solución del ejercicio 46 que calcula la suma de los primeros T facto-
riales. Para ello, debe leer el valor T usando la función LeeIntRango del ejercicio 4
para obligar a que esté en el intervalo [1,20] .
Debe definir la función SumaFactoriales que calcule la suma pedida. Implemente
dos versiones de esta función:
    -En una primera versión, la función SumaFactoriales debe llamar a la función
    Factorial , para realizar la suma tal y como se indica en el ejercicio 46
    -En una segunda versión, la función SumaFactoriales debe realizar la suma
    de forma directa tal y como se indica en el ejercicio 47. Ponga dentro de un
    comentario la primera versión.
*/
#include <iostream>

using namespace std;

int LeeIntRango(){
    int numero;

    do{
        cout << "Introduce un número entero: ";
        cin >> numero;
    }while(numero < 1 || numero > 20);

    return numero;
}

long long Factorial(int n){
    int i;
    long long fact = 1;

    for(i = 2; i <= n; i++)
        fact = fact * i;

    return fact;
}

//Primera versión
int SumaFactoriales(){
    int T, sumatorio;
    T = LeeIntRango();
    for(int i=1; i<=T; i++){
        sumatorio += Factorial(i);
    }
    return sumatorio;
}

int main()
{
    int sumatorio=0;

    sumatorio = SumaFactoriales();
    cout << "El resultado es: " << sumatorio;
}
