#include "Sessao.h"
#include "Pessoa.h"

namespace poo {

    // Construtor de Sessao (Cria vetor de Pessoas com tamanho da capacidade da Sessao)
    Sessao::Sessao(string nomePeca, DataHorario& dataHora) : nomePeca(nomePeca), dataHora(dataHora) {
        espectador = new Pessoa*[210];
    }
    
    Sessao::~Sessao() {
        
    }
    
    // Verifica próximo assento livre
    string Sessao::proximoLivre() {
        // Vetor Letras para retornar a letra da fileira correspondente
        string letras[15] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O"};
        for(int i = 0; i < 15; i++) {
            for(int j = 0; j < 14; j++) {
                if(espectador[i * 14 + j] == NULL){
                    return letras[i] + to_string(j+1); // Se estiver vazio volta a posição disponível
                }
            }
        }
        return "Cheio"; // Se não achar nenhum vazio retorna "Cheio"
    }
    
    // Verifica se a poltrona está ocupada (1 para ocupada e 0 para disponível)
    bool Sessao::verifica(string poltrona) {
        if( espectador[(poltrona[0]-'A') * 14 + (stoi(poltrona.substr(1))-1)] == NULL ) { //Posicao relativa da matriz [A-O][1-14]
            return 0;
        }
        return 1;
    }
    
    // Usa funçao verifica() para verificar disponibilidade e insere uma pessoa na poltrona caso disponível 
    bool Sessao::ocupa(string poltrona, Pessoa &pessoa) {
        if(!verifica(poltrona)) { //Quando verifica() retornar 0 (poltrona disponível) entra no if
            espectador[(poltrona[0]-'A') * 14 + (stoi(poltrona.substr(1))-1)] = &pessoa;
            cout << "Poltrona " + poltrona + " reservada para " + espectador[(poltrona[0]-'A') * 14 + (stoi(poltrona.substr(1))-1)]->getNome() << endl;
            return 1;
        }
        return 0;
    }
    
    // Usa funçao verifica() para verificar disponibilidade e tira uma pessoa da poltrona caso ocupada 
    bool Sessao::desocupa(string poltrona) {
        if(verifica(poltrona)) {
            espectador[(poltrona[0]-'A') * 14 + (stoi(poltrona.substr(1))-1)] = NULL;
            cout << "Poltrona " + poltrona + " desocupada" << endl;
            return 1;
        }
        return 0;
    }
    
    // Conta a quantidade de Vagas disponíveis no Cinema
    int Sessao::vagas() {
        int cont = 0;
        for(int i = 0; i < 15; i++) {
            for(int j = 0; j < 14; j++) {
                if(espectador[i * 14 + j] == NULL) {
                    cont++;
                }
            }
        }
        return cont;
    }
    
    // Imprime o nome da peça e sua DataHorario
    void Sessao::imprime() {
        string letras[15] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O"};
        cout << nomePeca << endl;
        dataHora.imprime(0);
        // Representação dos espectadores da sessão
        for(int i = 0; i < 15; i++) {
            for(int j = 0; j < 14; j++) {
                if(espectador[i * 14 + j] != NULL){
                    cout << espectador[i * 14 + j]->getNome() << " - " << letras[i] + to_string(j+1) << endl;
                }
            }
        } 
    }
}