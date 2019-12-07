#include "Aluno.h"

namespace poo {

    Aluno::Aluno(string nome, int cpf, int RA, double notaP1, double notaP2, double notaT1, double notaT2, double notaT3) 
    : Pessoa(nome, cpf), RA(RA) {
        // Inserindo as notas em suas respectivas posições
        notaP[0] = notaP1;
        notaP[1] = notaP2;
        notaT[0] = notaT1;
        notaT[1] = notaT2;
        notaT[2] = notaT3;
        cout << "Construtor (aluno): (" << nome << ", " << cpf << ", " << RA << ", " << notaP[0] << ", " << notaP[1] << ", " << notaT[0] << ", " << notaT[1] << ", " << notaT[2] << " )" << endl; // Printa quando constrói aluno
    }

    Aluno::~Aluno() {
        
    }

    int Aluno::getRA() {
        return RA;
    }

    void Aluno::imprime() {
        Pessoa::imprime(); // Imprime as informações de pessoa (nome e cpf)
        cout << "RA: " << RA << endl; //imprime as informações de Aluno
        cout << "Notas das provas: " << notaP[0] << ", " << notaP[1] << endl;
        cout << "Notas dos trabalhos: " << notaT[0] << ", " << notaT[1] << ", " << notaT[2] << endl;
        cout << "Média: " << media() << endl; // Chama função que calcula média.
        if (aprovado()) { // Mostra se foi aprovado, se precisa de SAC ou se está reprovado
            cout << "Aprovado" << endl;
        } else {
            if (sac()) {
                cout << "Aluno precisa de Prova de Avaliação Complementar\nNota mínima na SAC: " << notaSAC() << endl;
            } else {
                cout << "Reprovado" << endl;
            }
        }

    }

    double Aluno::media() { // Calcula média do aluno conforme demonstrado no trabalho
        double mp = (notaP[0] + notaP[1])/2, mt = (notaT[0] + (2*notaT[1]) + (3*notaT[2]))/6;
        return ((mp * 8)+(mt * 2)) / 10;
    }

    bool Aluno::aprovado() { // Retorna 1 caso aprovado
        if (media() >= 6.00) {
            return 1;
        } else {
            return 0;
        }
    }

    bool Aluno::sac() { // Verifica se o aluno precisa de Prova de Avaliação Complementar
        if (media() >= 5.00 && media() < 6.00) {
            return 1;
        } else {
            return 0;
        }
    }

    double Aluno::notaSAC() { // Retorna nota necessária para passar na SAC ou 0 caso não seja necessário faze-la
        if (sac()) {
            return 12 - media();
        } else {
            return 0;
        }
    }

}

