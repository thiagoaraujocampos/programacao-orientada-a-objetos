#include <iostream>
#include <fstream>

using namespace std;

// Lê três números
// Calcula quem é o maior (armazena na variável maior)
// Imprime a variável

int main(int argc, char** argv) {
    
    int a, b, c, maior;
    
    ifstream in; //Sempre abre para leitura
    // Leitura
    //              ifstream -> open("nomedoarquivo")
    //              fstream -> open("nomedoarquivo", ios::in)
    ofstream out; //Sempre abre para escrita
    // Escrita
    //              ofstream -> open("nomedoarquivo")
    //              fstream -> open("nomedoarquivo", ios::out)
    
    // Escrita/Leitura
    //              fstream -> open("nomedoarquivo", ios::in|ios::out)
    
    
    in.open("entrada.txt");
    out.open("saida.txt");
    
    in >> a;
    in >> b;
    in >> c;
    
    if (a > b) {
        maior = a;
    } else {
        maior = b;
    }
    
    if (c > maior) {
        maior = c;
    }
    
    out << "O Maior valor é: " << maior << endl;
    
    in.close();
    out.close();
    
    return 0;
}

