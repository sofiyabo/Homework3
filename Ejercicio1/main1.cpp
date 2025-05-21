#include "header.hpp"
#include <fstream>

int main(){
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3);
    Presion presion(101.3f, 5.8f, 6.1f);

    std::ofstream archivo("info_vuelo.dat", std::ios::binary);
    //agregar si hay un error al abrir

    posicion.serializar(archivo);
    presion.serializar(archivo);
    archivo.close();

    //Creo otra posicion y otra presion para que sean sobreescritas por la deserializacion de SaveFlightData
    //que dentro usa la deserializacion de cada clase
    Posicion posicion_vuelo(0,0,0,0);
    Presion presion_vuelo(0,0,0);
    std::ifstream archivo_leer("info_vuelo.dat", std::ios::binary);
    SaveFlightData vuelo(posicion_vuelo, presion_vuelo);
    vuelo.deserializar(archivo_leer);
    archivo_leer.close();

    vuelo.imprimir();

}