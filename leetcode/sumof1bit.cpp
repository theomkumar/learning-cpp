#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int s=0;

    while(n) {
        n=n&n-1;
        s++;



   /*    if(n&1) {
          s++;
       }
       n=n>>1; 
    }
    */
    }
    cout<<s;
    


}
