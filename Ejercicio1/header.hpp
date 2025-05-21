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
        virtual void serializar(std::ofstream& out) const = 0;
        virtual void deserializar(std::ifstream& in)  = 0; //deberia ser ifstream?

};

//Clase Abstracta
//Para serializar y deserializar primero se hace la clase base y dsp las derivadas 
class MedicionBase: public Imediciones{
    protected:
        std::unique_ptr<float> tiempoMedicion; 
        //Va a ser parte de las clases Presion y Posicion
    public:
        MedicionBase(float tm) : tiempoMedicion(std::make_unique<float>(tm)) {} 
        virtual ~MedicionBase() = default;
        float getTiempo() const;
        virtual void imprimir()const;
        void serializar(std::ofstream& out) const override;
        void deserializar(std::ifstream& in) override;
};

//Derivadas
class Presion : public MedicionBase{ 
    public:
        float presionEstatica; //p
        float presionDinamica; //q

        Presion(float p, float q, float t) : MedicionBase(t), presionEstatica(p), presionDinamica(q) {}
        void serializar(std::ofstream& out) const override;
        void deserializar(std::ifstream& in)  override;
        void imprimir() const override;
};

class Posicion : public MedicionBase{
    public:
        float latitud;
        float longitud;
        float altitud;

        Posicion(float lat, float lon, float alt, float t) : MedicionBase(t), latitud(lat), longitud(lon), altitud(alt) {}
        void serializar(std::ofstream& out) const override;
        void deserializar(std::ifstream& in) override;
        void imprimir()const override;
};

class SaveFlightData{
    public:
        Posicion& posicion;
        Presion& presion;

        SaveFlightData(Posicion& p, Presion& q) : posicion(p), presion(q) {}
        void serializar(std::ofstream& out);
        void deserializar(std::ifstream& in);
        void imprimir();
};