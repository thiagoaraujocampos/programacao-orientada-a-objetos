#include "Departamento.h"

#include <iostream>
using namespace std;

Departamento::Departamento(string nome, string sigla) :
nome(nome), sigla(sigla) {
    cout << "[Construindo departamento " << sigla << "]" << endl;
}

Departamento::~Departamento() {
    cout << "[Destruindo departamento " << sigla << "]" << endl;
}

string Departamento::getNome() const {
    return nome;
}

void Departamento::setNome(string nome) {
    this->nome = nome;
}

string Departamento::getSigla() const {
    return sigla;
}

void Departamento::setSigla(string sigla) {
    this->sigla = sigla;
}

void Departamento::imprime() {
    cout << "Departamento " << nome << " de sigla " << sigla << endl;
}




