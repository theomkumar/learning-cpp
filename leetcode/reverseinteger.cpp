#include<iostream>
#include <climits>
using namespace std;

int main() {
    //Given a signed 32-bit integer x, return x with its digits reversed.
    // If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
    int x;
    cin>>x;
        int s=0;
        while(x) {
            if ((s>INT_MAX/10) || (s<INT_MIN/10)) {return 0;}
            s=(s*10)+x%10;
            x/=10;
        } 
       cout<<s<<endl;
}