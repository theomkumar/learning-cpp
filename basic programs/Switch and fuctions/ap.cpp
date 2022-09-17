#include <iostream>
using namespace std;

int ap(int n) {
    
    int ans=(3*n)+7;
    return ans;
}
int main() {
    int n,t; 
    //t is no of test cases;
    cin>>t;
    while(t>0){
        cin>>n;
        cout<<ap(n)<<endl;
        t--;
    }
    return 0;
}

