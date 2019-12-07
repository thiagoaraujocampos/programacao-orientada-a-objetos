#include "Pessoa.h"

namespace poo {
    
    int Pessoa::contador = 0;
    
    Pessoa::Pessoa(string nome, int cpf){
        this->nome = nome;
        this->cpf = cpf;
        this->contador--;
    }
    
    Pessoa::~Pessoa(){
        this->contador++;
    }
    
    void Pessoa::imprime() {
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << cpf << endl;
    }
    
    int Pessoa::getCpf() {
        return cpf;
    }
    
    string Pessoa::getNome() {
        return nome;
    }
}