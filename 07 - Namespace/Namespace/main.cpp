#include "Pessoa1.h"
#include "Pessoa2.h"

using namespace ns1;

int main(int argc, char** argv) {

    Pessoa p1("Fulano", 18);
    ns2::Pessoa p2("Sincrano", "Endereco X");
    
    p1.imprime();
    
    cout << endl;
    
    p2.imprime();    
}

