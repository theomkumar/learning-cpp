#include<iostream>
#include<string>
using namespace std;

/* READ IT:

Think of '*' as boundary, whatever is in contact with const is meant to be constant
eg1: int const *ptr -> int const |*| ptr -> (int const),(ptr)
eg2: const int *ptr -> const int |*| ptr -> (const int),(ptr)
eg3: int * const ptr; -> int |*| const ptr -> (int),(const ptr)

eg1,2
-> const is in contact with int only, and ptr is separated thanks to boundry '*', this means:
1. we can't modify int values 
2. we can modify pointer

eg3
-> const is in contact with ptr while int is separated, this means:
1. we can't modify pointer.
2. we can modify int values.

*/

int main()
{
//**************************************************************************
    int age = 40;
    
    //eg1.

    //int const *ptr = new int; // (int const) (ptr)
    const int *ptr = new int; // (const int) (ptr)

    //*ptr = 12; const is in contact with int
    ptr = &age;

    //eg2
    int *const ptr2 = new int; // (int) (const ptr2)
    *ptr2 = 12;
    // ptr2 = &age;//const is in contact with pointer 'ptr2'

    //eg3
    const int *const ptr3 = new int; // (const int) (const ptr3)
    // *ptr3 = 12;
    // ptr3 = &age;

//****************************************************************************
    const int max_age = 90;
    cout <<"ADDRESS OF MAX_AGE: "<<&max_age <<'\n';

//    int *maxAge = &max_age; //a value of type "const int *" cannot be used to initialize an entity of type "int 
    int *maxAge = (int*)&max_age;

    cout << "Address stored in ptr: " << maxAge <<'\n';
    cout <<"pointer dereference before : " << *maxAge <<'\n';

    *maxAge = 101;

    cout <<"Pointer dereference after: " << *maxAge <<'\n';
    cout <<"max_age: " << max_age <<'\n';




}