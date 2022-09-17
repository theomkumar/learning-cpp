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

class GermanShepherd: public Dog
{

};

int main() 
{
    GermanShepherd JohnOlson;
    JohnOlson.bark();
    
    return 0;
}
