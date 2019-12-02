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

