#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=1;
    while (i<=n) {
        int star=1,space=1;
        while (space<=(i-1)){
            cout<<" ";
            space=space+1;
        }
        while (star<=n-i+1) {
            cout<<"*";
            star=star+1;
        }
        cout<<"\n";
        i=i+1;
    }
}
/*
4
****
 ***
  **
   *
*/