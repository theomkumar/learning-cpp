#include<iostream>
using namespace std;
int main() {
    int a,b;
    cout<<"\nenter the value of a \n";
    cin>>a;
    cout<<"enter the value of b \n";
    cin>>b;
    char op;
    cout<<"enter the operation \n";
    cin>>op;
    cout<<"\nResult : \n"<<a<<" "<<op<<" "<<b<<" = ";

    switch (op) {
        case '+' : cout<<a+b<<endl;
                    break;
        case '-' : cout<<a-b<<endl;
                    break;
        case '*' : cout<<a*b<<endl;
                    break;
        case '/' : cout<<a/b<<endl;
                    break;
        case '%' : cout<<a%b<<endl;
                    break;
        default  : cout<<"enter a valid operation \n";
                    break;
    }

}