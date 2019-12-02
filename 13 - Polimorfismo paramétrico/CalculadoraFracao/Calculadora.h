#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>
using namespace std;

template <class T>
class Calculadora {
public:

    Calculadora(T num1, T num2) :
    num1(num1), num2(num2) {
    }

    ~Calculadora() {
    }

    T soma() {
        return num1 + num2;
    }

    T subtracao() {
        return num1 - num2;
    }

    T multiplicacao() {
        return num1 * num2;
    }

    T divisao() {
        return num1 / num2;
    }

    void imprime() {
        cout << "Numeros: " << num1 << " " << num2 << endl;
        cout << "Soma: " << soma() << endl;
        cout << "Subtracao: " << subtracao() << endl;
        cout << "Multiplicacao: " << multiplicacao() << endl;
        cout << "Divisao: " << divisao() << endl;
    }
private:
    T num1, num2;
};

#endif /* CALCULADORA_H */