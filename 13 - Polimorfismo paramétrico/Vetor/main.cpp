
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;

void remove(vector<int>& v, int el) {
    vector<int>::iterator it;
    it = find(v.begin(), v.end(), el);

    if (it != v.end()) {
        v.erase(it);
    }
}

bool encontra(vector<int> v, int el) {

    vector<int>::iterator it;
    it = find(v.begin(), v.end(), el);

    if (it != v.end()) {
        return true;
    } else {
        return false;
    }
}

void imprime(vector<int> v) {
    for (int i = 1; i <= v.size(); i++) {
        cout << setw(2) << setfill('0') << v[i - 1];
        if (i % 10 == 0 || i == v.size()) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    cout << endl;
}

int main(int argc, char** argv) {

    srand(time(NULL));

    /* vector<int> vetor;
     * 
    for (int i = 0; i < 50; i++) {
        int segredo = rand() % 50 + 1;
        vetor.push_back(segredo);
    } */

    vector<int> vetor(50);

    for (int i = 0; i < 50; i++) {
        int segredo;
        do {
            segredo = rand() % 50 + 1;
        } while (encontra(vetor, segredo));
        vetor[i] = segredo;
    }

    imprime(vetor);

    sort(vetor.begin(), vetor.end());

    imprime(vetor);

    vetor.erase(vetor.begin() + 22);

    remove(vetor, 7);
    remove(vetor, 38);
    remove(vetor, 5);
    remove(vetor, 17);

    imprime(vetor);

    for (int i = 0; i < 5; i++) {
        vetor.pop_back();
    }

    imprime(vetor);

    vetor.erase(vetor.end() - 10, vetor.end());

    imprime(vetor);

    return 0;
}