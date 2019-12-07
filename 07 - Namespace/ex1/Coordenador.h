#ifndef COORDENADOR_H
#define COORDENADOR_H

#include "Professor.h"

namespace poo {
    class Coordenador : public Professor {
    public:
        Coordenador(string nome, int cpf, float salario, string curso);
        virtual float getSalario() const;
        virtual void imprime();
    private:
        string curso;
    };
}

#endif /* COORDENADOR_H */

