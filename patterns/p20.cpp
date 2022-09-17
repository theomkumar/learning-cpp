#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=1;
    int s=1;
    while (i<=n) {
        int space=1,j=1;
        while (space<=n-i) {
            cout<<"  ";
            space=space+1;
        }
        while (j<=i) {
            cout<<s<<" ";
            s=s+1;
            j=j+1;

        }
        cout<<"\n";
        i=i+1;
    }
}
/*
4
      1 
    2 3 
  4 5 6 
7 8 9 10 
*/