#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
using namespace std;

namespace poo {

    class Pessoa {
    public:
        Pessoa(string nome, int cpf); // Construtor da classe Pessoa
        ~Pessoa(); // Destruidor da classe Pessoa
        string getNome(); 
        int getCpf();
        virtual void imprime();
    private:
        string nome;
        int cpf;
    };
}


#endif /* PESSOA_H */

