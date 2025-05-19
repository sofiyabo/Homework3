#include "header2.hpp"
#include <cmath>

void Punto::setX(double nuevoX){
    x = nuevoX;
}

double Punto::getX(){
    return x;
}

void Punto::setY(double nuevoY){
    y = nuevoY;
}

double Punto::getY(){
    return y;
}

void Circulo::setXCentro(double nuevoX){
    centro.setX(nuevoX);
}

double Circulo::getXCentro(){
    return centro.getX();
}

void Circulo::setYCentro(double nuevoY){
    centro.setY(nuevoY);
}

double Circulo::getYCentro(){
    return centro.getY();
}

void Circulo::setRadio(double nuevoR){
    r = nuevoR;
}

double Circulo::getRadio() const{
    return r;
}

void Elipse::setXCentro(double nuevoX){
    centro.setX(nuevoX);
}

double Elipse::getXCentro(){
    return centro.getX();
}

void Elipse::setYCentro(double nuevoY){
    centro.setY(nuevoY);
}

double Elipse::getYCentro(){
    return centro.getY();
}

void Elipse::setSemiMayor(double nuevoA){
    a = nuevoA;
}

double Elipse::getSemiMayor() const{
    return a;
}

void Elipse::setSemiMenor(double nuevoB){
    b = nuevoB;
}

double Elipse::getSemiMenor()const{
    return b;
}

void Rectangulo::setXVertice(double nuevoX){
    verticeIzqInferior.setX(nuevoX);
}

double Rectangulo::getXVertice(){
    return verticeIzqInferior.getX();
}

void Rectangulo::setYVertice(double nuevoY){
    verticeIzqInferior.setY(nuevoY);
}

double Rectangulo::getYVertice(){
    return verticeIzqInferior.getY();
}

void Rectangulo::setAncho(double nuevoAnc){
    ancho = nuevoAnc;
}

double Rectangulo::getAncho() const{
    return ancho;
}

void Rectangulo::setAlto(double nuevoAlt){
    alto = nuevoAlt;
}

double Rectangulo::getAlto()const {
    return alto;
}

//ProcesadorFigura

double ProcesadorFigura<Circulo>::calcularArea(const Circulo& circ){
    return circ.getRadio()*circ.getRadio()*M_PI;
}

double ProcesadorFigura<Elipse>::calcularArea(const Elipse& el){
    return M_PI * el.getSemiMayor() * el.getSemiMenor();
}

double ProcesadorFigura<Rectangulo>::calcularArea(const Rectangulo& rect){
    return rect.getAlto() * rect.getAncho();
}