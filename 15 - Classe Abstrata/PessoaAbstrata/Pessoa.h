#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
using namespace std;

class Pessoa {
public:
    Pessoa(int CPF, string nome) : CPF(CPF), nome(nome) {
    }
    virtual ~Pessoa() {
        
    }
    virtual string getProfissao() = 0;
    virtual void imprime() {
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << CPF << endl;
        cout << "Profissão: " << getProfissao() << endl;
    }
private:
    int CPF;
    string nome;
};

#endif /* PESSOA_H */

