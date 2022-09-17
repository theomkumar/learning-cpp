#include<iostream>
using namespace std;
int main() {
    //power(a,b) without using function
    int a,b;
    cin>>a>>b;
    long long int ans=1;
    for (int i=1; i<=b; i++) {
        ans*=a;
    }
    cout<<ans<<endl;

}