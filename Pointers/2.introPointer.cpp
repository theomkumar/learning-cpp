#include<iostream>

using namespace std;

int main() {
    //pointer to int is created and pointing to some garbage address
    int *p;   
    cout<<*p<<endl;

    //pointing to null
    int *p1=0;
    cout<<p1<<endl;
    //error : cout<<*p1<<endl; Segmentation fault/Segfaults are caused by a program trying to read or write an illegal memory location

    // 2 ways to initialise
    int i = 5;

    int *a = &i;
    cout<<"value is "<<*a<<" adress is "<<a<<endl;

    int *b = 0;
    b = &i;
    cout<<"value is "<<*b<<" adress is "<<b<<endl;

    //incrementing 
    int num = 5;
    int *p3 = &num;
    cout<<"before "<<num<<endl;
    (*p3)++;
    cout<<"after "<<num<<endl;
    
    // copying pointer p3->q
    int *q = p3;
    cout<<p3<<"- "<<q<<endl;
    cout<<*p3<<"- "<<*q<<endl;

    int j = 6;
    int *t = &j;

    *t = *t + 1; //increases value of j by 1

    cout<< "after incrementing j by 1 "<<*t <<endl;

    //icrementing address by one increases address by 4 for int type, 
    // and by 8 for double. coz the space (4 byte-int) is used by current data type.
    // so the next address will be the address of next data type;

    cout<<"before incrementing t "<<t<<endl;

    t = t + 1;
    cout<<"after  incrementing t "<<t<<endl;
    //if we calculate difference in hex value we'll get four coz int is 4bytes.


    return 0;

}