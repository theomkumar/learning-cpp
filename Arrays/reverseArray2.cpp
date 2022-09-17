#include<iostream>
using namespace std;

void print(int arr[],int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverse(int arr[],int n) {
    
    
    for(int start=0,end=n-1; start<end; start++,end--) {
        swap(arr[start],arr[end]);
    }
}

int main() {
    int arr[5]= {1,2,3,4,5};
    int arr2[6]= {1,2,3,4,5,6};

    reverse(arr,5);
    reverse(arr2,6);

    print(arr,5);
    print(arr2,6);


    return 0;
}