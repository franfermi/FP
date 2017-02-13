/*
Indique si se produce un problema de precisión o de desbordamiento en los siguientes
ejemplos y diga cuál sería el resultado final de las operaciones.
*/
#include <iostream>

using namespace std;

int main()
{
/*
    //a)
    int chico, chico1, chico2;
    chico1 = 1234567;
    chico2 = 1234567;
    chico = chico1 * chico2;
    //Se produce desbordamiento, el resultado real es: 1,524155677×10¹²

    //b)
    unsigned long grande;
    int chico1, chico2;
    chico1 = 1234567;
    chico2 = 1234567;
    grande = chico1 * chico2;
    //Se produce desbordamiento, si usamos long int si tendría
    //espacio para almacenar el resultado.

    //c)
    double real, real1, real2;
    real1 = 123.1;
    real2 = 124.2;
    real = real1 * real2;
    //Se produce falta de precisión, en este caso los dos últimos decimales.

    //d)
    double real, real1, real2;
    real1 = 123456789.1;
    real2 = 123456789.2;
    real = real1 * real2;
    cout.precision(17);
    //Cambiando la precisión a 17 decimales, comprobamos que se
    //produce falta de precisión en los decimales.

    //e)
    double real, otro_real;
    real = 2e34;
    otro_real = real + 1;
    otro_real = otro_real - real;
    //El resultado es 0, es correcto.

    //f)
    double real, otro_real;
    real = 1e+300;
    otro_real = 1e+200;
    otro_real = otro_real * real;
    //Se produce desbordamiento a infinito.

    //g)
    float chico;
    double grande;
    grande = 2e+150;
    chico = grande;
    //Se produce desbordamiento a infinito al almacenar
    //el contenido de grande a chico siendo este último un float.
*/
}
