
#pragma once
#include <iostream>



class Punto{
    private:
    double x, y;

    public:
    Punto(){};
    Punto(double xp, double yp) : x(xp), y(yp) {} 
    void setX( double nuevoX);
    double getX();
    void setY(double nuevoY);
    double getY();

};

class Circulo{
    private:
    Punto centro;
    double r;

    public:
    Circulo(){};
    Circulo(double xp, double yp, double radio): centro(xp, yp), r(radio){}
    
    void setXCentro(double nuevoX);
    double getXCentro();
    void setYCentro(double nuevoY);
    double getYCentro();
    void setRadio(double nuevoR);
    double getRadio() const;

};

class Elipse{
    private:
    Punto centro;
    double a, b;

    public:
    Elipse(double xp, double yp, double mayor, double menor): centro(xp, yp), a(mayor), b(menor){}
    
    void setXCentro(double nuevoX);
    double getXCentro();
    void setYCentro(double nuevoY);
    double getYCentro();
    void setSemiMayor(double nuevoA);
    double getSemiMayor() const;
    void setSemiMenor(double nuevoB);
    double getSemiMenor() const;

};

class Rectangulo{
    private:
    Punto verticeIzqInferior;
    double ancho, alto;

    public:
    Rectangulo(double xv, double yv, double anc, double alt): verticeIzqInferior(xv, yv), ancho(anc), alto(alt){}
    
    void setXVertice(double nuevoX);
    double getXVertice();
    void setYVertice(double nuevoY);
    double getYVertice();
    void setAncho(double nuevoAnc);
    double getAncho() const;
    void setAlto(double nuevoAlt);
    double getAlto() const;
};

template <typename T> 
class ProcesadorFigura{
    public:
    double calcularArea(const T& figura);

};

template<>
class ProcesadorFigura<Circulo>{
    public:
    double calcularArea(const Circulo& circ);
};

template<>
class ProcesadorFigura<Elipse>{
    public:
    double calcularArea(const Elipse& el);
};

template<>
class ProcesadorFigura<Rectangulo>{
    public:
    double calcularArea(const Rectangulo& rect);
};