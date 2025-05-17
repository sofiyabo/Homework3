/*
2. Escriba el código para las clases que representan:
a. Un punto, con su posición (x, y) y los correspondientes setters y getters.
b. Un círculo, con su posición, radio (r) y los correspondientes setters y getters.
c. Una elipse, con la posición de su centro, el semieje mayor (a), el semieje menor (b) y los correspondientes setters y getters.
d. Un rectángulo, con la posición de su vértice izquierdo inferior, su ancho, su largo y los correspondientes métodos setters y getters.
Cree una clase adicional denominada ProcesadorFigura que utilice especialización de plantilla para calcular el área de las figuras.
Escriba el código en el main que permita ejemplificar como calcular el área de cada una de las figuras mencionadas
*/

#include <iostream>

//float o double??
//Faltan destructores ??
//VER USO DE CONST


class Punto{
    private:
    float x, y;

    public:
    Punto(float xp, float yp) : x(xp), y(yp) {} //constructor
    void setX( float nuevoX);
    float getX();
    void setY(float nuevoY);
    float getY();

};

class Circulo{
    private:
    Punto centro;
    float r;

    public:
    Circulo(float xp, float yp, float radio): centro(xp, yp), r(radio){}
    
    void setXCentro(float nuevoX);
    float getXCentro();
    void setYCentro(float nuevoY);
    float getYCentro();
    void setRadio(float nuevoR);
    float getRadio();

};

class Elipse{
    private:
    Punto centro;
    float a, b;

    public:
    Elipse(float xp, float yp, float mayor, float menor): centro(xp, yp), a(mayor), b(menor){}
    
    void setXCentro(float nuevoX);
    float getXCentro();
    void setYCentro(float nuevoY);
    float getYCentro();
    void setSemiMayor(float nuevoA);
    float getSemiMayor();
    void setSemiMenor(float nuevoB);
    float getSemiMenor();

};

class Rectangulo{
    private:
    Punto verticeIzqInferior;
    float ancho, alto;

    public:
    Rectangulo(float xv, float yv, float anc, float alt): verticeIzqInferior(xv, yv), ancho(anc), alto(alt){}
    
    void setXVertice(float nuevoX);
    float getXVertice();
    void setYVertice(float nuevoY);
    float getYVertice();
    void setAncho(float nuevoAnc);
    float getAncho();
    void setAlto(float nuevoAlt);
    float getAlto();
};