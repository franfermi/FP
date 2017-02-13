/*
[Parking]. Recupere la solución del ejercicio 9 de la relación de problemas III (párking).
Re-escríbalo definiendo la clase TarifadorParking para calcular la tarifa.
La clase debe permitir cualquier número de tramos. Para ello, haga lo siguiente:
    • Defina dos vectores como datos miembro de la clase. En uno almacenaremos los
    límites de los tramos y en el otro la correspondiente tarifa.
    • Defina el siguiente método:
    void AniadeTramo(double limite_superior_tramo,
    double tarifa_tramo)
    Este método se llamará tantas veces como tramos tengamos.
    • Defina el método GetTarifa para calcular la tarifa según el número de minutos
    de un estacionamiento.
    • Cree dos objetos de la clase TarifadorParking (uno para cada parking) y
    modifique adecuadamente el programa principal para calcular las tarifas a partir
    de los métodos de los objetos.
Mantenga la definición de la función MinutosEntreInstantes para calcular los
minutos que hay entre dos instantes.
*/
//No he conseguido que me funcione bien.
#include <iostream>
using namespace std;

class TarificadorParking{
    private:
        static const int TAM = 50;
        double vector_tramos[TAM];
        double vector_tarifas[TAM];
        int util_tramos, util_tarifas;
    public:
        TarificadorParking(){
            util_tramos = 0;
            util_tarifas = 0;
        }

        int MinutosEntreInstantes (int hora_inicial, int minuto_inicial, int segundo_inicial,
            int hora_final, int minuto_final, int segundo_final){

            const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;
            int segundos_iniciales, segundos_finales, segundos_diferencia;

           segundos_iniciales = SEGUNDOS_POR_MINUTO * (hora_inicial * MINUTOS_POR_HORA   +
                                                       minuto_inicial) + segundo_inicial;

           segundos_finales   = SEGUNDOS_POR_MINUTO * (hora_final * MINUTOS_POR_HORA   +
                                                       minuto_final) + segundo_final;

           segundos_diferencia = segundos_finales - segundos_iniciales;

           return segundos_diferencia / SEGUNDOS_POR_MINUTO;
        }

        double GetTarifa (int minutos_estacionamiento){
            double tarifa;
            bool fin = false;
            int i;
            for(i=0; i<util_tramos && !fin; i++){
                if(minutos_estacionamiento <= vector_tramos[i]){
                    fin = true;
                }
            }
            tarifa = vector_tarifas[i] * minutos_estacionamiento;

            return tarifa;
        }

        void AniadeTramo(double limite_superior_tramo, double tarifa_tramo){
            vector_tramos[util_tramos] = limite_superior_tramo;
            vector_tarifas[util_tarifas] = tarifa_tramo;
            util_tramos++;
            util_tarifas++;
        }
};


int main(){
    const int FIN = -1;
    double limite, tarifa;
    double tarifa_parking_1, tarifa_parking_2;
    double total_recaudado_parking_1, total_recaudado_parking_2;
    int hora_inicial, minuto_inicial, segundo_inicial;
    int hora_final, minuto_final, segundo_final;
    int minutos_estacionamiento;
    TarificadorParking parking1, parking2;

    cout << "Parking.\n\n";
    cout << "Límites y tarifas parking 1: " << endl;

    cin >> limite >> tarifa;
    if(tarifa != FIN)
        parking1.AniadeTramo(limite, tarifa);

    while(tarifa != FIN){
        cin >> limite >> tarifa;
        if(tarifa != FIN)
            parking1.AniadeTramo(limite, tarifa);
    }

    cout << "\nLímites y tarifas parking 2: " << endl;

    cin >> limite >> tarifa;
    if(tarifa != FIN)
        parking2.AniadeTramo(limite, tarifa);

    while(tarifa != FIN){
        cin >> limite >> tarifa;
        if(tarifa != FIN)
            parking2.AniadeTramo(limite, tarifa);
    }

   total_recaudado_parking_1 = 0;
   total_recaudado_parking_2 = 0;

   cout << "\nTiempo de estacionamiento: " << endl;

   cin >> hora_inicial;

   while (hora_inicial != FIN){
      cin >> minuto_inicial;
      cin >> segundo_inicial;

      cin >> hora_final;
      cin >> minuto_final;
      cin >> segundo_final;

      minutos_estacionamiento = parking1.MinutosEntreInstantes(hora_inicial, minuto_inicial,
                                    segundo_inicial, hora_final, minuto_final, segundo_final);

      tarifa_parking_1 = parking1.GetTarifa(minutos_estacionamiento);

      tarifa_parking_2 = parking2.GetTarifa(minutos_estacionamiento);

      cout << "\nTarifa resultante con cada parking:\n"
           << tarifa_parking_1 << "\n" << tarifa_parking_2 << "\n";

      total_recaudado_parking_1 = total_recaudado_parking_1 + tarifa_parking_1;
      total_recaudado_parking_2 = total_recaudado_parking_2 + tarifa_parking_2;

      cin >> hora_inicial;
   }

   cout << "\nTotal recaudado en cada parking:\n"
        << total_recaudado_parking_1 << "\n"
        << total_recaudado_parking_2 << "\n";
}
