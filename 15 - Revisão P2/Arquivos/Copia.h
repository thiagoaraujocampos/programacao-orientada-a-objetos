#ifndef COPIA_H
#define COPIA_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Copia {
public:

    Copia() {

    }

    virtual ~Copia() {

    }

    static void substituiPalavra(string fileIn, string fileOut, char old, char novo) {
        string palavra;
        ifstream in;
        ofstream out;
        in.open(fileIn.c_str());
        out.open(fileOut.c_str());

        if (in.is_open()) {
            while (!in.eof()) {
                in >> palavra;
                for (int i = 0; i < palavra.size(); i++) {
                    if(palavra[i] == old || palavra[i] == toupper(old)) {
                        palavra[i] = novo;
                    }
                }
                out << palavra << " ";
                cout << palavra << " ";
            }
        }

        in.close();
        out.close();
    }
    
    static void substituiLinha(string fileIn, string fileOut, char old, char novo) {
        string linha;
        
        ifstream in (fileIn.c_str());
        ofstream out (fileOut.c_str());
        
        if(in.is_open()) {
            while (getline(in, linha)) {
                for(int i = 0; i < linha.size(); i++) {
                    if(linha[i] == old) {
                        linha[i] = novo;
                    }
                }
                out << linha << "\n";
            }
        }
        
    }
    
    static void imprimeNLinhas(string fileIn, int n) {
        ifstream ifs(fileIn.c_str());
        
        vector<string> linhas;
        
        int contador = 0;
        string str;
        
        while (getline(ifs, str)) {
            contador++;
            linhas.push_back(str);
            if(contador > n) {
                linhas.erase(linhas.begin());
            }
        }
        
        for (int i = 0; i < linhas.size(); i++) {
            cout << linhas[i] << endl;
        }
        
        ifs.close();
    }
private:

};

#endif /* COPIA_H */

