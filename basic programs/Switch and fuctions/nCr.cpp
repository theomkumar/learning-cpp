#include<iostream>
using namespace std;
//function of factorial
int f(int n) {
    int fact=1;
    for (int i=1; i<=n; i++) {
        fact=fact*i;
    }
    return fact;
}
//function of nCr formula 
int ncr(int n, int r) {
    int c=f(n)/(f(n-r)*f(r));
    return c;
}
int main() {
    int n,r;
    cin>>n>>r; 
    cout<<"Answer is "<<ncr(n,r)<<endl;
    return 0;
}