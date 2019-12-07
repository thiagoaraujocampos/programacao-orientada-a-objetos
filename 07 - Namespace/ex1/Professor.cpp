#include "Professor.h"

namespace poo {
    
    Professor::Professor(string nome, int cpf, float salario) : Pessoa(nome, cpf), salario(salario){
        
    }
    
    float Professor::getSalario() const {
        return salario;
    }
    
    void Professor::imprime() {
        Pessoa::imprime();
        cout << "Salario: " << Professor::getSalario() << endl; 
    }
}
