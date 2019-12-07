#include "Data.h"

int main() {
        
    Data D1;
    Data D2;
    
    cout << "1a Data: ";
    cin >> D1;
    cout << "2a Data: ";
    cin >> D2;
    
    if (D1 > D2) {
        cout << D1 << " é mais recente que " << D2 << endl;
    } else if (D1 < D2) {
        cout << D2 << " é mais recente que " << D1 << endl;
    } else {
        cout << D1 << " é igual a " << D2 << endl;
    } 
    
    return 0;
}