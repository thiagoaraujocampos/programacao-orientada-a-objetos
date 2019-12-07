#include "Pessoa.h"
#include "Professor.h"
#include "Coordenador.h"

using namespace poo;

int main(int argc, char** argv) {
    
    Pessoa p1("Thiago", 111);
    p1.imprime();
    
    cout << endl;
    
    Professor p2("Sara", 222, 15697.42);
    p2.imprime();
    
    cout << endl;
    
    Coordenador p3("Julia", 333, 16042.23, "Engenharia");
    p3.imprime();
    
    return 0;
}

