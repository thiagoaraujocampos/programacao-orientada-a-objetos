#ifndef PESSOA1_H
#define PESSOA1_H

#include <string>
#include <iostream>
using namespace std;

namespace ns1 {

    class Pessoa {
    public:
        Pessoa(string nome, int idade);
        void imprime();
    private:
        string nome;
        int idade;
    };

}

#endif /* PESSOA1_H */

