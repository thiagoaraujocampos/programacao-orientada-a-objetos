#include <iostream>
#include "ContaCorrente.h"

using namespace std;

ContaCorrente::ContaCorrente(int numero, double saldo) {
    cout << "Construindo Conta " << numero << endl;
    this->numero = numero;
    this->saldo = saldo;
}

ContaCorrente::~ContaCorrente() {
    cout << "Destruindo Conta " << numero << endl;
}

bool ContaCorrente::retirada(double valor) {
    if (saldo - valor >= 0) {
        saldo -= valor;
        return true;
    }
    return false;
}

void ContaCorrente::deposito(double valor) {
    this->saldo += valor;
}

bool ContaCorrente::transferencia(ContaCorrente &outra, double valor) {
    bool ok = this->retirada(valor);
    if (ok) {
        outra.deposito(valor);
    }
    return ok;
}

void ContaCorrente::imprime() {
    cout << "Numero: " << numero << ", saldo: " << saldo << endl;
}
