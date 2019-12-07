#include "Time.h"

int main() {
    
    Jogador *prass = new Jogador("Fernando Prass", 40, "Goleiro");
    Jogador *guerra = new Jogador("Alejando Guerra", 33, "Meia");
    Jogador *borja = new Jogador("Miguel Borja", 25, "Atacante");
    
    Time *time = new Time("Palmeiras");
    
    time->adicionaJogador(1, prass);
    time->adicionaJogador(10, guerra);
    time->adicionaJogador(9, borja);
    
    time->imprime();
    
    time->removeJogador(10);
    
    time->imprime();
    
    delete time;
    
    delete borja;
    delete guerra;
    delete prass;
    
    return 0;
}

