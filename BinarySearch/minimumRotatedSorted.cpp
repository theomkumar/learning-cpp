#include<iostream>
using namespace std;
//find minimum rotated sorted array.
int pivortPoint(int arr[], int n) {
    int start = 0, end = n-1, mid = start+(end-start)/2;
    while(start<end) {
        if (arr[mid]>arr[mid+1]) {
            return mid+1;
        }
        else if (arr[mid]>arr[end]) {
            start=mid;
        }
        else {
            end=mid;
        }
        mid = start+(end-start)/2;
    }
    return mid;
}
int main() {
    int arr[5]={7,9,1,2,3};
    cout<<"index of pivot point "<<pivortPoint(arr,5)<<'\n';
}