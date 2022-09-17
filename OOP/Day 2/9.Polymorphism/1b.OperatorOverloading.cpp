//eg. we want to substract using '+' operator
//syntax -> return_type operator+ (parameter i/p optional) {}

//https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/274159/offering/3757648
#include<iostream>
using namespace std;

class A {
    public:
    int a;
    int b;
    
    int add() {
        return a + b;
    }
    //overloading +
    void operator+ (A &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout <<"output "<< value2-value1 << '\n'; 
    }
    //overloading ();
    void operator() () {
        cout <<"I am Bracket " << this->a <<'\n';
    }
};

int main() 
{
    A obj1, obj2;
    obj1.a = 8;
    obj2.a = 12;

    obj1 + obj2; //
    obj1();

    return 0;
}