#include "TextFile.h"

TextFile::TextFile() {
}

TextFile::~TextFile() {
}

void TextFile::toLower(char& c) {
    if (c >= 'A' && c <= 'Z') {
        c = c - 'A' + 'a';
    }
}

void TextFile::toUpper(char& c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
}

bool TextFile::isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void TextFile::transforma(char& c, bool& upper) {
    if (isLetter(c)) {
        if (upper) {
            toUpper(c);
        } else {
            toLower(c);
        }
        upper = !upper;
    }
}

// Lê e escreve um caractere por vez

void TextFile::transformaC(string entrada, string saida) {
        
    ifstream ifs(entrada.c_str(), ifstream::in);
    ofstream ofs(saida.c_str(), ofstream::out);
    
    bool upper = true;
    
    char c = ifs.get();
    transforma(c, upper);

    while (ifs.good()) {
        ofs << c;
        c = ifs.get();
        transforma(c, upper);
    }

    ofs.close();
    ifs.close();
}

// Lê e escreve uma linha por vez

void TextFile::transformaL(string entrada, string saida) {
    
    ifstream ifs(entrada.c_str());
    ofstream ofs(saida.c_str());
    
    string str;
    bool upper = true;
    while (getline(ifs, str)) {
        for (int i = 0; i < str.size(); i++) {
            transforma(str[i], upper);
        }
        ofs << str << endl;
    }

    ofs.close();
    ifs.close();
}