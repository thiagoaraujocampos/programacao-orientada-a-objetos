#include <math.h>
#include "Ponto2D.h"

Ponto2D::Ponto2D(float a, float b) {
    x = a;
    y = b;
}

Ponto2D::~Ponto2D() {

}

float Ponto2D::distancia(Ponto2D p) {
    float dx = x - p.x;
    float dy = y - p.y;
    return sqrt(dx * dx + dy * dy);
}



