#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a=100,b=50,c=20,d=1;
    
    switch(a) {
        case 100:if (n>=a) cout<<"100-"<<n/a<<endl;
                 n=n%a;
        case 50 :if (n>=b) cout<<"50-"<<n/b<<endl;
                n=n%b;
        case 20 :if (n>=c) cout<<"20-"<<n/c<<endl;
                n=n%c;
        case 1  :if (n>=d) cout<<"1-"<<n/d<<endl;
                break; 
    }
}