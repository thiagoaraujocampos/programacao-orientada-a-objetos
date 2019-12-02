#include <iostream>
#include <fstream>
#include <string>

void transforma(char &c) {
    int a;
    if(c >= 'A' && c <= 'Z') {
        c = c - 'A' + 'a';
    } else if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
}

using namespace std;

int main(int argc, char** argv) {
    
    ifstream arq_entrada;
    ofstream arq_saida;
    string palavra;
    
    arq_entrada.open("dados.txt");
    arq_saida.open("saida.txt");
    
    if (arq_entrada.is_open()) {
        while(!arq_entrada.eof()) {
            arq_entrada >> palavra;
            for(int i = 0; i < palavra.size(); i++) {
                transforma(palavra[i]);
            }
            arq_saida << palavra << " ";
            cout << palavra << " ";
        }
    } else {
        cout << "O arquivo não pode ser aberto.";
    }
    
    arq_entrada.close();
    arq_saida.close();
    
    return 0;
}

