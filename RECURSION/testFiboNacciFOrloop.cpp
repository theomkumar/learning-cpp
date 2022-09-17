#include<iostream>
using namespace std;

int fibo(int n)
{
    //base case
    if ( n < 2)
        return 0;
    if (n == 2 )
        return 1;

    //var
    int a = 0, b = 1;

    for (int i = 3; i <= n; i++)
    {
        int nextNo = a + b; 
        a = b;
        b = nextNo;
    }

    return b;
}

int main () 
{
    //input 
    int n; cout<<"INPUT: ";
    cin>>n;

    //output
    cout<<"OUTPUT: " << fibo(n)<<"\n";

    return 0;
}