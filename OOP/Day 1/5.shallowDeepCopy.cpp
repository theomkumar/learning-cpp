#include<iostream>
#include<cstring>

using namespace std;
/*
    Default copy constructor -> Shallow Copy  [same memory different name eg. hero1 hero2]
*/

class Hero
{
  //properties
  private:
  int health;

  public:
  char *name;
  char level;

// Default constructor
  Hero() {
    cout << "default constructor called " << '\n';
    name = new char[100];
  }

  //Paramerterised Constructor 
  Hero(int health, char level) {
    this->health = health;
    this-> level = level;
  }
  
  // copy constructor (manually made)
  
  //deep copy -> coz we made new array and copied value rather than referencing the same memory block(shallow copy) , in deep copy we make separate memory block.
  Hero(Hero &temp){
    char *ch = new char[strlen(temp.name)+1];
    strcpy(ch, temp.name);
    this->name = ch;
    
    cout <<"copy constructor called "<<'\n';
    this->health = temp.health; //used this to avoid ambiguity
    this->level = temp.level;
  }
  void print() 
  {
    cout <<"name: " << this->name <<" ,";
    cout << "health: " << this->health <<" ,";
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
  void setName(char name[]) {
    strcpy(this->name, name);
  }
};

int main() 
{
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[4] = "Omi";
    hero1.setName(name);
    
    hero1.print();
    //use default copy constructor - shallow copy
    Hero hero2 = hero1; //Hero2(hero1);
    hero2.print();

    hero1.name[0] = 'B';
    hero1.setHealth(122);
    hero1.print();

    hero2.print();
    return 0;
}