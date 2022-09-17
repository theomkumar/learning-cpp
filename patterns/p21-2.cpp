#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=1;
    while (i<=n) {
        int space=n-i;
        while (space) {
            cout<<" ";
            space=space-1;
        }
        int j=1;
        while (j<=i) {
            cout<<j;
            j=j+1;
        }
        j=i-1;
        while (j>=1) {
            cout<<j;
            j=j-1;
        }
        cout<<endl;
        i=i+1;
    }
}

/*
4
   1
  121
 12321
1234321
*/