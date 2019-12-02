#include <iostream>
#include "Liger.h"

using namespace std;

int main(int argc, char** argv) {

    Liger lg(100);

    /*COMPILE ERROR, the code below will not get past
    any C++ compiler */

    int weight = lg.getWeight();

    cout << weight << endl;
    
    return 0;
}

