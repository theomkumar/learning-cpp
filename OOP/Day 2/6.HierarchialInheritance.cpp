// 'A' class is parent of 'B' and 'C'.
//In hierarchical inheritance, one class is a base class for more than one derived class.
#include<iostream>
using namespace std;

class A 
{
    public:
    void func1()
    {
        cout << "Inside func1 \n";
    }
};

class B: public A
{
    public:
    void func2()
    {
        cout << "Inside func2 \n";
    }

};

class C: public A
{
    public:
    void func3()
    {
        cout << "Inside func3 \n";
    }
};
int main() 
{
    A object1;
    object1.func1();

    B object2;
    object2.func1();
    object2.func2();

    C object3;
    object3.func1();
    object3.func3();

    
    return 0;
}