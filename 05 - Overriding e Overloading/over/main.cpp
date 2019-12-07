#include <cstdlib>
#include <iostream>
using namespace std;

class A {
public:
    virtual void m1() {
        cout << "m1() da Classe A" << endl;
    }
};

class B : public A {
public:
    void m1() {  //overiding
        cout << "m1() da Classe B" << endl;
    }
    void m1(int a) { //overloading
        cout << "m1(int) da Classe B" << endl;
    }
};

class C : public B {
public:
    void m1() {  //overiding
        cout << "m1() da Classe C" << endl;
    }
};

void func (A& obj) {
    obj.m1();
    B* objB = dynamic_cast<B*>(&obj);
    if (objB) {
        objB->m1(1);   
    }
}

int main(int argc, char** argv) {
    A a;
    B b;
    C c;
    func(a);
    func(b);
    func(c);
    return 0;
}

