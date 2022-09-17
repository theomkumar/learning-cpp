#include<iostream>
using namespace std;
//In multiple inheritance, a class can inherit more than one class. This means that a single child class can have multiple parent classes in this type of inheritance.

//here Class Hybrid inherited Human and Animal thus multiple inheritance.
class Animal 
{
    public:
    int age;
    int weight;

    public:
    void bark() {
        cout << "MMmWooo grr...! WooOO...! whuff whuff. Rrrrrr.  \n";
    }
};
class Human {
    public:
    string color;

    public:
    void speak() {
        cout <<"Speaking \n";
    }
};
//multiple Inheritance
class Hybrid: public Animal, public Human 
{
    
};

int main() 
{
    Hybrid obj1; 
    obj1.speak();
    obj1.bark();

    return 0;
}
