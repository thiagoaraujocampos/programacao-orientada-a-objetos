#include "Aluno.h"

Aluno::Aluno() {
}

Aluno::Aluno(int RA, double NP, double NT) :
RA(RA), NP(NP), NT(NT) {
}

Aluno::~Aluno() {
}

int Aluno::getRA() const {
    return RA;
}

double Aluno::media() {
    return NP * 0.8 + NT * 0.2;
}
void Aluno::imprime() {
    cout << "RA: " << RA;
    cout << ", NP: " << NP;
    cout << ", NT: " << NT;
    cout << ", Média: " << media() << endl;
}

bool Aluno::compara(Aluno a1, Aluno a2) {
    return a1.media() < a2.media();
}

