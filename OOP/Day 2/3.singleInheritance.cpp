#include<iostream>
using namespace std;

class Animal 
{
    public:
    int age;
    int weigtht;

    public:
    void bark() {
        cout << "MMmWooo grr...! WooOO...! whuff whuff. Rrrrrr.  \n";
    }
};

class Dog: public Animal 
{
    
};

int main() 
{
    Animal dog;
    dog.bark();
    
    return 0;
}