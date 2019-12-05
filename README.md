# Programação Orientada a Objetos (POO)

### Conteúdo
 > _Com base no cronograma_
  
 1. [Introdução ao paradigma orientado a objetos](#introducao-ao-paradigma-orientado-a-objetos)
 2. [Trabalhando com objetos e classes em C++, Herança e Composição](#trabalhando-com-objetos-e-classes)
 3. [Métodos estáticos & métodos comuns](#métodos-estáticos-e-comuns)
 4. [Visibilidade de métodos e atributos: private, public, protected (C++)](#visibilidade-de-métodos-e-atributos)
 5. [Overriding (Sobreposição) & Overloading (Sobrecarga)](#overriding-e-overloading)
 6. [Relacionamento entre classes:](#relacionamento-entre-classes)
    * Composição
    * Agregação
    * Asociação
 7. [Namespace C++](#namespace)
 8. [Alocação Dinâmica](#alocação-dinâmica)
 9. [Polimorfismo, Sobrecarga de métodos e operadores](#polimorfismo,-sobrecarga-de-métodos-e-operadores)
 10. [Sobrecarga de operadores (métodos friend)](#sobrecarga-de-operadores-(métodos-friend))
  
 > **P1**

 11. [Herança Múltipla (diamond problem)](#herança-múltipla)
 12. [Classes Abstratas (Interfaces)](#classes-abstratas)
 13. [Templates: polimorfismo paramétrico](#polimorfismo-paramétrico)
 14. [Arquivos](#arquivos)
 15. [Tratamento de Exceções](#tratamento-de-exceções)
 
 > **P2**
 ---
 ### Introdução ao paradigma orientado a objetos
 
 Para uma linguagem ser considerada orientada a objetos ele precisa implementar quatro conceitos básicos:
 
   1. Abstração: habilidade de modelar características do mundo real.
   2. Encapsulamento: habilidade da unidade de proteger os dados e permitir que apenas suas operações internas tenham acesso a elas
   3. Herança: mecanismo que permite
      a) a criação de novos objetos por meio da modificação de algo já existente;
      b) o vínculo do objeto criado com o objeto antigo.
   4. Polimorfismo: capacidade de uma unidade ter várias formas.
   
 O paradigma de orientação a objetos, basicamente, é um príncipio que se baseia em criar novos "objetos" através de "objetos" já existentes, ou então, utiliza-se de "moldes" para que seja possível a construção de outras ferramentes facilmente.
 
 **Abstrair** é encontrar algo geral que pode ser aplicado á outros casos menores.
 **Encapsular** é "esconder" detalhes para os manter "protegidos", análogo a uma capsula de remédio.
 **Herança** são características que podem ser herdadas de um para outro, assim como no conceito biológico.
 **Polimorfismo** é a transformação que pode ocorrer de um algo geral para outros, por isso um "Polimorfo".
 
 A Pasta _01 - Introdução ao paradigma orientado a objetos_ tem um pequeno exemplo de projeto orientado a objetos: **Pontos25-C++**.
 
 Esse projeto possuí três arquivos principais que o compõe: main.cpp, Ponto2D.cpp e Ponto2D.h. Estes fazem um conjunto que podem facilmente fazer com que o conceito de orientação a objeto básico possa ser visto.
 
 - **Ponto2D.h** _Header_ do projeto.
```c++
#ifndef PONTO2D_H
#define PONTO2D_H

class Ponto2D {
public:
    Ponto2D(float x, float y); // Construtor
    virtual ~Ponto2D(); // Destrutor
    
    float distancia(Ponto2D p); // Método da classe
private:
    float x, y; // Atributos da classe
};

#endif /* PONTO2D_H */
 ```
 
 Aqui está a primeira classe que veremos. **Ponto2D.h** é um arquivo de cabeçalho, aqui estão a assinatura dos métodos (funções da classe) e seus atributos. O importante de entender aqui é que esse é o "geral" correspondente a um ponto, temos duas coordenadas x e y, criar um ponto com o construtor (passando as coordenadas como parâmetro) e calcular a distância de um determinado ponto a outro (que foi passado por parâmetro).
 
 - **Ponto2D.cpp**
```c++
#include <math.h>
#include "Ponto2D.h"

Ponto2D::Ponto2D(float a, float b) {
    x = a;
    y = b;
}

Ponto2D::~Ponto2D() {

}

float Ponto2D::distancia(Ponto2D p) {
    float dx = x - p.x;
    float dy = y - p.y;
    return sqrt(dx * dx + dy * dy);
}
 ```
 
 Aqui estão implementadas os métodos declarados em _Pontos2D.h_. Em **Pontos25.cpp** pode-se perceber como os atributos são definidos quando usamos o construtor e como pode ser implementado a lógica de um método (como em _ float distancia(Pontos25 p)_).
 
 - **main.cpp**
```c++
#include <cstdio>
#include "Ponto2D.h"

int main(int argc, char** argv) {

    Ponto2D p1(4, 4);
    Ponto2D p2(7, 8);    

    printf("dist(P1, P2) = %5.2f\n", p1.distancia(p2));
    printf("dist(P2, P1) = %5.2f\n", p2.distancia(p1));

    return 0;
}
 ```
 
 o arquivo **main.cpp** possúi o include da classe _#include "Ponto2D.h"_ e a instanciação de objetos do tipo ponto (usando seu construtor e passando as coordenadas por parâmetro)
 
 ### Trabalhando com objetos e classes
 
 Como visto na introdução, uma classe pode ser considerada como o par de arquivos .h e .cpp que conterão, repectivamente, a assinatura da classe e a implementação dos métodos. Mas devemos nos aprofundar um pouco em como usar uma classe.
 
 Um objeto é a instanciação de uma classe, ou então, a classe é um geral que pode ser aplicada a determinado objeto, como por exemplo, se tivessemos uma classe pessoa na vida real poderiamos dizer que todos as pessoas do planeta são objetos dessa classe, ou então, todas elas possuí características em comum que estão encapsuladas nessa classe (altura etc). Lógico que o mundo é bem mais complexo do que somente uma classe pessoas mas esse exemplo ajuda a entender o que é uma classe e seus objetos.
 
 É interessante dizer aqui que você poderá ver, recorrentemente, diagramas de classe toda vez que vai estudar um projeto orientado a objeto. um diagrama de classe representa classes (com seus elementos incluídos) e suas interações com outras classes de forma visual e facilitada.
 
 Nesse tópico introduzi um projeto um pouco mais elaborado na pasta _02 - Trabalhando com objetos e classes_: **ContaCorrente-C++**. Esse projeto consiste na criação da classe ContaCorrente que possuí elementos semelhantes a uma conta real e métodos capazes de manipular os atributos (depósito, retirada, transferência e imprime).
 
 ```c++
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
 ```

 A implementação em _ContaCorrente.cpp_ pode ser conferida na pasta assim como a _main.cpp_ que contêm um simples uso da classe e utilizando seus métodos entre dois objeto diferentes instanciados.

 ### Métodos estáticos e comuns
 
 Antes de dizer diretamente o que é um método estático e comum (como já pode ser induzidos pelos tópicos acima), vamos ver um exempl de projeto com herança.
 
 Em _03 - Métodos estáticos e comuns_ foi disponibilizado _Herança_. Este projeto possuí o seguinte diagrama:
 
 ![Diagrama Pessoa](https://i.imgur.com/pmY6du9.png)
 
 Percebe-se que a classe pessoa é "pai" da classe professor e professor é "pai" de coordenador. Com isso é fácil perceber que coordenador herda os elementos de professor que herda de pessoa.
 
 Em outras palavra, um coordenador é um professor que é uma pessoa, um professor é uma pessoa, e uma pessoa somente é uma pessoa. No fim da história todos são pessoas, porém alguns possuem ramificações especiais de pessoas.
 
 Outro fato curioso desenvolvido nesse projeto é o elemento _static int contador_ na classe pessoa que é nossa primeiro contato com um atributo estático. Esse atributo é feito com intuito de contar quantas pessoas existem no total (implementado: contador++ no construtor e contador-- no destrutor).
 
 **Atributo estático**
 
 Um **atributo estático** é um atributo que é compartilhado por toda a classe (ele não pertece exclusivamente a cada objeto e sim a classe como um todo).
 
 ```c++
 static <tipo> <nomeAtributo>;
 ```
 
 Também podemos usar constantes em conjunto com _static_
 
 ```c++
 static const <tipo> <nomeAtributo> = <valor>;
 ```
 
 Para acessar atributos estáticos não é nessário instancia objeto:
 
 ```c++
 <NomeDaClasse>::<atributoDaClasse>;
 ```
 
 **Método estático**
 
 Um **método estático** é, de modo semelhante ao atributo estático, compartilhado por toda classe.
 
 ```c++
 static <tipoRetorno> <nomeMetodo> (params);
 ```
 
 Para acessar (não é necessário instanciar objetos):
 
 ```c++
 C++: <NomeDaClasse>::<métodoDaClasse>;
 ```
 
 ### Visibilidade de métodos e atributos
 ### Overriding e Overloading
 ### Relacionamento entre classes
 ### Namespace
 ### Alocação dinâmica
 ### Polimorfismo, Sobrecarga de métodos e operadores
 ### Sobrecarga de operadores (métodos friend)
 
 
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
 ### Polimorfismo paramétrico
  
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
 ### Arquivos
 
 A utilização de arquivos é baseada no armazenamento de dados fora da memória principal para que seja possível, por exemplo, um armazenamento permanente de informações. Essa ferramenta é muito importante para que seja possível que o sistema possa manter atualizado constantemente os dados no software mesmo após desligamento da maquina entre outras causas.
 
 Para que seja dominado o entendimento de arquivos, antes, é necessário entender um pouco sobre **Entradas e Saídas**.
 
  * **Stream**: palavra usada para indicar _fluxo de bytes_. Dessa forma, objetos que tem a capacidade de receber ou transferir bytes de ou para a memória é chamado de **objeto stream**.
    * cin e cout são exemplos de objetos stream.
  
 Em C++ são fornecidas três classes para lidar com arquivos:
   * **ofstream** para escrever em arquivos;
   * **ifstream** para ler de arquivos;
   * **fstream** para ler e/ou escrever em arquivos.
   
Para usá-las precisamos incluir a biblioteca <fstream>.
 
  * Arquivo de Saída:
    ```c++
     ofstream arqSaida;
     arqSaida.open("nomeArquivo.txt")
     arqSaida << "Gravando no arquivo";
     arqSaida.close();
    ```
  
  * Arquivo de Entrada:
    ```c++
     ifstream arqSaida;
     arqEntrada.open("nomeArquivo.txt")
     arqEntrada >> x;
     arqEntrada.close();
    ```
  _Obs: O operador de extração de fluxo (>>) pula os caracteres em branco como espaços, tabulações e nova linha no fluxo de entrada._
  
  Os exemplos de arquivos estão presentes em _17 - Arquivos_ onde é possível verificar ArquivoTexto, ArquivoTxt2, ContaCaracteres, CopiaTransformada, RetanguloBinario e ArquivoBinario. Todos utilizando a teoria de arquivos em sua conjuntura.
  
  **ArquivoTxt2**
  
  Esse projeto contém uma codificação simples do funcionamento de arquivos. O objetivo é abrir um arquivo para Saída e um para Entrada onde será lido o arquivo de entrada e seu conteúdo copiada para o arquivo de Saída.
  
  ```c++
  #include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    
    ifstream arq_entrada;
    ofstream arq_saida;
    string palavra;
    
    arq_entrada.open("dados.txt");
    arq_saida.open("saida.txt");
    
    if (arq_entrada.is_open()) {
        while(getline(arq_entrada, palavra)) {
            arq_saida << palavra << endl;
        }
    } else {
        cout << "O arquivo não pode ser aberto.";
    }
    
    arq_entrada.close();
    arq_saida.close();
    
    return 0;
}
  ```
 
 Além disso, existe uma verificação para confirmar que o arquivo foi aberto com sucesso (asegurando um erro futuro).
 
 **Métodos de abertura de arquivos**
 
|Modos|Descrição|
|---|---|
|ios::in|abre para leitura|
|ios::out|abre para gravação|
|ios::app|grava a partir do fim do arquivo|
|ios::trunc|abre e apaga todo o conteúdo do arquivo|
|ios::ate|abre e posiciona no final do arquivo|
 
  * Arquivo de Entrada:
    ```c++
     fstream arq;
     arq.open("nomeArquivo.txt", ios::in) //Abrir somente leitura
     arq.open("nomeArquivo.txt", ios::out) //Abrir somente leitura
     arq.open("nomeArquivo.txt", ios::in|ios::out) //Abrir leitura e escrita
    ```
 
 Algumas observações:
 
 **ofstream:** 
   * Abre somente para escrita (não permite leitura);
   * Se não existe, o arquivo é criado;
   * Se o arquivo já existe, o seu conteúdo anterior é apagado.
   
 **ifstream:** 
   * Abre somente para leitura (Não é permitido escrita);
   * A abertura falha caso o arquivo não exista.
 
 Para verificar o **fim de arquivos** usamos **eof()**. É retornado true se o marcador estiver no fim do arquivo e false caso contrário.
 
   ```c++
     ifstream inArq;
     ofstream outArq;
     inArq.eof();
     outArq.eof();
   ```
 Para verificar se um arquivo foi aberto com sucesso pode-se usar a função **is_open()** que retorna true se o arquivo encontra-se aberto ou false caso contrário.
 
   ```c++
     inArq.is_open();
     outArq.is_open();
   ```
   
  Trabalhando com um único caracter por vez:
    * inArq.get(caracter): Pega o próximo caracter da stream inArq;
    * outArq.put(caracter): Insere o caracter na stream saída.
  
   
**Arquivos em modo binário**

Para gravar ou ler um bloco de dados pode-se usar **write()** e **read()**
 
  * Exemplo retangulo:
    Classe:
    ```c++
    #ifndef RETANGULO_H
    #define RETANGULO_H

    class Retangulo {
    private:
      double ladoa;
      double ladob;
    public:
      void setDim(double a, double b) {
        ladoa = a;
        ladob = b;
      }
      void imprimir() {
        cout << "Retangulo com lados : " << ladoa << " e " << ladob << end << "Area : " << area() << endl << endl;
      }
      double area() {
        return ladoa * ladob;
      }
      static bool compara(Retangulo r1, Retangulo r2) {
        return r1.area() < r2.area();
      }
    };

    #endif /* RETANGULO_H */
    ```
    
    Main:
    ```c++
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
        cin >> x>>y;
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
      grava(fileName);
      imprime(fileName);
      int pos;
      cout << "Posicao: ";
      cin >> pos;
      imprime(fileName, pos);
      ordenaArquivo(fileName);
      imprime(fileName);
      return 0;
    }
    ```
    
   Esse exemplo apesar de grande representa muito do uso de arquivos, arquivo binário e suas interações com estruturas. O programa, basicamente, possuí a classe retangulo a qual guarda dois lados do retangulo e tem alguns métodos (setDim, imprimir, area e compara). Essa classe é usada para instanciar objetos e guarda-los no arquivo binário usando **write()** e também para ler usando **read()**. Além disso, usa-se as bibliotecas <vector> e <algorithm> para criar o vetor de objetos retangulo e ordena-lo.
 
 ---
 ### Tratamento de Exceções
 
