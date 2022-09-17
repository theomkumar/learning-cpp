#include<iostream>
#include<math.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    
    int s=0;
    for( int i=0;n!=0;i++,n=n/10) {
        int digit= (n%10);
        if(digit==1) {
            s= (pow(2,i)+s);
        } 
    }
    cout<<s;
}


