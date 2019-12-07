#include "DataHorario.h"

namespace poo {

    // Constrói DataHorario e verifica se a data é válida
    DataHorario::DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo) {
        if (dia <= 0 || dia >= 32 || (mes <= 0 || mes >= 13) || ano <= 0 || hora < 0 || minuto < 0 || minuto >= 60 || segundo < 0 || segundo >= 60) {
            this->dia = 1;
            this->mes = 1;
            this->ano = 1;
            this->hora = 1;
            this->minuto = 1;
            this->segundo = 1;
        } else {
            this->dia = dia;
            this->mes = mes;
            this->ano = ano;
            this->hora = hora;
            this->minuto = minuto;
            this->segundo = segundo;
        }
        cout << "Construtor: (" << this->dia << ", " << this->mes << ", " << this->ano << ")" << endl;
    }

    DataHorario::~DataHorario() {

    }

    // Compara as datas
    int DataHorario::compara(DataHorario &obj) {
        // Se todos os dados forem iguais
        if (obj.dia == dia && obj.mes == mes && obj.ano == ano && obj.hora == hora && obj.minuto == minuto && obj.segundo == segundo) {
            return 0;
        // Se a data corrente for maior que a data do parâmetro
        } else if ((ano > obj.ano) || (mes > obj.mes && ano == obj.ano) || (dia > obj.dia && mes == obj.mes && ano == obj.ano) || (hora > obj.hora && dia == obj.dia && mes == obj.mes && ano == obj.ano) || (minuto > obj.minuto && hora == obj.hora && dia == obj.dia && mes == obj.mes && ano == obj.ano) || (segundo > obj.segundo && minuto == obj.minuto && hora == obj.hora && dia == obj.dia && mes == obj.mes && ano == obj.ano)) {
            return 1;
         // Se a data corrente for menor que a data do parâmetro (última possibilidade)
        } else {
            return -1;
        }
    }

    // Get's
    
    int DataHorario::getDia() {
        return dia;
    }

    int DataHorario::getMes() {
        return mes;
    }

    int DataHorario::getAno() {
        return ano;
    }

    int DataHorario::getHora() {
        return hora;
    }

    int DataHorario::getMinuto() {
        return minuto;
    }

    int DataHorario::getSegundo() {
        return segundo;
    }

    void DataHorario::imprime(bool sistema) { // Imprime conforme o sistema escolhido (12 Horas ou 24 Horas)
        if (sistema) {
            if (hora > 12) { // Sistema 23 Horas
                printf("%02d/%02d/%02d %02d:%02d:%02d PM\n", dia, mes, ano, hora-12, minuto, segundo);
            } else {
                printf("%02d/%02d/%02d %02d:%02d:%02d AM\n", dia, mes, ano, hora, minuto, segundo);
            }
        } else { // Sistema 24 Horas
            printf("%02d/%02d/%02d %02d:%02d:%02d\n", dia, mes, ano, hora, minuto, segundo);
        }
    }

    void DataHorario::imprimePorExtenso() { // Imprime a data por extenso
        char meses[12][40] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
        printf("%02d de %s de %02d - %02d Horas, %02d Minutos e %02d Segundos.\n", dia, meses[mes-1], ano, hora, minuto, segundo);
    }
}