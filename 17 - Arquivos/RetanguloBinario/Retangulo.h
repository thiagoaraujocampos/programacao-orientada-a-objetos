#ifndef RETANGULO_H
#define RETANGULO_H

class Retangulo {
private:
    double ladoa;
    double ladob;
public:
    void setDim(double a, double b);
    void imprimir();
    double area();
    static bool compara(Retangulo r1, Retangulo r2);
};

#endif /* RETANGULO_H */

