#include<iostream>
using namespace std;

//iterative
int ApowerB(int a, int b)
{
    int ans = 1;
    for (int i = 0; i<b; i++)
    {
        ans = ans * a;
    }
    return ans;
}

//recursive
int ApowerB2(int a, int b)
{
    //base case
    if (b==0)
        return 1;
    if (a==0)
        return 0;

    return a * ApowerB2(a,b-1);
}
int main() 
{
    int a, b; 
    cout << "INPUT A: ";
    cin >> a;
    cout << "INPUT B: ";
    cin >> b; 

    cout<< "Output: " <<ApowerB2(a,b)<<"\n";
 
    return 0;
}