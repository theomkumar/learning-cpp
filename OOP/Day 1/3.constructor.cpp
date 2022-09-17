#include<iostream>
using namespace std;
/*
    DEFAULT constructor -> doesn't need any parameters/arguments to run. Syntax to define a Default Constructor: Class_name()

    PARAMETERIZED Constructor -> A constructor with parameters is known as a parameterized constructor.
    Syntax to define a parameterized Constructor: Class_name(parameters)

->after making our own constructor the default constructor is gone.

-> 'this' pointer stores address of current object, and basically this pointer points to the class's current object.this resolves ambiguity esp. when same name is used for local variable and data member e.g line 31

*/
class Hero
{
  //properties
  private:
  int health;

  public:
  char level;
// Default constructor
  Hero() {
    cout <<"Default constructor called "<<'\n';
  }

  //Paramerterised Constructor  
  Hero(int health) {
    cout <<"this pointer address-> "<<this<<'\n';
    this->health = health;
  }

  Hero(int health, char level) {
    this->health = health;
    this-> level = level;
  }

  void printLevel() 
  {
    cout << "level: " << level <<'\n';
  }
  
  int getHealth() {
    return health;
  }

  char getLevel() {
    return level;
  }
  // setter
  void setHealth(int h) {
    health = h;
  }
  void setLevel(char ch) {
    level = ch;
  }
  
};

int main() 
{
//  Object created statically
    Hero defaultConstructor;
    Hero King(12); //parameterized constructor
//  King.getHealth();
//  cout <<"address of King: " << &King <<'\n';
//  cout <<"health: " << King.getHealth()<<'\n'; 

    //dynamically
    Hero *check = new Hero;//new Hero; or () -> default constructor called
    Hero *h = new Hero(33); //parameterized constructor called
    cout << "new health: " << h->getHealth() << endl;

    Hero temp(22, 'B');
    temp.printLevel();


   
    return 0;
}