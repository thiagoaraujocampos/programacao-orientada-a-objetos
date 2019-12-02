#include "BinaryFile.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

    char op;
    int nroAlunos, pos;
    int RA;
    
    BinaryFile bf("info.dat"); 
    
    do {
        op = BinaryFile::opcao();
        switch (op) {
            case 'G': 
                cout << "Numero de Alunos: ";
                cin >> nroAlunos;
                bf.grava(nroAlunos);
                break;
            case 'I':
                bf.imprime();
                break;
            case 'R':
                cout << "RA: ";
                cin >> RA;
                bf.imprimeRA(RA);
                break;
            case 'P':
                cout << "Posição: ";
                cin >> pos;
                bf.imprimePos(pos);
                break;
            case 'O':
                bf.imprimeOrdenado();
                break;
            case 'A':
                bf.imprimeAprovados();
                break;
            case 'B':
                bf.imprimeReprovados();
                break;
            case 'S':
                bf.imprimeSAC();
                break;
        }
        cout << endl;
    } while (op != 'F');

    return 0;
}

