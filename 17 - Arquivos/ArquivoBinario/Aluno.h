#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
using namespace std;

class Aluno {
public:
    Aluno();
    Aluno(int RA, double NP, double NT);
    virtual ~Aluno();
    void imprime();
    int getRA() const;
    double media();
    static bool compara(Aluno a1, Aluno a2);
private:
    int RA;
    double NP;
    double NT;
};

#endif /* ALUNO_H */

