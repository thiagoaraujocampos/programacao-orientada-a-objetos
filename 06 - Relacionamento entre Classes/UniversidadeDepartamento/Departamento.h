#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>
using namespace std;

class Departamento {
public:
    Departamento(string nome, string sigla);
    virtual ~Departamento();
    string getNome() const;
    void setNome(string nome);
    string getSigla() const;
    void setSigla(string sigla);
    void imprime();
private:
    string nome;
    string sigla;
};

#endif /* DEPARTAMENTO_H */

