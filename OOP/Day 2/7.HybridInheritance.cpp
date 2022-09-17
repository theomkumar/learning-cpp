#include<iostream>
//basically using multiple types of inheritance 
using namespace std;
/*                A   M
                /   \ |
               /     \|    
              B       C
*/
class A {
    public:
    int age;
    int weight;
    char *name;

    void printA() {
        cout <<"inside A \n";
    }
}; 

class B: public A {
    public:
    void printB() {
        cout << "inside B \n";
    }
};



class M {
    public:
    void print() {
        cout <<"inside M \n";
    }
};

class C:public A, public M{
    public:
    void printC() {
        cout <<"inside C \n";
    }
};

int main() 
{

    
    return 0;
}