#include<iostream>
using namespace std;

int fibo(int n) {
    int a=0,b=1;
    if (n==0) return 0;
    for(int i=1; i<n-1; i++) {
        int nextno= a+b;
        a=b;
        b=nextno;
    }
    return b;
}

int main() {
    int n; cin>>n;
    cout<<fibo(n);
    return 0;


}