#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    
    ifstream arq_entrada;
    ofstream arq_saida;
    string palavra;
    
    arq_entrada.open("dados.txt");
    arq_saida.open("saida.txt");
    
    if (arq_entrada.is_open()) {
        //while(!arq_entrada.eof()) {
        //    arq_entrada >> palavra;
        //    arq_saida << palavra << " ";
        //    cout << palavra << " ";
        //}
        while(getline(arq_entrada, palavra)) {
            arq_saida << palavra << endl;
        }
    } else {
        cout << "O arquivo não pode ser aberto.";
    }
    
    arq_entrada.close();
    arq_saida.close();
    
    return 0;
}

