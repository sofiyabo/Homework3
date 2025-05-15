//Serializar y deserializar:
// Pasar el estado de un objeto a un archivo y viceversa
//def: proceso de convertir el estado de un objeto en un formato que se oueda almacenar o transmitir (archivo), 
//generalmente como una secuencia de bytes. Permite guardar y recuperar info del objeto

#include <iostream>
#include <memory>

//Interfaz
class Imediciones{
    public:
        virtual void serializar(std::ofstream& out) = 0;
        virtual void deserializar(std::ofstream& in) = 0; //deberia ser ifstream?


};

//Clase Abstracta
class MedicionBase{
    protected:
        std::unique_ptr<float> tiempoMedicion; //Se usa unique para que el tiempo pertenezca unicamente a la clase
        //Va a ser parte de las clases Presion y Posicion
    public:
        MedicionBase(float tm) : tiempoMedicion(std::make_unique<float>(tm)) {}
        float getTiempo();
        virtual void imprimir();
};

//Derivadas
class Presion : public MedicionBase{ //Preguntar por que estan los comentarios p y q
    public:
        float presionEstatica;
        float presionDinamica;

};