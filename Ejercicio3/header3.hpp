
#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>




template <typename T>
class Generador{  
    private:
    std::vector<T> vector; 

    public:
    Generador()= default;
    void agregarElemento(const T& elemento){
        vector.push_back(elemento);
    } 
    std::string getVectorString() const{
        std::string texto = "[";
        //uso if constexpr para convertir cada tipo en string
    
        if constexpr (std::is_same_v<T, double>){
            for (size_t i = 0; i< vector.size(); i++){
                std::stringstream redondeo;
                redondeo << std::fixed << std::setprecision(1)<< vector[i];
        
                texto += redondeo.str();
                if(i< vector.size() - 1){
                    texto+= ", ";
                }
            }
        }
        else if constexpr(std::is_same_v<T, std::string>){
            for(size_t i = 0; i < vector.size(); i++){
                texto += vector[i];
                if(i< vector.size() - 1){
                    texto+= ", ";
                }
            }
        }
        else if constexpr(std::is_same_v<T, std::vector<int>>){
            for (size_t i =0; i<vector.size(); i++){
                texto += "\n[";
                for(size_t j=0; j<vector[i].size(); j++){
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
    std::string getTipo()const{
        if constexpr(std::is_same_v<T, double>){
            return "vec_doubles";
        }
        else if constexpr(std::is_same_v<T, std::string>){
            return "palabras";
        }
        else if constexpr(std::is_same_v<T, std::vector<int>>){
            return "listas";
        }
        else {
            std::cout<< "Tipo no valido."<< std::endl; 
        }
    
    }
};

class CrearJSON{
    private:
    std::string cadena_json;

    public:
    template <typename T>
    void agregarGenerador(const Generador<T>& elemento){
        if(!cadena_json.empty()){
            cadena_json+= ",\n";
        }
    
        cadena_json+= "\""  + elemento.getTipo() + "\" : " + elemento.getVectorString();
    }
    void imprimir() const;
};
