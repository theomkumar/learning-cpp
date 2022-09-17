// Inline functions are used to reduce the function calls overhead.
// Benefits : no memory usage + no function call overhead
//  For functions that are large and/or perform complex tasks, the overhead of the function call is usually insignificant compared to the amount of time the function takes to run. However, for small, commonly-used functions, the time needed to make the function call is often a lot more than the time needed to actually execute the function’s code. This overhead occurs for small functions because execution time of small function is less than the switching time.
//When the inline function is called whole code of the inline function gets inserted or substituted at the point of inline function call.
//This substitution is performed by the C++ compiler at compile time.

#include<iostream>
using namespace std;

inline int getMax( int& a, int& b) //it'll replace getMax(a,b) to (a>b) ? a : b;
{
    return (a>b) ? a : b;
}
int main() {
     
    int a = 4, b = 1;
    int ans = 0;

    ans = getMax(a,b);
    cout<< ans << "\n";

    a++, b++;
    ans = getMax(a,b);
    cout<< ans <<"\n";
    
    return 0;
}