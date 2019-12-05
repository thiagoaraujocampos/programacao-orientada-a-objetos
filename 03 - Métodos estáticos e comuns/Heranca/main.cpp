#include "Pessoa.h"
#include "Aluno.h"

int main(int argc, char** argv) {

    Pessoa p1("Fulano da Silva", 18);
    Pessoa p2("Sincrano Andrade", 19);
    Pessoa p3("Beltrano dos Santos", 18);
    
    p1.imprime();
    
    cout << "Nome: " << p2.getNome() << endl;
    cout << "Idade: " << p2.getIdade() << endl;
    
    p3.imprime();
        
    cout << p1.compare(p2) << endl;
    cout << p1.compare(p3) << endl;
    cout << p2.compare(p1) << endl;

    Aluno a1("Aluno teste", 18, 927450);
    a1.imprime();
    
    cout << p1.compare(a1);
    
    return 0;
}

