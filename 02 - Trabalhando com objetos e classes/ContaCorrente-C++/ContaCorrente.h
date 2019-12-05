#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

class ContaCorrente {
public:
    ContaCorrente(int numero, double saldo = 0); // construtor 
    virtual ~ContaCorrente(); // destrutor
    // métodos da classe
    bool retirada(double valor);
    void deposito(double valor);
    bool transferencia(ContaCorrente &outra, double valor);
    void imprime();
private: // atributos da classe
    int numero;
    double saldo;
};

#endif /* CONTACORRENTE_H */

