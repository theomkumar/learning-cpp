#include<iostream>
// in i'th round i'th largest element is placed at right spot.
using namespace std;
void printArray(int arr[],int n) {
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
//best case O(n); when already sorted coz of break (swapCount condition, if swap
//count is 0 it means its already sorted;
//worst case O(n^2) 
void bubbleSort(int arr[], int n) {
    bool swapCount = 0;
    for(int i=1; i<n; i++) {
        bool swapCount = 0;
        for(int j=0; j<n-i; j++ ) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swapCount=1;
            }
        }
        if (!swapCount) break;
    } 
}
int main() {
    int arr[5] = {6, 2 ,8 ,4, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    printArray(arr,n);
}
