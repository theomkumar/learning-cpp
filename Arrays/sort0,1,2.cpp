#include<iostream>
using namespace std;

void print(int arr[],int n) {
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
}

void sorting(int arr[],int n) {
    int start=0,middle=0,end=n-1;
    while(middle<=end) {
        switch(arr[middle]) {
            case 0: swap(arr[middle++],arr[start++]);
                    break;
            case 1: middle++;
                    break;
            case 2: swap(arr[end--],arr[middle]);
                    break;        
        }
    }
}

int main() {
    int arr[10]= {1,2,1,2,0,0,1,2,0,1};
    sorting(arr,10);
    print(arr,10);

}