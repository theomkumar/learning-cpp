#include<iostream>
using namespace std;

class Hero 
{
    public:
    //destructor
    ~Hero() //tilde sign (~)
    {
        cout <<" Destructor called! \n";
    }
};

int main() 
{
    //static allocation -> Destructor is automatically called
    Hero a;

    //dynamic -> Manual call needed(delete)
    Hero *b = new Hero(); 
    delete b;

    return 0;
}