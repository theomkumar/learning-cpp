#include<iostream>
using namespace std;

void insertionSort(int arr[],int n) {
    for(int i=1; i<n; i++) {
        int temp = arr[i];
        int j=i-1; 
        while(j>=0) {
            if (arr[j]>temp) {
                arr[j+1]=arr[j];
            }
            else break;
            j--;
        }
        arr[j+1] = temp;
    }
}

void printArray(int arr[],int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main() {
    int arr[]={10,1,5,4,6,9,4,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,n);
    printArray(arr,n);
    return 0;
}