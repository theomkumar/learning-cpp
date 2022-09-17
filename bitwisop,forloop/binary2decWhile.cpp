#include<iostream>
#include<math.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=0,s=0;
    while(n!=0) {
        int digit = (n%10);
        if(digit==1) {
            s=(pow(2,i)+s);
        }
        i++;
        n=n/10;
        
    }
    cout<<s;
}