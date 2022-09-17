/*
The standard does not allow objects (and classes thereof) of size 0, since that would make it possible for two distinct objects to have the same memory address. That's why even empty classes must have a size of (at least) 1.

The size of an empty class is not zero. It is 1 byte generally. It is nonzero to ensure that the two different objects will have different addresses.
*/
#include<iostream>
using namespace std;

class empty_class {

};

class derived:public empty_class {

};

class derived2:public derived {

};

int main() 
{
    cout << sizeof(empty_class) << "\n";
    cout << sizeof(derived2) << "\n";

    return 0;
}