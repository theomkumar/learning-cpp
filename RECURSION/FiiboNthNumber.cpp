#include<iostream>
//fibonacci starting from (0)th term.
using namespace std;

int main() 
{
    int n;
    cin>>n; cout<<"\n";

    int a = 0; //O'th index  ;; n-2 >>> n-1
    int b = 1; //1'st index  ;; n-1>>> n

//basically we need (total n Elements-2) loops, coz we have a = 0'th and b = 1'st
// eg if n = 3, i.e 0,1,2,3 no. of loops = 4-2 
// i.e relation between n and loops is n-1;  if fibo starts from 1st term as 0 then loops = n-2,, eg n = 3; (1,2,3) loops = n-2 = 1;

    if (n<2) return n;
//
    for (int i = 2; i<=n; i++) //i = 2'nd index// loops = n-1,, 
        int c = a+b; 
        a = b; 
        b = c;     
    }

    cout<< b ;
    
    
    return 0;
}