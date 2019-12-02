#include "TextFile.h"

TextFile::TextFile() {
}

TextFile::~TextFile() {
}

void TextFile::contaCaracteres(string nome) {

    ifstream ifs(nome.c_str(), ifstream::in);

    int nroLetras = 0;
    int nroDigitos = 0;
    int nroOutros = 0;
    int nroCaracteres = 0;

    char c = toupper(ifs.get());

    while (ifs.good()) {
        nroCaracteres++;
        if (c >= 'A' && c <= 'Z') {
            nroLetras++;
        } else if (c >= '0' && c <= '9') {
            nroDigitos++;
        } else {
            nroOutros++;
        }
        c = toupper(ifs.get());
    }

    cout << "Número caracteres: " << nroCaracteres << endl;
    cout << "Número letras: " << nroLetras << endl;
    cout << "Número digitos: " << nroDigitos << endl;
    cout << "Número outros: " << nroOutros << endl;

    ifs.close();
}

