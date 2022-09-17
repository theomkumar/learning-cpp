#include<iostream>
using namespace std;

int countbit(int n) {
    int s=0;
    while (n) {
        if (n&1) {
            s++;   
        }
        n=n>>1;
    }
    return s;
}

int main() {
    int a,b; cin>>a>>b;
    int s=countbit(a)+countbit(b);
    cout<<s<<endl;
    return 0;
}