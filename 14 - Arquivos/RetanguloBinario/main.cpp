#include "Retangulo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void grava(string fileName) {

    Retangulo r;
    double x, y;

    ofstream saida(fileName.c_str(), ios::binary);

    for (int i = 0; i < 3; i++) {
        cout << "\n Digite base e altura: ";
        cin >> x >> y;
        r.setDim(x, y);
        saida.write(reinterpret_cast<char*> (&r), sizeof (Retangulo));
    }

    saida.close();
}

void imprime(string fileName) {

    Retangulo r;

    ifstream entrada(fileName.c_str(), ios::binary);

    entrada.read(reinterpret_cast<char*> (&r), sizeof (Retangulo));
    while (entrada.good()) {
        r.imprimir();
        entrada.read(reinterpret_cast<char*> (&r), sizeof (Retangulo));
    }
}

void imprime(string fileName, int pos) {

    Retangulo r;

    ifstream entrada(fileName.c_str(), ios::binary);

    entrada.seekg((pos - 1) * sizeof (Retangulo));
    entrada.read(reinterpret_cast<char*> (&r), sizeof (Retangulo));

    if (entrada.good()) {
        r.imprimir();
    } else {
        cout << "Retangulo não encontrado" << endl;
    }
}

void ordenaArquivo(string fileName) {

    Retangulo r;

    vector<Retangulo> retangulos;
    ifstream entrada(fileName.c_str(), ios::binary);

    entrada.read(reinterpret_cast<char*> (&r), sizeof (Retangulo));
    while (entrada.good()) {
        retangulos.push_back(r);
        entrada.read(reinterpret_cast<char*> (&r), sizeof (Retangulo));
    }

    entrada.close();

    sort(retangulos.begin(), retangulos.end(), Retangulo::compara);

    ofstream ordenado(fileName.c_str(), ios::binary);
    for (int i = 0; i < retangulos.size(); i++) {
        ordenado.write(reinterpret_cast<char*> (&retangulos[i]), sizeof (Retangulo));
    }

    ordenado.close();
}

int main() {

    string fileName = "info.dat";
    
    //grava(fileName);
    
    imprime(fileName);
   
    int pos;

    cout << "Posicao: ";
    cin >> pos;

    imprime(fileName, pos);
    
    ordenaArquivo(fileName);
    
    imprime(fileName);
    return 0;
}