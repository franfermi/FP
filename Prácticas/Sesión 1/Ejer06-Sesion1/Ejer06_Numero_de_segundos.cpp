#include <iostream>

using namespace std;

int main()
{
    const int CONVERSION = 60;
    float horasI, horasF;
    float minutosI, minutosF;
    float segundosI, segundosF;
    float horasT, minutosT, segundosT;
    float total;

    cout << "Introduce las horas iniciales: ";
    cin >> horasI;

    cout << "Introduce los minutos iniciales: ";
    cin >> minutosI;

    cout << "Introduce los segundos iniciales: ";
    cin >> segundosI;

    cout << "Introduce las horas finales: ";
    cin >> horasF;

    cout << "Introduce los minutos finales: ";
    cin >> minutosF;

    cout << "Introduce los segundos finales: ";
    cin >> segundosF;

    horasT = horasF - horasI;
    minutosT = minutosF - minutosI;
    segundosT = segundosF - segundosI;

    total = ((horasT*CONVERSION)*CONVERSION) + (minutosT*CONVERSION) + segundosT;

    cout << "\nLos segundos entre los dos instantes son: " << total << "s";

}
