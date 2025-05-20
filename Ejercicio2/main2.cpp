#include "header2.hpp"

int main(){
    Circulo circu;
    circu.setRadio(5);

    ProcesadorFigura<Circulo> p1;

    std::cout<< "Area del circulo = "<< p1.calcularArea(circu)<< std::endl;


    Elipse elipse(0, 0, 5, 3);

    ProcesadorFigura<Elipse> p2;

    std::cout<< "Area del elipse = "<< p2.calcularArea(elipse)<< std::endl;


    Rectangulo rect(0, 0, 3, 2);

    ProcesadorFigura<Rectangulo> p3;
    std::cout<< "Area del rectangulo = "<< p3.calcularArea(rect)<< std::endl;
}