#include<iostream>

using namespace std;

#define PI 3.14159

#define AREA(r) (PI * r * r)

int main()
{
    float r; cout<<"enter radius: "; cin>>r;

    cout<<"area :"<<AREA(r);
}