/*
if constexpr es para decidir un comportamiento en tiempo de compilacion
Para lograr esto, cree dos clases que colaboren para construir el JSON en partes separadas:
1. Clase 1: esta clase se encargará de generar los vectores de double y std::string, así como la matriz de enteros. 
Para ello, se debe utilizar un método para agregar los valores y las palabras a la instancia de la clase para luego procesarlas según el tipo de dato que se pasó.
Deberá utilizar un template para poder trabajar con los distintos tipos de datos.
En función del tipo, y mediante el uso obligatorio de “if constexpr”, se deberán aplicar distintos métodos para procesar los datos adecuadamente.

2. Clase 2: Esta clase se encargará de asociar etiquetas (por ejemplo, “palabras”) con su vector/matriz correspondiente (por ejemplo, [“Hola”, “Mundo”]).
Además, contendrá el método que finalmente construya el JSON completo y lo imprima por pantalla.

*/
#include "header3.hpp"
//template <typename T>
/*
void Generador<T>::agregarElemento(const T& elemento){
        vector.push_back(elemento);
}



template<typename T>
std::string Generador<T>::getTipo() const {
    if constexpr(std::is_same_v<T, double>){
        return "vec_doubles";
    }
    else if constexpr(std::is_same_v<T, std::string>){
        return "palabras";
    }
    else if constexpr(std::is_same_v<T, std::vector<int>>){
        return "matriz_enteros";
    }
    else {
        std::cout<< "Tipo no valido."<< std::endl; //revisar manejo de error
    }

}

template <typename T>
std::string Generador<T>::getVectorString() const{
    std::string texto = "[";
    //uso if constexpr para convertir cada tipo en string

    if constexpr (std::is_same_v<T, double>){
        for (size_t i = 0; i< vector.size(); i++){
            texto += std::to_string(vector[i]);
            if(i< vector.size() - 1){
                texto+= ",";
            }
        }
    }
    else if constexpr(std::is_same_v<T, std::string>){
        for(size_t i = 0; i < vector.size(); i++){
            texto += vector[i];
            if(i< vector.size() - 1){
                texto+= ",";
            }
        }
    }
    else if constexpr(std::is_same_v<T, std::vector<int>>){
        for (size_t i =0; i<vector.size(); i++){
            texto += "[";
            for(size_t j; j<vector[i].size(); j++){
                texto+= std::to_string(vector[i][j]);
                if(j < vector[i].size() -1){
                    texto+= ",";
                }
            }
            texto+= "]";
            if (i<vector.size() - 1){
                texto += ",";
            }
        }
    }
    texto +="]";
    return texto;
}

*/


/*
template <typename T>
void CrearJSON::agregarGenerador(const Generador<T>& elemento){
    if(!cadena_json.empty()){
        cadena_json+= ",\n";
    }

    cadena_json+= elemento.getTipo() +" : " + elemento.getVectorString();
}
*/
void CrearJSON::imprimir() const{
    std::cout << "{\n" << cadena_json << "\n}"<< std::endl;
}