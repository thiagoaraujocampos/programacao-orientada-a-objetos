#include "Endereco.h"
#include <iostream>

using namespace std;

// construtor com 4 parâmetros

Endereco::Endereco(string logradouro, int numero, string cidade, string estado) {

    this->logradouro = logradouro;
    this->numero = numero;
    this->cidade = cidade;
    this->estado = estado;
}

// destrutor da classe

Endereco::~Endereco() {
    cout << "Destrutor Endereco (" << logradouro << ", " << numero << ")" << endl;
}

string Endereco::getLogradouro() {
    return logradouro;
}

void Endereco::setLogradouro(string val) {
    logradouro = val;
}

int Endereco::getNumero() {
    return numero;
}

void Endereco::setNumero(int val) {
    numero = val;
}

string Endereco::getCidade() {
    return cidade;
}

void Endereco::setCidade(string val) {
    cidade = val;
}

string Endereco::getEstado() {
    return estado;
}

void Endereco::setEstado(string val) {
    estado = val;
}

void Endereco::imprime() {
    cout << "Logradouro: " << this->getLogradouro() << endl;
    cout << "Numero: " << this->getNumero() << endl;
    cout << "Cidade: " << this->getCidade() << endl;
    cout << "Estado: " << this->getEstado() << endl;
}
