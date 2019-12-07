#ifndef SESSAO_H
#define SESSAO_H

#include "Pessoa.h"
#include "DataHorario.h"

namespace poo {

    class Sessao {
    public: 
        Sessao(string nomePeca, DataHorario& dataHora);
        ~Sessao(); 
        string proximoLivre(); 
        bool verifica(string poltrona); 
        bool ocupa(string poltrona, Pessoa &pessoa); 
        bool desocupa(string poltrona);
        int vagas(); 
        void imprime(); 
        
    private: 
        string nomePeca;
        DataHorario& dataHora;
        Pessoa **espectador;
    };
}

#endif /* SESSAO_H */

