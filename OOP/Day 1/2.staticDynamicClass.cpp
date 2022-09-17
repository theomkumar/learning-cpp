#include<iostream>
using namespace std;


class Hero
{
  //properties
  private:
  int health;

  public:
  char level;

  //creating getter 
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
    //static allocation
    Hero a;
    cout <<"Size of a: "<< sizeof(a);

    a.setHealth(94); //bcoz its private
    a.level = 'B'; //a.setLevel('B');
    
    cout <<"Level: " << a.level <<" ";
    cout <<"Health: "<< a.getHealth() <<"\n";

    //dynamically allocation
    Hero *b = new Hero;

    (*b).level = 'A'; //b->setLevel('A'); (*b).setLevel('A');
    (*b).setHealth(45); //b->setHealth(45);

    cout <<"Level: " << (*b).level <<" ";
    cout <<"Health: "<< (*b).getHealth() <<"\n";
    //Alternatively we can us arrow
    cout <<"Level: " << b->level <<" ";
    cout <<"Health: "<< b->getHealth() <<"\n";

    return 0;
}