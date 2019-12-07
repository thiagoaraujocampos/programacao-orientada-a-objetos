#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>

using namespace std;

class Endereco {
public:
    Endereco(string logradouro, int numero, string cidade, string estado);
    virtual ~Endereco();
    string getLogradouro();
    void setLogradouro(string val);
    int getNumero();
    void setNumero(int val);
    string getCidade();
    void setCidade(string val);
    string getEstado();
    void setEstado(string val);
    void imprime();
private:
    string logradouro;
    int numero;
    string cidade;
    string estado;
};

#endif // ENDERECO_H
