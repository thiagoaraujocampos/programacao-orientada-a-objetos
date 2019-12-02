#include <iostream>

#include "Calculadora.h"
using namespace std;

template <class X> void troca(X& a, X& b) {
    X aux = a;
    a = b;
    b = aux;
}

int main(int argc, char** argv) {

    int i = 10, j = 20;
    double x = 10.1, y = 23.3;
    char a = 'A', b = 'Z';

    cout << "Original: " << i << " " << j << endl;
    cout << "Original: " << x << " " << y << endl;
    cout << "Original: " << a << " " << b << endl;
    cout << endl;
    
    troca(i, j); // Troca inteiros
    troca(x, y); // Troca números double
    troca(a, b); // Troca caracteres
    
    cout << "Depois da Troca: " << i << " " << j << endl;
    cout << "Depois da Troca: " << x << " " << y << endl;
    cout << "Depois da Troca: " << a << " " << b << endl;
    cout << endl;
    
    Calculadora<int> cInt(10, 3);
    cInt.imprime();
    
    cout << endl;
    
    Calculadora<float> cFloat(10, 3);
    cFloat.imprime();
    
    return 0;
}