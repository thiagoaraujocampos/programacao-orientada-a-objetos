#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <cmath>
#include <iostream>
using namespace std;

class Triangulo {
public:
    Triangulo(double lado);
    Triangulo(double lado1, double lado2, double lado3);
    double getPerimetro();
    virtual double getArea();
    void imprime();
    int compare(Triangulo& t);
protected:
    double lados[3];
};

#endif /* TRIANGULO_H */

