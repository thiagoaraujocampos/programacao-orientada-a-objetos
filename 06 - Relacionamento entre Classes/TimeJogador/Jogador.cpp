#include "Jogador.h"

#include <iostream>
using namespace std;

Jogador::Jogador(string nome, int idade, string posicao) :
nome(nome), idade(idade), posicao(posicao) {
    cout << "Criando jogador " << nome << endl;
}

Jogador::~Jogador() {
    cout << "Destruindo jogador " << nome << endl;
}

void Jogador::imprime() {
    cout << nome << ", " << posicao << ", " << idade << " anos" << endl;
}


