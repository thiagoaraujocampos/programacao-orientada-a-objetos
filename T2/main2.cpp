#include "Museu.h"
#include "ObraDeArte.h"
#include "Pintura.h"
#include "Escultura.h"

using namespace std;
using namespace catalogo;

int main(int argc, char** argv) {
    Museu* m1 = new Museu();
    
    Pintura* p1 = new Pintura("Mona Lisa", "Leonardo da Vinci", "Madeira", 1503, "Óleo");
    m1->adicionaObra(p1);
    
    cout << endl;
    
    Escultura* e1 = new Escultura("David", "Michelangelo", "Mármore", 1501, 1.99);
    m1->adicionaObra(e1);
    
    m1->imprime();
    m1->imprimePorCategoria(ObraDeArte::PINTURA);
    m1->imprimePorCategoria(ObraDeArte::ESCULTURA);
    cout << "Qtde pintura: " << m1->qtdePinturas() << endl;
    cout << "Qtde escultura: " << m1->qtdeEsculturas() << endl;
    cout << "Qtde obras: " << m1->qtdeObras() << endl;
    m1->removeObra("Mona Lisa");
    m1->imprime();
    ObraDeArte* teste = m1->obtemObra("David");
    teste->imprimeFicha();
    
    return 0;
}

