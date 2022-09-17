#include<iostream>
using namespace std;
void printArray(int arr[],int n) {
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void bubbleSort(int arr[], int n) {
    for(int i = 0; i<n-1; i++) {
        bool swapped=0;
        for(int j = 0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swapped = 1;
            }
        }
        if (!swapped) break;   
    }
}
int main() {
    int arr[5] = {6, 2 ,8 ,4, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    printArray(arr,n);
}
