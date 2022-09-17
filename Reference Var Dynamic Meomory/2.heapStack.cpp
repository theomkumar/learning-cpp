#include<iostream>

using namespace std;

int main() {
    //heap - dynamic memory allocation- mem. allocation during runtime
    //stack - static memory allocation- allocation during compile time


    //heap
    new char; //it's basically an adrress.

    //heap initialize
    char * ch = new char;//total memory of this statement
                         // 8(pointer) + 1(char) = 9.

    char stack = 'a'; // total memory = 1.

/* 
   //case1- stack clears memory automatically after '}' here.
    while (true) {
        int i = 5;
    }

   //case2- here pointer is cleared coz it's using stack but
   // heap keeps on piling ultimately it'll exhaust memory and crash if in infinite loop.

    while (true) {
        int *i = new int; //total memory of this statement = 8+4, out of which 8(pointer) 
                         // is cleared every loop coz pointer uses stack.
    }
*/
    return 0;
}