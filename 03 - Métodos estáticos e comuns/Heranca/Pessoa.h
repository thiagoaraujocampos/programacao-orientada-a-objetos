#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
using namespace std;

class Pessoa {
public:
    Pessoa(string nome, int idade);
    int getIdade();
    void setIdade(int idade);
    string getNome();
    void setNome(string nome);
    virtual void imprime();
    int compare(Pessoa p);
private:
    string nome;
    int idade;
};

#endif /* PESSOA_H */

