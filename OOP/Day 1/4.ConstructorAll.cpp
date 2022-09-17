#include<iostream>
using namespace std;

class Hero
{
  private:
  int health;

  public:
  char level;
// Default constructor
  Hero() {
    cout <<"Default constructor called "<<'\n';
  }
  //Paramerterised Constructor 
  Hero(int health, char level) {
    cout <<"Parameterized Constructor called "<<'\n';
    this -> health = health;
    this -> level = level;
  }
  //copy constructor (manually made)
  Hero(Hero &temp){
    cout <<"copy constructor called "<<'\n';
    this -> health = temp.health; //used this to avoid ambiguity
    this -> level = temp.level;
  }
  void print() 
  {
    cout << "health: " << this->health <<'\n';
    cout << "level: " << level <<'\n';
  }
  //getter  
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
    Hero D; //default constructor invoke
    Hero S(70, 'C'); //parameterized constructor invoke

    S.print();

    //copy constructor will be created automatically 
    // but we can also manually create our own copy constructor line: 22
    Hero R(S); //or Hero R = Hero S, copy constructor invoke

    R.print();

   
    return 0;
}