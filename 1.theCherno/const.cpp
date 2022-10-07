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
    const int age = 90;

    // case 1 : const int* a == int const * a

    const int* a = new int; // this makes this pointer read only -> i.e content of pointer can't be changed but the address pointer is pointing to can be changed


//    *a = 2; //changing content of the pointer is not allowed!

   a = (int*)&age; //changing what pointer is pointing to
    cout << *a;

    //case 2: int *const a : pointer's content can be changed but not the address it is pointing to.
    const int* x = new int;
    // *x = 12; not allowed
    x = &age; //allowed

    int *const b = new int;
    *b = 122; //can change
    // b = &x; //can't change

}