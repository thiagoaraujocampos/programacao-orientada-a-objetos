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

