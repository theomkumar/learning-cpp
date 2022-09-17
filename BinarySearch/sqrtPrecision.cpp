#include<iostream>
using namespace std;

double precise(int x, int whole, int precision) {
    double ans = whole, factor = 1;
    for(int i=0; i<precision; i++) {
        factor = factor/10;
        for(double j = ans; j*j<x; j+=factor) {
            ans=j;
        }
    }
    return ans;
}


long int mySqrt(int x) {
    long int start = 0, end = x, mid = start+(end-start)/2;
    while (start<=end) {
        if(x>=mid*mid && x<(mid+1)*(mid+1)) return mid;
        else if (x>mid*mid) start=mid+1;
        else end=mid-1;
        mid = start+(end-start)/2;
    }
    return -1;
}

int main() {
    cout<<"Input number : ";
    int x;
    cin>>x;
    int whole=mySqrt(x);
    cout<<"\nSquare root of "<<x<<": "<<precise(x,whole,3);

}
