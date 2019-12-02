#include <iostream>
#include "Pessoa.h"

using namespace std;

int main(int argc, char** argv) {
    
    Pessoa p1("Fulano", 18, 1 , 2);
    Pessoa p2("Sincrano", 21, 0.2, 0.4);
    Pessoa *p3 = new Pessoa("Beltrano", 30, 10, 10);
    
    cout << "Contador " << Pessoa::getContador() << endl;
    
    
    return 0;
}

