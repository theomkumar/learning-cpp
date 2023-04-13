#include<iostream>
#include<math.h>

using namespace std;
int main() {
    int n;
    cin>>n;
    bool isprime=1;

//    for(int i=2; i<n; i++) {
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i==0){
          //cout<<"Not Prime! \n";
            isprime=0;
            break;
        }
        
    }
    if(isprime==0){
        cout<<"Not Prime! \n" ;
    }
    else {
        cout<<"Prime! \n";
    }

}