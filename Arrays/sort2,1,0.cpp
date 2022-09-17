#include<iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void sorting(int arr[],int n) {
    int i=0, j=0, k=n-1;
    
    while(j<=k) {
        switch(arr[j]) {
            case 0: swap(arr[j],arr[k--]);
                    break;
            case 1: j++; 
                    break;
            case 2: swap(arr[j++],arr[i++]);
                    break;
        }
    }
}

int main() {
    int arr[11] = { 0,2,2,0,1,1,1,0,2,1,2};
    sorting(arr,11);
    print(arr,11);

}