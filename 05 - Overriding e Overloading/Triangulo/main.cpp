#include "Triangulo.h"
#include "Equilatero.h"

int main(int argc, char** argv) {

    Triangulo t1(3,4,5);
    Equilatero t2(3);
    
    t1.imprime();
    
    cout << endl;
    
    t2.imprime();
    
    cout << t1.compare(t2) << endl;
    cout << t1.compare(t1) << endl;
    cout << t2.compare(t1) << endl;
    
    return 0;
}

