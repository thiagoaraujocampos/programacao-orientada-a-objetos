# Trabalho 2
 
O trabalho foi baseado na construção do projeto Museu. Para isso foram determinadas quarto classes: _Obra de arte, Pintura, Escultura e Museu_.

  * Diagrama de classe:
   ![Diagrama Museu](https://i.imgur.com/niUuXsV.png)

O projeto teve como objetivo principal desenvolver um sistema de gerenciamento de obras de arte de um Museu. Como apresentado no diagrama de classe o Museu possuí duas categorias de obras - pinturas e esculturas - que compartilham algumas características em comum: título, artista, material e ano de criação.

**Classe ObraDeArte**

```c++
#ifndef OBRADEARTE_H
#define OBRADEARTE_H

#include <iostream>
#include <string>
using namespace std;

namespace catalogo {

    class ObraDeArte {
    public:     
        // Constantes estáticas para facilitar o entendimento
        static const int PINTURA = 1;
        static const int ESCULTURA = 2;
        
        // Construtor
        ObraDeArte(string titulo, string artista, string material, int ano)
        : titulo(titulo), artista(artista), material(material), ano(ano) {
        }
        
        // Destrutor
        virtual ~ObraDeArte() {
        }
        
        // Funções abstratas (obriga os filhos a implementarem)
        virtual int getCategoria() = 0;
        virtual void imprimeFicha() = 0;

        // Geters e Seters para atributos privados de ObraDeArte
        void setTitulo(string titulo) {
            this->titulo = titulo;
        }
        
        string getTitulo() {
            return titulo;
        }

        void setArtista(string artista) {
            this->artista = artista;
        }

        string getArtista() {
            return artista;
        }

        void setMaterial(string material) {
            this->material = material;
        }

        string getMaterial() {
            return material;
        }

        void setAno(int ano) {
            this->ano = ano;
        }

        int getAno() {
            return ano;
        }

        // Compara o ano, se os anos forem iguais compara o título
        static bool compAno(ObraDeArte* obra1, ObraDeArte* obra2) {
            if (obra1->getAno() == obra1->getAno()) {
                return compTitulo(obra1, obra2);
            } else {
                return obra1->ano < obra2->ano;
            }
        }
        
        // Compara o título
        static bool compTitulo (ObraDeArte* obra1, ObraDeArte* obra2) {            
            return obra1->titulo < obra2->titulo;
        }
        
    private:
        string titulo;
        string artista;
        string material;
        int ano;
    };

}

#endif /* OBRADEARTE_H */
```

Essa classe possuí duas constantes estáticas: **PINTURA** e **ESCULTURA**. Estes atributos são úteis pois podem funcionar como um #DEFINE, contudo com um pouco mais de "classe" permitindo usar PINTURA e ESCULTURA (constantes) direto nos métodos em que desejámos diferenciar cada uma e ainda mantendo o aspecto do tipo inteiro.

Os métodos
```c++
virtual int getCategoria() = 0;
virtual void imprimeFicha() = 0;
```
são virtuais e fazem com que os herdeiros desta classe sejem obrigados a implementar ambos os métodos. (isso também faz com que a classe se torne abstrata e a mesma não possa ser instânciada).

**compAno** e **compTitulo** são métodos somente feitos para comparação e são estáticos para serem usados sem instâncias ("Pertecem a classe"). O objetivo da construção das duas é a utilização no sort da biblioteca <algorithm>.


**Classe Escultura e Pintura**

As duas classes são estritamente parecidas (e por isso ambas compartilham atributos de ObraDeArte) tendo a principal diferença em seu atributo privado e consequentemente em imprimeFicha() e getCategoria().

  * Escultura:
     ```c++
        #ifndef ESCULTURA_H
        #define ESCULTURA_H

        #include "ObraDeArte.h"

        namespace catalogo {

        class Escultura : public ObraDeArte {
        public:
        // Construtor
        Escultura(string titulo, string artista, string material, int ano, double altura)
        : ObraDeArte(titulo, artista, material, ano), altura(altura) {
        }
        // Destrutor
        ~Escultura() {
        }
        
        // Retorna categoria
        int getCategoria() {
            return ObraDeArte::ESCULTURA;
        }

        // Abstrata no Pai, imprime ficha da Escultura
        void imprimeFicha() {
            cout << "Categoria: Escultura" << endl;
            cout << "Título: " << ObraDeArte::getTitulo() << endl;
            cout << "Artista: " << ObraDeArte::getArtista() << endl;
            cout << "Material: " << ObraDeArte::getMaterial() << endl;
            cout << "Ano: " << ObraDeArte::getAno() << endl;
            cout << "Altura: " << altura << endl;
        }
        
        // Set e Get exclusivo de Escultura
        void setAltura(double altura) {
            this->altura = altura;
        }
        
        double getAltura() {
            return altura;
        }
        
        private:
          double altura;
        };

        }

        #endif /* ESCULTURA_H */
     ```

  * Pintura:
     ```c++
        #ifndef PINTURA_H
        #define PINTURA_H

        #include "ObraDeArte.h"

        namespace catalogo {

        class Pintura : public ObraDeArte {
        public:
        // Construtor
        Pintura(string titulo, string artista, string material, int ano, string tipo)
        : ObraDeArte(titulo, artista, material, ano), tipo(tipo) {
        }
        
        // Destrutor
        ~Pintura() {
        }

        // Retorna categoria
        int getCategoria() {
            return ObraDeArte::PINTURA;
        }

        // Abstrata no Pai, imprime ficha da Pintura
        void imprimeFicha() {
            cout << "Categoria: Pintura" << endl;
            cout << "Título: " << ObraDeArte::getTitulo() << endl;
            cout << "Artista: " << ObraDeArte::getArtista() << endl;
            cout << "Material: " << ObraDeArte::getMaterial() << endl;
            cout << "Ano: " << ObraDeArte::getAno() << endl;
            cout << "Tipo: " << tipo << endl;
        }

        // Set e Get exclusivo de Pintura
        void setTipo(string tipo) {
            this->tipo = tipo;
        }

        string getTipo() {
            return tipo;
        }
        private:
           string tipo;
        };

        }

        #endif /* PINTURA_H */
     ```


**Museu**

Museu é a - praticamente - a classe principal do projeto. Nela está incluido as bibliotecas <algorithm> e <vector> que irão permitir a utilização facilitada de um 'vetor' para as obras disponíveis no Museu e para ordena-lo de acordo com os métodos de comparação feitos em _ObraDeArte_.

```c++
#ifndef MUSEU_H
#define MUSEU_H

#include "ObraDeArte.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

namespace catalogo {
    class Museu {
    public:
        // Construtor
        Museu(string nome) : nome(nome) { 
        }
        
        // Destrutor
        ~Museu() {
        }
        
        // Função para adicionar obra a um determinado museu
        bool adicionaObra(ObraDeArte* obra) {
            for (int i = 0; i < catalogo.size(); i++) { // Verifica se a Obra já está no catálogo
                if (catalogo[i] == obra) {
                    return 0; // Retorna 0 caso já exista a obra
                }
            }
            catalogo.push_back(obra); // Adiciona a obra na última posição do catálogo
            return 1; // Obra adicionada com sucesso
        }

        // Função para remover obras do catálogo
        bool removeObra(string titulo) {
            for (int i = 0; i < catalogo.size(); i++) { // Percorre o catálogo
                ObraDeArte* obra = catalogo[i];
                // Se o título buscado for encontrado no catálogo, remove a obra e retorna 1 (operação bem sucedida)
                if (obra->getTitulo() == titulo) {
                    catalogo.erase(catalogo.begin() + i);
                    return 1;
                }
            }
            return 0; // Caso a obra não seja encontrada
        }

        // Função para retornar uma obra
        ObraDeArte* obtemObra(string titulo) {
            // Percorre o catálogo em busca da obra
            for (int i = 0; i < catalogo.size(); i++) {
                ObraDeArte* obra = catalogo[i];
                if (obra->getTitulo() == titulo) {
                    return obra; // Se achar retorna a obra
                }
            }
            return NULL; // Se não retorna NULL
        }

        // Devolve o tamanho do catálogo
        int qtdeObras() {
            return catalogo.size();
        }

        // Devolve a quantidade de obras de determinada categoria
        int qtdeCategoria(int categoria) {
            int cont = 0;
            // Percorre o catálogo
            for (int i = 0; i < catalogo.size(); i++) {
                ObraDeArte* obra = catalogo[i];
                // Se for a obra do tipo da categoria que deseja contar soma-se um ao contador
                if (obra->getCategoria() == categoria) {
                    cont++;
                }
            }
            return cont;
        }

        // Devolve quantidade de pinturas
        int qtdePinturas() {
            return qtdeCategoria(ObraDeArte::PINTURA);
        }

        // Devolve quantidade de esculturas
        int qtdeEsculturas() {
            return qtdeCategoria(ObraDeArte::ESCULTURA);
        }

        // Imprime todo catálogo de um museu
        void imprime() {
            // Se existir obras do catálogo
            if (catalogo.size() > 0) {
                vector<ObraDeArte*> copia = catalogo; // Copia para um novo vector
                sort(copia.begin(), copia.end(), ObraDeArte::compAno); // Ordena as obras
                // Percorre imprimindo o vetor ordenado
                for (int i = 0; i < copia.size(); i++) {
                    copia[i]->imprimeFicha();
                }
                cout << endl;
            }
        }

        // Imprime analogamente a função acima, porém somente determinada categoria
        void imprimePorCategoria(int categoria) {
            // Se existir obras da categoria desejada
            if (qtdeCategoria(categoria) > 0) {
                vector<ObraDeArte*> copia = catalogo; // Copia para vector auxiliar
                sort(copia.begin(), copia.end(), ObraDeArte::compAno); // Ordena o auxiliar
                // Percorre o vetor
                for (int i = 0; i < copia.size(); i++) {
                    // Imprime somente se for da categoria desejada
                    if (copia[i]->getCategoria() == categoria) { 
                        copia[i]->imprimeFicha();
                    }
                }
                cout << endl;
            }
        }

    private:
        string nome;
        vector<ObraDeArte*> catalogo; // Vetor de obras
    };
}

#endif /* MUSEU_H */

```

É interessante perceber que temos _vector<ObraDeArte*> catalogo;_ diretamente no private para que tenhamos salvo, dessa forma, o vetor de todas as ObrasDeArte* presente no museu (é um vetor de ponteiros).

Utilizando vector:

A biblioteca foi utilizada em algumas situações. Podemos verificar, primeiramente, o método **adicionaObra(ObraDeArte* obra)**:
```c++
bool adicionaObra(ObraDeArte* obra) {
    for (int i = 0; i < catalogo.size(); i++) { // Verifica se a Obra já está no catálogo
       if (catalogo[i] == obra) {
          return 0; // Retorna 0 caso já exista a obra
       }
    }
    catalogo.push_back(obra); // Adiciona a obra na última posição do catálogo
    return 1; // Obra adicionada com sucesso
}
```

  * _catalogo.size()_ dentro dos parâmetros do for permite que tenhamos o tamanho atual do vector catalogo.
  * A verificação é utilizada para retornar FALSE caso já exista a obra a ser inserida dentro do catalogo.
  * _catalogo.push(obra);_ adciona a obra recebida como parâmetro na última posição do vector catalogo.


Em **bool removeObra(string titulo)** é feito algo muito parecido, porém, neste caso é buscado uma obra com mesmo título dentro do catálogo.
```c++
bool removeObra(string titulo) {
   for (int i = 0; i < catalogo.size(); i++) { // Percorre o catálogo
      ObraDeArte* obra = catalogo[i];
      // Se o título buscado for encontrado no catálogo, remove a obra e retorna 1 (operação bem sucedida)
      if (obra->getTitulo() == titulo) {
         catalogo.erase(catalogo.begin() + i);
         return 1;
      }
   }
   return 0; // Caso a obra não seja encontrada
}
```

  * _catalogo.erase(catalogo.begin() + i)_ é declarada exclusivamente para excluir um determinado objeto do vetor (em uma posição determinada por _catalogo.begin() + i_, - acredito que essa parte funciona como a soma de um endereço - endereço inicial + n posições adiante).

Utilizando algorithm (sort):
```c++
void imprime() {
   // Se existir obras do catálogo
   if (catalogo.size() > 0) {
      vector<ObraDeArte*> copia = catalogo; // Copia para um novo vector
      sort(copia.begin(), copia.end(), ObraDeArte::compAno); // Ordena as obras
      // Percorre imprimindo o vetor ordenado
      for (int i = 0; i < copia.size(); i++) {
         copia[i]->imprimeFicha();
      }
      cout << endl;
   }
}
```

  *  Após ser criado um vector cópia de catalogo o mesmo foi ordenado com _sort(copia.begin(), copia.end(), ObraDeArte::compAno)_ que recebe o inicio, o final e o meio de ordenação (uma função com retorno boleano - nesse caso o compAno feito em ObraDeArte - para determinar a ordem) e foi impresso em ordem logo em seguida.


A **main.c** foi desenvolvida e disponibilizada pelo professor para teste das classes desenvolvidas e de todo o funcionamento dos métodos implementados.

 
