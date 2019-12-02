#ifndef FRACAO_H
#define FRACAO_H

#include <iostream>
using namespace std;

class Fracao {
public:
    Fracao (int a, int b) :     a(a), b(b) {
    }
    
    Fracao operator+ (const Fracao& right) const {
        int a = this->a;
        int b = this->b;
        int c = right.a;
        int d = right.b;
        return Fracao(a * d + b * c, b * d);
    }
    
    Fracao operator- (const Fracao& right) const {
        int a = this->a;
        int b = this->b;
        int c = right.a;
        int d = right.b;
        return Fracao(a * d - b * c, b * d);
    }
    
    Fracao operator* (const Fracao& right) const {
        int a = this->a;
        int b = this->b;
        int c = right.a;
        int d = right.b;
        return Fracao(a * c, b * d);
    }
    
    Fracao operator/ (const Fracao& right) const {
        int a = this->a;
        int b = this->b;
        int c = right.a;
        int d = right.b;
        return Fracao(a * d, b * c);
    }
    
    friend ostream& operator<< (ostream& os, const Fracao& obj) {
        os << obj.a << "/" << obj.b;
        return os;
    }
    
private:
    int a, b;
};

#endif /* FRACAO_H */

