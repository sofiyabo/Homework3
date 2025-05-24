#include "header3.hpp"

int main(){
    Generador<double> doubles;
    doubles.agregarElemento(1.3);
    doubles.agregarElemento(2.1);

    Generador<std::string> texto;
    texto.agregarElemento("Hola");
    texto.agregarElemento("Mundo");

    Generador<std::vector<int>> lista;
    lista.agregarElemento(std::vector<int>{1,2});
    lista.agregarElemento(std::vector<int>{3,4});

    CrearJSON json;
    json.agregarGenerador(doubles);
    json.agregarGenerador(texto);
    json.agregarGenerador(lista);
    json.imprimir();

    return 0;


}