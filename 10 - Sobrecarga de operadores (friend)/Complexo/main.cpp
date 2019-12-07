#include "Complexo.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

    Complexo c1(2,2);
    Complexo c2(3,5);
    Complexo c3(1,2);
    Complexo c4(3,4);
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c1 + c2 << endl;
    cout << c1 - c2 << endl;
    cout << c3 * c4 << endl;
    cout << c3 / c4 << endl;
    
    return 0;
}

