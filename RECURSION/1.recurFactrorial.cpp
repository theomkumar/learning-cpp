#include<iostream>
using namespace std;

// n! = n * (n-1)!

//biggerProblem = n! = n * smallerProblem
//smallerProblem = factorial(n-1)!

int factorial(int n) 
{
    cout<<n<<endl;

      //base case
    if (n == 0) // coz 0! = 1
        return 1;

/*  int smallerProblem = factorial(n-1);
    int biggerProblem = n * smallerProblem; 

    return biggerProblem;
*/
    return n * factorial(n-1);
}

int main() {
    int n;
    cin >>n;

    int ans = factorial(n);

    cout << ans << endl;
    
    
    return 0;
}