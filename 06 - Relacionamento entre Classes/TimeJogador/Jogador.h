#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

using namespace std;

class Jogador {
public:
    Jogador(string nome, int idade, string posicao);
    virtual ~Jogador();
    void imprime();
private:
    string nome;
    int idade;
    string posicao;
};

#endif /* JOGADOR_H */

