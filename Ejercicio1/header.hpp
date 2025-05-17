//Serializar y deserializar:
// Pasar el estado de un objeto a un archivo y viceversa
//def: proceso de convertir el estado de un objeto en un formato que se oueda almacenar o transmitir (archivo), 
//generalmente como una secuencia de bytes. Permite guardar y recuperar info del objeto

#include <iostream>
#include <memory>

/*
Cosas que faltan:
    Destructores de las clases
    serializar y deserializar declaradas en las derivadas


*/

//Interfaz
class Imediciones{
    public:
        virtual void serializar(std::ofstream& out) = 0;
        virtual void deserializar(std::ofstream& in) = 0; //deberia ser ifstream?

};

//Clase Abstracta
class MedicionBase: public Imediciones{
    protected:
        std::unique_ptr<float> tiempoMedicion; //Se usa unique para que el tiempo pertenezca unicamente a la clase
        //Va a ser parte de las clases Presion y Posicion
    public:
        MedicionBase(float tm) : tiempoMedicion(std::make_unique<float>(tm)) {} //Pongo contructor o no??
        float getTiempo();
        virtual void imprimir();
        void serializar(std::ofstream& out) override;
        void deserializar(std::ofstream& in) override;
};

//Derivadas
class Presion : public MedicionBase{ 
    public:
        float presionEstatica; //p
        float presionDinamica; //q

        Presion(float p, float q, float t) : MedicionBase(t), presionEstatica(p), presionDinamica(q) {}

};

class Posicion : public MedicionBase{
    public:
        float latitud;
        float longitud;
        float altitud;

        Posicion(float lat, float lon, float alt, float t) : MedicionBase(t), latitud(lat), longitud(lon), altitud(alt) {}
};

class SaveFlightData{
    public:
        const Posicion& posicion;
        const Presion& presion;

        SaveFlightData(const Posicion& p, const Presion& q) : posicion(p), presion(q) {}
        void serializar(std::ofstream& out);
        void deserializar(std::ofstream& in);
        void imprimir();
};