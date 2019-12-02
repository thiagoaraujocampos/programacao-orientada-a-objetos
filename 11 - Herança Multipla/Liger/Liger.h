#ifndef LIGER_H
#define LIGER_H

#include "Lion.h"
#include "Tiger.h"

class Liger : public Lion, public Tiger {
public:
    Liger(int weight);
    virtual ~Liger();
    int getWeight();
};

#endif /* LIGER_H */

