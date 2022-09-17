#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=1;
    while (i<=n) {
        int space=1,j=1;
        while (space<=i-1) {
            cout<<" ";
            space=space+1;
        }
        while (j<=n-i+1) {
            cout<<i;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
/*
4
1111
 222
  33
   4
*/