#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a=100,b=50,c=20,d=1;
    
    switch(a) {
        case 100:if (n>=a) cout<<n/a<<endl;
        case 50 :if (n>=b) cout<<(n%a)/b<<endl;
        case 20 :if (n>=c) cout<<(n%a%b)/c<<endl;
        case 1  :if (n>=d) cout<<(n%a%b%c)/d<<endl;
        
                break; 
    }
}