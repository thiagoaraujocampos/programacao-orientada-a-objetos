#ifndef TIME_H
#define TIME_H

#include "Jogador.h"

class Time {
public:
    Time(string nome);
    virtual ~Time();
    void adicionaJogador(int numero, Jogador* jogador);
    void removeJogador(int numero);
    void imprime();
private:
    string nome;
    Jogador **elenco;
};

#endif /* TIME_H */

