#include<iostream>
#include<cstring>

using namespace std;
/*
NOTE: this data type belongs to class.(it can work without object) 
Initialise -> datatype class_name :: fieldName = value;

NOTE: 
1. static functions doesn't have 'this' keyword as this keyword -> pointer to current object, and static belongs to class.
2. Static function can only access static member.

*/


class Hero
{
  //properties
    private:
    int health;

    public:
    char *name;
    char level;
    static int timeToComplete;

    static void print()
    {
        cout <<"static Fuction called! time2complete : "<< timeToComplete <<'\n';
    }


};
//declaration
int Hero::timeToComplete = 5;
 
int main() 
{
    //ideally 
    //no need of creating object.
    cout << Hero::timeToComplete << '\n';
    Hero::print() ;

    //we can also access after creating object.
    cout <<"using object \n";
    Hero A;
    A.timeToComplete = 10;
    cout << A.timeToComplete;
    return 0;
}