#include<iostream>

using namespace std;

int getSum(int *arr, int n)
{ //arr[]= *(arr)
    int sum = 0;
    for (int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
} 
int main() {
/*
    int *arr = new int[4];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    int *nums = new int;
    *nums = 4;

    //same thing but in short.
    int *i = new int[4] {1,2,3,4};
    int *i = new int{4};
*/

    
    //cout<<*i<<"\n";
    int n;
    cin>>n;
    
    
    // variable size array
    int*arr= new int[n];

    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }    
    cout<<getSum(arr,n);

    //delete in heap
    delete []arr;
    //delete i; //if any int,char etc

    return 0;
}