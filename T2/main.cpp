#include <iostream>
#include "ObraDeArte.h"
#include "Pintura.h"
#include "Escultura.h"
#include "Museu.h"

using namespace std;
using namespace catalogo;

void imprime(Museu& museu) {
    cout << "================== IMPRIMINDO AS OBRAS ================== " << endl;

    cout << "Qtde Obras: " << museu.qtdeObras() << endl;
    cout << endl;
    museu.imprime();

    cout << "================== IMPRIMINDO AS PINTURAS =============== " << endl;

    cout << "Qtde Pinturas: " << museu.qtdePinturas() << endl;
    cout << endl;
    museu.imprimePorCategoria(ObraDeArte::PINTURA);

    cout << "================== IMPRIMINDO AS ESCULTURAS ============= " << endl;

    cout << "Qtde Esculturas: " << museu.qtdeEsculturas() << endl;
    cout << endl;
    museu.imprimePorCategoria(ObraDeArte::ESCULTURA);
}

int main(int argc, char** argv) {

    ObraDeArte* o1 = new Pintura("Mona Lisa", "Leonardo da Vinci", "Madeira", 1503, "Óleo");
    ObraDeArte* o2 = new Escultura("David", "Michelangelo", "Mármore", 1501, 1.99);
    Museu museu("Louvre");

    cout << boolalpha;

    cout << "================== TESTANDO ADICIONA OBRA =============== " << endl;
    bool res = museu.adicionaObra(o1);
    cout << "Adiciona Obra (" << o1->getTitulo() << ") => " << res << " deveria ser " << true << endl;

    res = museu.adicionaObra(o2);
    cout << "Adiciona Obra (" << o2->getTitulo() << ") => " << res << " deveria ser " << true << endl;

    res = museu.adicionaObra(o1);
    cout << "Adiciona Obra (" << o1->getTitulo() << ") => " << res << " deveria ser " << false << endl;

    res = museu.adicionaObra(o2);
    cout << "Adiciona Obra (" << o2->getTitulo() << ") => " << res << " deveria ser " << false << endl;

    imprime(museu);

    cout << "================== TESTANDO REMOVE OBRA =============== " << endl;
    res = museu.removeObra("David");
    cout << "Remove Obra (David) => " << res << " deveria ser " << true << endl;
    res = museu.removeObra("David");
    cout << "Remove Obra (David) => " << res << " deveria ser " << false << endl;

    imprime(museu);

    cout << endl;

    cout << "================== TESTANDO OBTEM OBRA =============== " << endl;
    ObraDeArte* o3 = museu.obtemObra("Mona Lisa");
    cout << "Deveria imprimir a ficha da Mona Lisa" << endl << endl;
    if (o3 != NULL) {
        o3->imprimeFicha();
    }

    cout << "================== TESTANDO OBTEM OBRA =============== " << endl;
    
    ObraDeArte* o4 = museu.obtemObra("David");
    cout << "Não deveria imprimir nada" << endl;
    cout << "(obra não se encontra no acervo)" << endl;
    if (o4 != NULL) {
        o4->imprimeFicha();
    }
    return 0;
}