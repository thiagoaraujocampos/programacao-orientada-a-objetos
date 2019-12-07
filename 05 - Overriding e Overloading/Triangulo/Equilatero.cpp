#include "Equilatero.h"

Equilatero::Equilatero(double lado) :
Triangulo(lado) {
}

double Equilatero::getArea() {
    return lados[0] * lados[0] * sqrt(3) / 4;
}


