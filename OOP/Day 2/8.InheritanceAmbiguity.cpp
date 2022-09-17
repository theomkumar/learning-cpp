//scope resolution operator -> :: is used to resolve ambiguity
#include<iostream>
using namespace std;

class A {
    public:

    void func() {
        cout <<"I am A \n";
    }
};
class B {
    public:

    void func() {
        cout <<"I am B \n";
    }
};
class C: public A, public B {
    public:
    void func() {
        cout << "I am C \n";
    }
};

int main() 
{
    C obj;
    //obj.func(); ambiguous as func is present in both base class (A and B)
    obj.A::func();
    obj.B::func();

    return 0;
}