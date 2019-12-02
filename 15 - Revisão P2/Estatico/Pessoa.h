#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

template <class X>

class Pessoa {
public:
    Pessoa(string nome, int idade) : nome(nome), idade(idade), faca1(faca1), faca2(faca2) {
        contador++;
    }
    virtual ~Pessoa() {
        contador--;
    }
    static int getContador() {
        return contador;
    }
    X totalAssasinatos() {
        return faca1 + faca2;
    }
private:
    string nome; 
    int idade;
    X faca1, faca2;
    static int contador;
};

#endif /* PESSOA_H */

