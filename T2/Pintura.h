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

