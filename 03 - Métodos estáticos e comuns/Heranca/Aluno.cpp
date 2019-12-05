#include "Aluno.h"

Aluno::Aluno(string nome, int idade, int RA) :
Pessoa(nome, idade), RA(RA) {
}

int Aluno::getRA() const {
    return RA;
}

void Aluno::setRA(int RA) {
    this->RA = RA;
}

void Aluno::imprime() {
    Pessoa::imprime();
    cout << "RA: " << RA << endl;
}