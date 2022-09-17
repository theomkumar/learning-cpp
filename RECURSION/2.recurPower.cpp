#include<iostream>
//2^n = ?
using namespace std;


// Recursive relation:-
//    f(n) = 2 * f(n-1);  as 2^n = 2 * 2^(n-1);

int power(int n) 
{
    //Base case
    if (n == 0)
        return 1;

    //recursive relation
/* 
    int smallerProblem = power(n-1);
    int biggerProblem = 2 * smallerProblem;
    
    return bigger problem;
*/
    return 2 * power(n-1);
    
}

int main() {
    
    int n;
    cin>>n;

    int ans = power(n);

    cout << ans << "\n";
    
    return 0;
}