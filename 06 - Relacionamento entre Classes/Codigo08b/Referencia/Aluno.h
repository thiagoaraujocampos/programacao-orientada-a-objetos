#ifndef ALUNO_H
#define ALUNO_H

#include "Endereco.h"
#include <string>

using namespace std;

class Aluno {
    public:
        Aluno(string nome, int RA);
        Aluno(string nome, int RA, Endereco& endereco);
        virtual ~Aluno();
        string getNome();
        void setNome(string val);
        int getRA();
        void setRA(int val);
        Endereco& getEndereco();
        void setEndereco(Endereco& val);
        void imprime();
    private:
        string nome;
        int RA;
        Endereco& endereco;
};

#endif // ALUNO_H