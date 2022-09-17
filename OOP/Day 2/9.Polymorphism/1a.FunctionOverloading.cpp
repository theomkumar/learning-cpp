/* PolyMorphism (many form)
 2 -> types :
 (i) Compile Time Polymorphism(static polymorphism)
        ->Function Overloading
        ->Operator Overloading
 (ii) Runtime Polymorphism(dynamic polymorphism)
        ->Virtual Function

//function overloading(same function name with different parameters) by :
    (i)different number of argument 
    (ii)different types of argument
//function cannot be overloaded by simply changing the return type. (e.g-> changing void funct() to int func() )
*/

#include<iostream>
using namespace std;

class A {
    public:
    void sayHello() {
        cout <<"Hello \n";
    }
    // changing parameter 
    void sayHello(string name) {
        cout <<"Hello " << name <<"\n";
    }
    //changing type of argument 
    void sayHello(char name) {
        cout <<"Hello " << name <<"\n";
    }
};

int main() 
{
    A obj;
    obj.sayHello();
    obj.sayHello("Omi");
    obj.sayHello('W');
    
    return 0;
}