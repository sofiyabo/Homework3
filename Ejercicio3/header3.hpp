/*
Para lograr esto, cree dos clases que colaboren para construir el JSON en partes separadas:
1. Clase 1: esta clase se encargará de generar los vectores de double y std::string, así como la matriz de enteros. Para ello, se debe utilizar un método para agregar
los valores y las palabras a la instancia de la clase para luego procesarlas según el tipo de dato que se pasó.
Deberá utilizar un template para poder trabajar con los distintos tipos de datos.
En función del tipo, y mediante el uso obligatorio de “if constexpr”, se deberán aplicar distintos métodos para procesar los datos adecuadamente.
2. Clase 2: Esta clase se encargará de asociar etiquetas (por ejemplo, “palabras”) con su vector/matriz correspondiente (por ejemplo, [“Hola”, “Mundo”]).
Además, contendrá el método que finalmente construya el JSON completo y lo imprima por pantalla.
*/

#include <iostream>
#include <vector>
#include <map> //revisar uso de esto
#include <memory>




template <typename T>
class Generador{  
    private:
    std::vector<T> vector; // el generador siempre va a generar un vector, solo que varia T

    public:
    Generador()= default;
    void agregarElemento(const T& elemento); //tengo que hacer que chequee que tipo tiene ya el vector, asi no deja que pongan otra cosa
    std::string getVectorString();
    std::string getTipo();
};

class CrearJSON{
    private:
    //hago tres vectores diferentes e imprimo por orden ?? 
    std::vector<Generador<double>> doubles;
    std::vector<Generador<std::string>> texto;
    std::vector<Generador<std::vector<int>>> listas;

    public:
    template <typename T>
    void agregarGenerador(const Generador<T>& elemento);
    void imprimir() const;
};
