#include "Time.h"
#include <iostream>
using namespace std;

Time::Time(string nome) :
nome(nome) {
    cout << "Criando time " << nome << endl;
    elenco = new Jogador*[22];
    // Notação C (precisa #include<cstdlib>)
    // elenco = (Jogador**) malloc (sizeof (Jogador*) * 22);
}

Time::~Time() {
    cout << "Destruindo time " << nome << endl;
}

void Time::adicionaJogador(int numero, Jogador* jogador) {
    elenco[numero - 1] = jogador;
}

void Time::removeJogador(int numero) {
    elenco[numero - 1] = NULL;
}

void Time::imprime() {
    cout << "Elenco do " << nome << endl;
    for (int i = 0; i < 22; i++) {
        if (elenco[i] != NULL) {
            cout << "(" << (i + 1) << ") ";
            elenco[i]->imprime();
        }
    }
}

