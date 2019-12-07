#ifndef PESSOA2_H
#define PESSOA2_H

#include <string>
#include <iostream>
using namespace std;

namespace ns2 {

    class Pessoa {
    public:
        Pessoa(string nome, string endereco);
        void imprime();
    private:
        string nome;
        string endereco;
    };
}

#endif /* PESSOA2_H */
