#include<iostream>

using namespace std;

int main() {
    int num = 5;

    cout<<num<<endl;
    //address of operator -> &
    
    cout<<" address of num is "<< &num <<"\n";
    int *ptr = &num;
    cout<<"address of num is "<<ptr<<endl;
    cout<<"value of num is "<<*ptr<<endl;

    double d = 1.23;
    double *p2 = &d;

    cout<<"value of d is "<<*p2<<"\n";
    cout<<"address of d is "<<p2<<'\n';

    //size of pointer is always 8 bytes for 64 bit system and 4 byte for 32 bit system
    //irrespective of data types coz, it only stores address.

    cout<<"size of integer is "<<sizeof(num)<<endl;
    cout<<"size of pointer is "<<sizeof(ptr)<<endl;
    cout<<"size of pointer is "<<sizeof(p2);
    
    
    return 0;
}