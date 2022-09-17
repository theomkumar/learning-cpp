#include<iostream>
using namespace std;
// f(1) = 0; 
int fibo (int n)
{
    if (n == 2)
        return 1;
    else if (n == 1)
        return 0;
    return fibo (n-1) + fibo (n-2);
}

int main() 
{
    int n;
    cin >> n;
    cout << fibo (n);
    
    
    return 0;
}