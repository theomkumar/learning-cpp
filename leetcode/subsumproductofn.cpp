#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int s=0,p=1;
    while (n!=0) {
        int d=n%10;
        s+=d;
        p*=d;
        n/=10;
    }
    int ans=p-s;
    cout<<ans<<endl;


    
}