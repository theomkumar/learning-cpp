#include<iostream>

using namespace std;

void print(int n)
{
    //base case  
    if( n == 0)
        return;

    //recursion relation
    print(n-1);

    //processing
    cout << n << " " << " ";
}

int main() {
    
    int n; 
    cin >> n; cout<<"\n";

    print(n);

    
    return 0;
}