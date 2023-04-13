#include<iostream>
#include<math.h>

using namespace std;

bool isPrime(int n) {
    for(int i=2; i<=sqrt(n); i++) {
        if (n%i==0) return false;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    //1=prime cout<<isPrime(n);

    if((isPrime(n))) cout<<"PRIME!\n";
    else cout<<"Not Prime!\n";
    return 0;
}   