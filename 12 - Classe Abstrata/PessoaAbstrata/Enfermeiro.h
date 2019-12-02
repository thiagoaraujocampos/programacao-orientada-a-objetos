#ifndef ENFERMEIRO_H
#define ENFERMEIRO_H

#include "Pessoa.h"

class Enfermeiro : public Pessoa {
public:
    Enfermeiro(int CPF, string nome) : Pessoa(CPF, nome) {
    }
    virtual ~Enfermeiro() {
        
    }
    string getProfissao() {
        return "Enfermeiro";
    }
private:
    
};


#endif /* ENFERMEIRO_H */

