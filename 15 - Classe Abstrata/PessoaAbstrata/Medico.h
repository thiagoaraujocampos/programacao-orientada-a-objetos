#ifndef MEDICO_H
#define MEDICO_H

#include "Pessoa.h"

class Medico : public Pessoa {
public:
    Medico(int CPF, string nome) : Pessoa(CPF, nome) {
    }
    virtual ~Medico() {
        
    }
    string getProfissao() {
        return "Medico";
    }
private:

};

#endif /* MEDICO_H */

