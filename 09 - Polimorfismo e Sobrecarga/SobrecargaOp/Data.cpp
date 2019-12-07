#include "Data.h"

int Data::compare(Data outra) const {
    if (this->ano != outra.ano) {
        return this->ano - outra.ano;
    } else if (this->mes != outra.mes) {
        return this->mes - outra.mes;
    } else return this->dia - outra.dia;
}

bool Data::operator<(const Data& right) const {
    return compare(right) < 0;
}

bool Data::operator<=(const Data& right) const {
    return compare(right) <= 0;
}

bool Data::operator>(const Data& right) const {
    return compare(right) > 0;
}

bool Data::operator>=(const Data& right) const {
    return compare(right) >= 0;
}

bool Data::operator==(const Data& right) const {
    return compare(right) == 0;
}

bool Data::operator!=(const Data& right) const {
    return compare(right) != 0;
}

ostream& operator<<(ostream& os, const Data& obj) {
    os << setfill('0') << setw(2) << obj.dia << "/";
    os << setfill('0') << setw(2) << obj.mes << "/";
    os << setfill('0') << setw(4) << obj.ano;
    return os;
}

istream& operator>>(istream& is, Data& obj) {
    char c; // usado para ignorar a barra "/"
    is >> obj.dia >> c >> obj.mes >> c >> obj.ano;
    return is;
}
