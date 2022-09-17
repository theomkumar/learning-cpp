#include <iostream>
using namespace std;

//recursive relation: f(n) = f(n-1) + f(n-2);

int fibonacci(int n)
{
    //base case if we consider 0th term as 0;
    if (n<2) //(n==0,n==1->term is 0,1) //fibonacci  0,1,1,2 
        return n;                       //term(n)    0,1,2,3

    //base case if we consider 1st term as 0;
/*  if ( n==2)       //fibonacci  0,1,1,2               
        return 1;    // term      1,2,3,4
    if ( n==1)
        return 0;
*/
    //Recursive relation
    return fibonacci(n-1) + fibonacci(n-2);
}

int main ()
{
    int n;
    cout<<"find nth fibonacci number: "<<"\n";
    cin>>n;

    cout<<"output: "<<fibonacci(n);
    return 0;
}