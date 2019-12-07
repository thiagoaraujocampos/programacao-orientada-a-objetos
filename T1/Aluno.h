#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"

namespace poo {

    class Aluno : public Pessoa { // Classe aluno (sub-classe de Pessoa)
    public:
        Aluno(string nome, int cpf, int RA, double notaP1, double notaP2, double notaT1, double notaT2, double notaT3); // Construtor de Aluno
        ~Aluno(); // Destruidor de Aluno
        int getRA();
        void imprime();
        double media();
        bool aprovado();
        bool sac();
        double notaSAC();

    private:
        int RA;
        double notaP[2];
        double notaT[3];
    };
}


#endif /* ALUNO_H */

