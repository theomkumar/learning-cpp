//compilation error, as the default constructor is available only till the point we don't create our own constructor. there exist no constuctor of Class_name() type, we have parameterized constructor here so we need to pass one parameter here.

#include <iostream> 
using namespace std; //creating class 
class Student {
    public:
    char name;
    int rollNo;
 
    //parameterized constructor
    Student(int num){
        rollNo = num;
    }
    void print() {
        cout << name << " " << rollNo;
    }
};
int main()
{
    Student s;
    s.name = 'A';
    s.rollNo = 15;
    s.print();
}