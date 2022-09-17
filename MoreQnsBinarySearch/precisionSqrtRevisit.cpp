#include<iostream>
using namespace std;

double precise (int x,int whole, int precision ) {
    double ans = whole, factor = 1;
    for(int i = 0; i<precision; i++) {
        factor = factor/10;
        for(double j = ans; j*j<x; j+=factor) {
            ans = j;
        }
    }
    return ans;
}

int sqrt(int x) {
    int s = 0, e = x/2;
    long m;

    while(s<=e) {
        m = s+(e-s)/2;
        if (x>=m*m && x<(m+1)*(m+1)) 
            return m;
        else if (x<m*m)
            e = m - 1;
        else s = m + 1;
    }
    return -1;
}

int main() {
    cout<<"Input: ";
    int x; cin>>x;
    int whole = sqrt(x);

    double decimal = precise(x,whole,3);

    cout<<" sqrt whole: "<<whole<<"\nSqrt precise: "<<decimal<<"\n";

}