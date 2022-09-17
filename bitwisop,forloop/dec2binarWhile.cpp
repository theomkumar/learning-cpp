#include<iostream>
#include<math.h>
using namespace std;
int main() {
    int n;
    cout<<"Convert Decimal into Binary:- \nInput Number: ";
    cin>>n;
    //b will save input n for cout<<n as the value of n will get reduced to 0 by n=n>>1 until (n!=0)
    int b=n;
    int i=0;
    int a=0;
    while (n!=0) {
        int bit=n&1;
        a=(bit*pow(10,i)+a);
        i++;
        n=n>>1;

    }
    cout<<"Binary representation of "<<b<<" is : "<<a<<endl;
}




