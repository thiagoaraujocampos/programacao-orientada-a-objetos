#include "Coordenador.h"

namespace poo {
    Coordenador::Coordenador(string nome, int cpf, float salario, string curso) : Professor(nome, cpf, salario), curso(curso){
        
    }
    
    float Coordenador::getSalario() const { 
        return Professor::getSalario() + 2000;
    }
    
    void Coordenador::imprime(){
        Professor::imprime();
        cout << "Salário com Bonificação: " << Coordenador::getSalario() << endl;
        cout << "Curso: " << curso << endl; 
    }
}