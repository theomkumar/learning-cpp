#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"Fibonacci Series Generate \nInput number! \n";
    cin>>n;
    cout<<"Fibonacci series upto number "<<n<<":"<<endl<<endl;

    int i=1;
    int a=0,b=1;
    if (n<=1) {
        cout<<"0"<<endl;
    }
        else {
                n=n-2;
                cout<<a<<" "<<b<<" ";
                for (;i<=n;i++) {
                    int s=a+b;
                    cout<<s<<" ";
                    a=b;
                    b=s;
                }
                cout<<endl;
        }    
   
}

