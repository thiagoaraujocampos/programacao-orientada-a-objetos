#include <iostream>
#include "ContaCorrente.h"

using namespace std;

int main() {

    ContaCorrente c1(1000, 1200.50);
    ContaCorrente c2(2000);
    
    cout << endl << "Antes da Transferência" << endl << endl;
    
    c1.imprime();
    c2.imprime();
    
    c1.transferencia(c2, 500);
    
    cout << endl << "Depois da Transferência" << endl << endl;
    
    c1.imprime();
    c2.imprime();
    
    cout << endl;
    
    return 0;
}

