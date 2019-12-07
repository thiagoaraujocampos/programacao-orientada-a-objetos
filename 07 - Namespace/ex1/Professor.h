#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"

namespace poo {
    class Professor : public Pessoa {
    public:
        Professor(string nome, int cpf, float salario);
        virtual float getSalario() const;
        virtual void imprime();
    private:
        float salario;
    };
}

#endif /* PROFESSOR_H */

