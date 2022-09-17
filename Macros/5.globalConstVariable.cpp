#include<iostream>
using namespace std;

//global variable -> considered bad practice coz its
// value can be changed by any function.


//global variable.
int score = 15;


//reference variable
void a(int& i) 
{
    cout<< score <<endl;
    cout << i << endl;
}

int main() {
    cout<<score<<endl; 
    int i = 5;
    a(i);

//constant variable -> can't be reassigned.
    const int c = 21;
    const int *ptr = &c; 

    int d = 13;

    //c++; error!

    cout<<c<<" "<<*ptr<<"\n";

    ptr = &d;

    cout<<*ptr<<endl;

    // error -> *ptr = 5; error.

    return 0;
}   