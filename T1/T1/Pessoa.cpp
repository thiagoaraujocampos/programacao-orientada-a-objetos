#include "Pessoa.h"

namespace poo {

    Pessoa::Pessoa(string nome, int cpf) : nome(nome), cpf(cpf) {
        cout << "Construtor: (" << nome << ", " << cpf << ")" << endl; // Printa quando constroi
    }

    Pessoa::~Pessoa() {
        
    }

    string Pessoa::getNome() {
        return nome;
    }

    int Pessoa::getCpf() {
        return cpf;
    }

    void Pessoa::imprime() {
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << cpf << endl;
    }

}
