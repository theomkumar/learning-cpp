#include<iostream>
#include "Enemy.cpp"
using namespace std;
//Access modifier is private by default, //below public everthing can be accessed outside class until private is added.
//private can be directly accessed inside class only.
//protected can be directly accessed inside class and child class only.

//empty class allocates -> 1 byte for identification.
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
    //creation of object
    Hero Paul;
    cout <<"size of Paul: "<<sizeof(Paul)<<"\n"; //how 8? padding and greedy alignment read
    Enemy Tiger;

    Paul.setHealth(67);
    cout << "health of Paul: " << Paul.getHealth()<<"\n";
    // cout << "Level: "<< Paul.getLevel() << "\n";


    cout << "health of Tiger: " << Tiger.health<<"\n";
  //  cout <<sizeof(h1) << "\n";
    return 0;
}