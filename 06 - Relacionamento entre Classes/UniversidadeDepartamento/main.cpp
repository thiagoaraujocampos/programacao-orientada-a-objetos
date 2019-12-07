#include "Universidade.h"

int main() {

    Universidade *ufscar = new Universidade("UFSCar");

    cout << "-------------------------------" << endl;

    ufscar->adicionaDepartamento("Computação", "DC");
    ufscar->adicionaDepartamento("Matemática", "DM");
    ufscar->adicionaDepartamento("Física", "DF");

    cout << "-------------------------------" << endl;
    
    ufscar->imprime();

    cout << "-------------------------------" << endl;
    
    ufscar->removeDepartamento("DM");

    ufscar->imprime();

    cout << "-------------------------------" << endl;
    
    delete ufscar;

    return 0;
}

