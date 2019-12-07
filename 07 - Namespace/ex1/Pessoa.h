#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
using namespace std;

namespace poo {
    class Pessoa {
    public:
        Pessoa(string nome, int cpf);
        virtual ~Pessoa();
        string getNome();
        int getCpf();
        virtual void imprime();
    private:
        static int contador;
        string nome;
        int cpf;
    };
}

#endif /* PESSOA_H */

