#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

#include <iostream>
#include "Departamento.h"

using namespace std;

class Universidade {
public:
    Universidade(string nome);
    virtual ~Universidade();
    string getNome() const;
    void setNome(string nome);
    void adicionaDepartamento(string nome, string sigla);
    void removeDepartamento(string sigla);
    void imprime();
private:
    int qtde;
    string nome;
    Departamento** departamentos;
};

#endif /* UNIVERSIDADE_H */