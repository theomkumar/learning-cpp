#include<iostream>
//A ternary operator evaluates the test condition and executes a block of code based 
//on the result of the condition. Its syntax is condition ? expression1 : expression2;
// Here, condition is evaluated and. if condition is true , expression1 is executed, else expression 2 .

using namespace std;

#define MIN(a,b) ( a>b ? b:a)

int main() {
    int i = -12, j = -13;

    cout<<MIN(i,j); 

    return 0;
}