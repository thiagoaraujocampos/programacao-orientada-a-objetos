# Programação Orientada a Objetos (POO)

### Conteúdo
 > _Com base no cronograma_
  
 1. Introdução ao paradigma orientado a objetos
 2. Trabalhando com objetos e classes em C++, Herança e Composição
 3. Métodos estáticos & métodos comuns
 4. Visibilidade de métodos e atributos: private, public, protected (C++)
 5. Overriding (Sobreposição) & Overloading (Sobrecarga)
 6. Relacionamento entre classes:
    * Composição
    * Agregação
    * Asociação
 7. Namespace C++
 8. Alocação Dinâmica
 9. Polimorfismo, Sobrecarga de métodos e operadores
 10. Sobrecarga de operadores (métodos friend)
  
 > **P1**

 11. [Herança Múltipla (diamond problem)](#herança-múltipla)
 12. [Classes Abstratas (Interfaces)](#classes-abstratas)
 13. [Templates: polimorfismo paramétrico](#polimorfismo-paramétrico)
 14. [Arquivos](#arquivos)
 15. [Tratamento de Exceções](#tratamento-de-exceções)
 
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
 
