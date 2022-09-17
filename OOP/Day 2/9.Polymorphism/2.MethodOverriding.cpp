/* Runtime polymorphism (Dynamic Polymorphism)
 >Method(function) overriding 
    > possible through inheritance only
    > method of parent and child class must have same name and parameters.
*/
#include<iostream>
using namespace std;

class Animal {
    public:
    void speak () {
        cout <<"speaking \n";
    }
};
//we are doing method(function overriding here)
//if speak's implementation isn't present in child's class then implementation from paraent class will be used

class Dog : public Animal {
    public:
    void speak () {
        cout <<"Barking \n";
    }
};

int main() 
{
    Dog obj;
    obj.speak();
    
    return 0;
}