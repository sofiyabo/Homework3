#include "header.hpp"
#include <fstream>

//CONSULTAR TEMA CONST EN DESERIALIZACION

float MedicionBase::getTiempo() const {return *tiempoMedicion;}

//La serializacion va a ser en un archivo binario
void MedicionBase::serializar(std::ofstream& out) const{
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

void MedicionBase::deserializar(std::ifstream& in) {
    tiempoMedicion = std::make_unique<float>(0); //se asigna la memoria antes de guardar la variable, para no usar move
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

void MedicionBase::imprimir() const{
    std::cout<< "Tiempo: "<< getTiempo()<<std::endl;
}

void Presion::serializar(std::ofstream& out)const {
    MedicionBase::serializar(out); //primero la base
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::deserializar(std::ifstream& in) {
    MedicionBase::deserializar(in); 
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
}
void Presion::imprimir() const {
    std::cout<<"Presion estatica: "<< presionEstatica<<"\nPresion dinamica: "<< presionDinamica<<std::endl;
    std::cout<<"Tiempo medicion de presion: "<< getTiempo()<< std::endl;

}

void Posicion::serializar(std::ofstream& out) const{
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
}

void Posicion::deserializar(std::ifstream& in)  {
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
}

void Posicion::imprimir()const{
    std::cout<< "Latitud: "<< latitud << "\nLongitud: "<< longitud<< "\nAltitud: "<<altitud<<std::endl;
    std::cout<<"Tiempo medicion de posicion: "<< getTiempo()<< std::endl;
}

void SaveFlightData::serializar(std::ofstream& out)  {
    posicion.serializar(out);
    presion.serializar(out);

}

void SaveFlightData::deserializar(std::ifstream& in) {
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir(){
    std::cout<<"Data de vuelo:\n";
    posicion.imprimir();
    presion.imprimir();
}