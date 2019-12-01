#ifndef ANFIBIO_H
#define ANFIBIO_H

#include "Barco.h"
#include "Carro.h"

class Anfibio : public Barco, public Carro {
public:
    Anfibio();
    virtual ~Anfibio();
private:

};

#endif /* ANFIBIO_H */

