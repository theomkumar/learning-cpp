#include<iostream>
using namespace std;

int getSum(int *arr, int size)
{
    //base case
    if (size==0)
        return 0;
    if (size==1)
        return arr[0];
    //recursive relation
    int ans = arr[0] + getSum(arr+1,size-1);
    return ans;
/*
    int remainingPart = getSum(arr+1,size-1);
    int sum = arr[0] + remainingPart;

    return sum;
*/
}

int main() 
{
    int arr[] = {1,3,5,3,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = 0;

    cout<<"sum: "<<getSum(arr,size);
    return 0;
}