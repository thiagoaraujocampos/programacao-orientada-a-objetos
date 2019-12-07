#include "Aluno.h"
#include "DataHorario.h"
#include "Sessao.h"
#include "Pessoa.h"
using namespace poo;

void imprimeAluno(Aluno& aluno) {
    aluno.imprime();
    cout << "[Final] ";
    if (aluno.aprovado()) {
        cout << "Aluno aprovado" << endl;
    } else if (aluno.sac()) {
        cout << "(SAC) Nota mínima: " << aluno.notaSAC() << endl;
    } else {
        cout << "Aluno reprovado." << endl;
    }
}

int main(int argc, char** argv) {

    Pessoa p("Fulano", 12345);
    p.imprime();

    cout << endl;

    Aluno a1("Aluno 01", 11111, 800001, 3, 3, 7, 8, 4);
    imprimeAluno(a1);

    cout << endl;

    Aluno a2("Aluno 02", 22222, 800002, 6, 5, 7, 8, 4);
    imprimeAluno(a2);

    cout << endl;

    Aluno a3("Aluno 03", 33333, 800003, 7, 8, 7, 8, 9);
    imprimeAluno(a3);

    cout << endl;

    DataHorario dh(31, 8, 2019, 15, 57, 10);
    dh.imprime(true);
    dh.imprime(false);
    dh.imprimePorExtenso();

    cout << endl;

    DataHorario dh2(31, 8, 2019, 12, 57, 10);
    dh2.imprime(true);
    dh2.imprime(false);
    dh2.imprimePorExtenso();

    cout << endl;

    DataHorario dh3(31, 8, 2019, 21, 00, 00);
    dh3.imprime(true);
    dh3.imprime(false);
    dh3.imprimePorExtenso();

    cout << endl;

    Sessao sessao("O Fantasma da Ópera", dh3);

    sessao.imprime();
    
    /*string s = sessao.proximoLivre();
    cout << s;
    sessao.ocupa(s, p); */
    cout << endl;

    
    for (int i = 0; i < 28; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, p);
    }

    for (int i = 0; i < 28; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, a1);
    }

    for (int i = 0; i < 28; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, a2);
    }

    for (int i = 0; i < 28; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, p);
    }

    for (int i = 0; i < 28; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, a1);
    }

    sessao.imprime();

    for (int i = 1; i <= 14; i++) {
        string s = "A" + to_string(i);
        sessao.desocupa(s);
    }

    for (int i = 1; i <= 6; i++) {
        string s = "B" + to_string(i);
        sessao.desocupa(s);
    }

    sessao.imprime();

    cout << endl;

    for (int i = 0; i < 48; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, a3);
    }

    sessao.imprime();

    cout << endl;
     
}
