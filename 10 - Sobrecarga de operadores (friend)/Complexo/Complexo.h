#ifndef COMPLEXO_H
#define COMPLEXO_H

#include <iostream>
using namespace std;

class Complexo {
public:
    Complexo(double real, double imaginaria);
    virtual ~Complexo();
    Complexo operator+(const Complexo obj) const;
    Complexo operator-(const Complexo obj) const;
    Complexo operator*(const Complexo obj) const;
    Complexo operator/(const Complexo obj) const;
    friend ostream& operator<<(ostream& os, const Complexo& obj);
private:
    double real;
    double imaginaria;
};

#endif /* COMPLEXO_H */