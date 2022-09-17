#include<iostream>
using namespace std;


int main() 
{
    int *arr = new int[100];
    cout <<" hello world";
    delete arr;
    
    int a = 12;
    int *ptr = &a;
    // delete ptr;

    int *intPtr = new int(14);

}