#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=1;
    while (i<=n) {
        int s=1,j=1;
        while (s<=n-i) {
            cout<<" ";
            s=s+1;
        }
        while (j<=i) {
            cout<<i;
            j=j+1;
        }
        cout<<"\n";
        i=i+1;
    }
}
/*
   1
  22
 333
4444
*/