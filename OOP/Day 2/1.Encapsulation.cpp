#include<iostream>
using namespace std;

class Student {
    //all the properties is encapsulated (private)
    private:
        string name;
        int age;
        int height;
    //we made this read only by using getter.
    public:
    int getAge()
    {
        return this -> age;
    }

};

int main() 
{
    Student first;
    cout << first.getAge();
    return 0;
}