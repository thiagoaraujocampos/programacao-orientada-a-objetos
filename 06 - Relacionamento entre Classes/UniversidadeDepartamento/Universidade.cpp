#include "Universidade.h"

#include <iostream>
using namespace std;

Universidade::Universidade(string nome) :
nome(nome) {
    cout << "[Construindo " << nome << "]" << endl;
    qtde = 0;
    departamentos = new Departamento*[15];
}

Universidade::~Universidade() {
    for (int i = 0; i < qtde; i++) {
        delete departamentos[i];
    }
    cout << "[Destruindo " << nome << "]" << endl;
}

string Universidade::getNome() const {
    return nome;
}

void Universidade::setNome(string nome) {
    this->nome = nome;
}

void Universidade::adicionaDepartamento(string nome, string sigla) {
    departamentos[qtde++] = new Departamento(nome, sigla);
}

void Universidade::removeDepartamento(string sigla) {
    bool found = false;
    int i = 0;
    
    while (i < qtde && !found) {
        if (departamentos[i]->getSigla().compare(sigla) == 0) {
            found = true;
        } else {
            i++;
        }
    }
    
    delete departamentos[i];
    
    while (i < qtde) {
        departamentos[i] = departamentos[i+1];
        i++;
    }
    
    qtde = qtde - 1;
}


void Universidade::imprime() {
    cout << "Departamentos da " << nome << endl;
    for (int i = 0; i < qtde; i++) {
        departamentos[i]->imprime();
    }
}