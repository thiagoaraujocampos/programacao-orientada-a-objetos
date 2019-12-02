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

