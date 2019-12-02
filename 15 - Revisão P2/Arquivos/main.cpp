#include <cstdlib>

#include "Copia.h"

using namespace std;

int main(int argc, char** argv) {
    
    Copia teste;
    teste.substituiLinha("txt.txt","out.txt",'a','*');
    
    return 0;
}

