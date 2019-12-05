#ifndef PONTO2D_H
#define PONTO2D_H

class Ponto2D {
public:
    Ponto2D(float x, float y); // construtor
    virtual ~Ponto2D(); // destrutor
    
    float distancia(Ponto2D p); // método da classe
private:
    float x, y; // atributos da classe
};

#endif /* PONTO2D_H */

