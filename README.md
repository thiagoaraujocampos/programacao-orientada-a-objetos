# Programação Orientada a Objetos (POO)

### Conteúdo
 > _Com base no cronograma_
  
 * Introdução ao paradigma orientado a objetos
 * Trabalhando com objetos e classes em C++, Herança e Composição
 * Métodos estáticos & métodos comuns
 * Visibilidade de métodos e atributos: private, public, protected (C++)
 * Overriding (Sobreposição) & Overloading (Sobrecarga)
 * Relacionamento entre classes:
   - Composição
   - Agregação
   - Asociação
 * Namespace C++
 * Alocação Dinâmica
 * Polimorfismo, Sobrecarga de métodos e operadores
 * Sobrecarga de operadores (métodos friend)
  
 > **P1**

 * Herança Múltipla (diamond problem)
 * Classes Abstratas (Interfaces)
 * Templates: polimorfismo paramétrico
 * Tratamento de Exceções
 * Entrada e Saída (Classes orientadas a objetos)
 
 > **P2**
 ---
 
 ### Herança Múltipla
 > Diamond problem
 
 Herança em Programação Orientada a Objetos pode ser relacionada diretamente com o que o nome diz, uma transmissão de características para indivíduos da mesma espécie, o mesmo acontece no paradigma em que uma classe pode herdar atributos de outra classe. De forma semelhante, a herança múltipla também herda atributos de uma outra classe, porém, mais de uma classe é considerada. Os exemplos na pasta _'14 - Herança Multiplica'_ caracterizam exatamente a herança direta de duas classes para uma.
 
 **Em Liger, foram criadas 4 classes: Animal, Lion, Tiger e Liger.**
 
 ![Diagrama Liger](https://i.imgur.com/Hqx2kpR.png)
 
 A classe Liger é herda atributos de Lion e Tiger definindo uma herança múltipla. Além disso a classe Animal tem Lion e Tiger como herdeiros diretos.
 Essa implementação pode ser construída elaborando Liger da seguinte maneira:
 ```c++
 #ifndef LIGER_H
#define LIGER_H

#include "Lion.h"
#include "Tiger.h"

class Liger : public Lion, public Tiger {
public:
    Liger(int weight) : Lion(weight), Tiger(weight) {
    }
    virtual ~Liger() {
    }
    int getWeight() {
       return Tiger::getWeight();
    }
};

#endif /* LIGER_H */
 
 ```
 
 _Obs:_ Na construção do projeto, tanto a classe Lion como a Tiger são compostas só pelo construtor e destrutor (ambas são public Animal). E a main só testa o código criando um objeto do tipo Liger (inserindo uma weight no construtor) e depois printando o valor de getWeight().
 
 **Em Anfibio, foram criadas 3 classes: Barco, Carro e Anfibio.**
 
 ![Diagrama Anfibio](https://i.imgur.com/5StYZZP.png)
 
 É interessante perceber que Anfibio herda métodos de ambas as classes (Barco e Carro) permitindo-o que use navegar() e andar().
 
 ---
 ### Classes Abstratas
 
 Uma classe abstrata não permite instanciações, elas são construídas para estabelecer parâmetros para classes herdadas a ela. Dessa forma, as classes que herdeiras devem, obrigatoriamente, implementar a função abstrata para que se torne uma classe concreta. 
 A sinalização de uma classe abstrata acontece quando igualamos um método a zero (este também deverá ser um método virtual). O exemplo dessa utilização é dado em _'15 - Classes Abstratas'_ onde é construído o projeto PessoaAbstrata.
 
 **PessoaAbstrata**

 Esse projeto contém 3 classes: Pessoa, Enfermeiro e Médico.
 
 ![Diagrama PessoaAbstrata](https://i.imgur.com/MmFFUbh.png)
 
 Pessoa é uma classe abstrata porque dentro de sua declaração temos um método abstrato _virtual string getProfissao() = 0;_ como pode ser visto no código da classe:
 
```c++

#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
using namespace std;

class Pessoa {
public:
    Pessoa(int CPF, string nome) : CPF(CPF), nome(nome) {
    }
    virtual ~Pessoa() {
        
    }
    virtual string getProfissao() = 0;
    virtual void imprime() {
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << CPF << endl;
        cout << "Profissão: " << getProfissao() << endl;
    }
private:
    int CPF;
    string nome;
};

#endif /* PESSOA_H */

```
 Essa implementação obriga que as classes Enfermeiro e Médico (herdeiros de pessoa) possuam implementado o método getProfissao().
 
 ---
 ### Templates: polimorfismo paramétrico
  
 Antes, podemos relembrar uma pequena definição: O Polimorfismo é o princípio pela qual duas ou mais classes derivadas de uma mesma 'superclasse' podem invocar métodos que tem a mesma identificação (assinatura) mas comportamentos distintos, especializado para cada classe derivada, usando para tanto uma referência a um objeto do tipo da 'superclasse'.
 
 Com isso, temos subdivisões do polimorfismo e um deles é o polimorfismo paramétrico. Esse tipo de polimorfismo é aquele que a partir de uma única definição de um método ou de atributo pode trabalhar de forma genérica com qualquer tipo.
 
 Em suma, o polimorfismo paramétrico funciona como uma forma de generalização, é esse tipo que permitirá que tenhamos uma classe 'molde' em que poderá ser usada para outros tipos como, por exemplo, exista uma classe com um vetor de inteiros porém é desejo do programador uma classe semelhante porém usando o tipo float, para isso é possivél usar o polimorfismo paramétrico para que, de forma genérica, seja criado uma classe capaz de aceitar ambos os tipos (sem precisar criar outra classe com nome diferente para que isso seja possível).
 
 Os exemplos estão na pasta _16 - Polimorfismo Paramétrico_ e neste é possível analisar CalculadoraFracao, Tamplate e Vetor todos desenvolvidos usando esse princípio.
 
 **Template**
 
 A classe Template é construída utilizando-se do template <class T> para que seja possível a generalização dos cálculos que são feitos em cada método da classe (soma, subtração, multiplicação e divisão).
 
 ```c++
#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>
using namespace std;

template <class T>
class Calculadora {
public:

    Calculadora(T num1, T num2) :
    num1(num1), num2(num2) {
    }

    ~Calculadora() {
    }

    T soma() {
        return num1 + num2;
    }

    T subtracao() {
        return num1 - num2;
    }

    T multiplicacao() {
        return num1 * num2;
    }

    T divisao() {
        return num1 / num2;
    }

    void imprime() {
        cout << "Numeros: " << num1 << " " << num2 << endl;
        cout << "Soma: " << soma() << endl;
        cout << "Subtracao: " << subtracao() << endl;
        cout << "Multiplicacao: " << multiplicacao() << endl;
        cout << "Divisao: " << divisao() << endl;
    }
private:
    T num1, num2;
};

#endif /* CALCULADORA_H */
 ```
 
 Pode-se perceber que todos os returns são do tipo T e que o construtor da classe recebe dois parâmetros do tipo T garantindo assim que poderá ser usado qualquer tipo aceitável dentro dos calculos em cada método.
 
 É relevante perceber que neste exemplo também está contruído na main um função do void troca(X& a, X& b) que também usa uma template:
 
 ```c++
template <class X> void troca(X& a, X& b) {
    X aux = a;
    a = b;
    b = aux;
}
 ```
 Neste último exemplo o nome dado para o template é X e por isso as varíaveis dentro da função (e seus parâmetros) são do tipo X.
 
 **CalculadoraFracao**
 
 Essa classe funciona de forma muito semelhante a Template (pois também foi implementado uma calculadora em Template), porém aqui usa-se a classe função para complementar a utilização do Template.
 
 ```c++
#ifndef FRACAO_H
#define FRACAO_H

#include <iostream>
using namespace std;

class Fracao {
public:
    Fracao (int a, int b) :     a(a), b(b) {
    }
    
    Fracao operator+ (const Fracao& right) const {
        int a = this->a;
        int b = this->b;
        int c = right.a;
        int d = right.b;
        return Fracao(a * d + b * c, b * d);
    }
    
    Fracao operator- (const Fracao& right) const {
        int a = this->a;
        int b = this->b;
        int c = right.a;
        int d = right.b;
        return Fracao(a * d - b * c, b * d);
    }
    
    Fracao operator* (const Fracao& right) const {
        int a = this->a;
        int b = this->b;
        int c = right.a;
        int d = right.b;
        return Fracao(a * c, b * d);
    }
    
    Fracao operator/ (const Fracao& right) const {
        int a = this->a;
        int b = this->b;
        int c = right.a;
        int d = right.b;
        return Fracao(a * d, b * c);
    }
    
    friend ostream& operator<< (ostream& os, const Fracao& obj) {
        os << obj.a << "/" << obj.b;
        return os;
    }
    
private:
    int a, b;
};

#endif /* FRACAO_H */
 ```
 
 É perceptível a utilização dos operadores aqui para que seja possível utilzar as frações na Calculadora. Na main, para que seja possível a manipulação de frações em Calculadora foi necessário instanciar uma calculadora do tipo fração da seguinte forma:
 
```c++
 Fracao f1(1,2);
    Fracao f2(1,3);
    Calculadora<Fracao> cFracao(f1, f2);
    cFracao.imprime();
```
 
 ---
 ### Tratamento de Exceções
 
 ---
 ### Entrada e Saída
 
