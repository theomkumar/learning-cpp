#include<iostream>
using namespace std;
int main() {
    float a,b;
    char op;
    cout<<"\n Calculate :) \n";
    cin>>a>>op>>b;
    cout<<"Result= ";

    switch (op) {
        case '+' : cout<<a+b<<endl;
                    break;
        case '-' : cout<<a-b<<endl;
                    break;
        case '*' : cout<<a*b<<endl;
                    break;
        case '/' : cout<<a/b<<endl;
                    break;
        default  : cout<<"enter a valid operation \n";
                    break;
    }

}