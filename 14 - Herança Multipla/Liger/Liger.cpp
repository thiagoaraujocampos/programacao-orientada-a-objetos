#include "Liger.h"

Liger::Liger(int weight) :
Lion(weight), Tiger(weight) {
}

Liger::~Liger() {
}

int Liger::getWeight() {
    return Tiger::getWeight();
}
