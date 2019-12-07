#ifndef EQUILATERO_H
#define EQUILATERO_H

#include "Triangulo.h"

class Equilatero : public Triangulo {
public:
    Equilatero(double lado);
    double getArea();
private:
};

#endif /* EQUILATERO_H */