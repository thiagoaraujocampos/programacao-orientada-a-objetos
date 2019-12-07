#ifndef DATAHORARIO_H
#define DATAHORARIO_H

#include <string>
#include <iostream>
using namespace std;

namespace poo {

    class DataHorario {
    public:
        DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo);
        ~DataHorario();
        int compara(DataHorario &obj);
        int getDia();
        int getMes();
        int getAno();
        int getHora();
        int getMinuto();
        int getSegundo();
        void imprime(bool sistema);
        void imprimePorExtenso();
    private:
        int dia, mes, ano, hora, minuto, segundo;
    };
}

#endif /* DATAHORARIO_H */

