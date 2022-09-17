#include<iostream>
using namespace std;

class Hero 
{
    public:
    int Health;
    char Level;

    Hero(int Health, char Level)
    {
        this->Health = Health;
        this->Level = Level;
    }
    void print()
    {
        cout << "Health: " << this -> Health <<' ';
        cout << "Level: " << this -> Level <<'\n';
    }
};

int main() 
{
    Hero Hero1(22, 'D');
    Hero Hero2(58, 'B');

    cout <<"Hero1: ";
    Hero1.print();

    cout <<"Hero2: ";
    Hero2.print();

    //Copy Assignment Operator
    Hero1 = Hero2; // == Hero1.Health = Hero1.Health and Hero1.Level = Hero2.Level. 
    cout <<"Hero1: ";
    Hero1.print();
    
    return 0;
} 