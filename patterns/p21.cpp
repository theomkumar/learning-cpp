#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=1;
    while (i<=n) {
        int space=1,j=1;
        while (space<=n-i) {
            cout<<" ";
            space=space+1;
        }
/*
        int space=n-i;
        while (space) {
            cout<<" ";
            space=space-1;
*/
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
        //using extra s variable
        int space=1,s=1,j=1;
        while (space<=n-i) {
            cout<<" ";
            space=space+1;
        }
        while (j<=i) {
            cout<<s;
            s=s+1;
            j=j+1;
        }
        j=1;
        s=i-1;
        while (j<=i-1) {
            cout<<s;
            s=s-1;
            j=j+1;
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