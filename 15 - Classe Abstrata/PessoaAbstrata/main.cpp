#include "Pessoa.h"
#include "Medico.h"
#include "Enfermeiro.h"
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
    Medico m(1234, "Jesus");
    m.imprime();
    Enfermeiro e(4321, "Maria");
    e.imprime();
    return 0;
}