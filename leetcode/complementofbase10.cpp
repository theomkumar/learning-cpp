#include<iostream>
#include<math.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    if(n==0) cout<<"1";
    else {
        int n2=n;
        int s=0;
        while (n) {
            s++;
            n=n>>1;
        }
        int a=(pow(2,s)-1);
        a=a & (~n2);
        cout<<a<<endl;
    }
}