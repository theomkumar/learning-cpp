#include<iostream>
using namespace std;
//refer code studio or gfg
/*
    Note: private data member of any class cannot be inherited.  
   ||parent class||         ||child class||                    ||result||
        public           public/private/protected      public/private/protected
        proteced         public/private/protected      protected/private/protected
        private                    any                        Not Accessible
*/
//parent/super class/base class
class Human 
{
    public:
        int height;
        int weight;
        int age;

    public:
        int getAge() {
            return this->age;
        }

        void setWeight(int weight) {
            this->weight = weight;
        }
};
// Child / sub-class
class Male: public Human
{
    public:
    string color;

    void sleep() 
    {
        cout <<"Male Sleeping" <<'\n';
    }
    
};

int main() 
{
    Male object1;
    cout << object1.age << endl;
    cout << object1.height << endl;
    cout << object1.weight << endl;
    
    cout << object1.color << endl;

    object1.setWeight(76);
    cout << object1.weight << endl;
      
    object1.sleep();
    return 0;
}