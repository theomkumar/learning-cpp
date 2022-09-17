#include<iostream>
// good read: https://stackoverflow.com/questions/1641957/is-an-array-name-a-pointer
using namespace std;


int main() {
    int arr[10] = {2,4,6,8,10,12,14,16,18,20};

    cout<<"address of first element: "<<arr<<endl;
    cout<<"address of first element: "<<&arr[0]<<endl;

    cout<<"value at i = 0: "<< *arr <<endl;
    cout<<"value + 1, print: "<< *arr + 1 <<endl;

    cout<<"value at i=1: "<< *(arr+1) <<endl;  
    //arr[8] == *(arr+8); as arr= &arr[0];

    //why? again the stack overflow link

    int *ptr = arr; //why? https://stackoverflow.com/questions/1641957/is-an-array-name-a-pointer
    //int *ptr = &arr[0]; first location 
    
    cout<<"address at i=0: " <<ptr<<" value: "<<*ptr<<endl;
    cout<<"address at i=1: " <<++ptr<<" value: "<<*ptr<<endl;
    
/*  arr[2] is evaluated as = *(arr+2)
                =  *(address of first i.e &arr[0] + 2)
                = *(address of 3rd element)
                = 6 a/q to our example

    ALSO,since, arr[i] = *(arr+i)
                arr[i] = *(i+arr)
                arr[i] = i[arr]
*/
    cout<<"arr[2] : "<<*(arr+2)<<" = "<<arr[2];
    cout<<" equal to: "<<2[arr]<<" = "<<*(2+arr)<<endl;

    return 0;
}