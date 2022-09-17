#include<iostream>

using namespace std;

double sqrt(int x, int precision) {
    int s = 0, e = x/2;
    double m,ans;
    //sqrt whole
    while(s<=e) {
        m = s+(e-s)/2;
        if (x>=m*m && x<(m+1)*(m+1)) {
            ans = m;
            break;
        }   
        else if (x<m*m)
            e = m - 1;
        else s = m + 1;
    }
    //sqrt precision
    double factor = 1;
    for(int i = 0; i<3; i++) {
        factor = factor/10;
        for(double j = ans; j*j<x; j+=factor) {
            ans = j;
        }
    }
    return ans;
}
int main() {
    cout<<"Input: ";
    double x; cin>>x;
    cout<<"\nSqrt precise: "<<sqrt(x,3)<<"\n";
   
    
    return 0;
    
}

    

   
