#include<iostream>
using namespace std;

void print(int arr[],int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}
void sorting(int arr[],int n) {
    int i=0,j=n-1;
    
    while(i<j){
        
        if (arr[i]==0) i++; 
        if (arr[j]==1) j--; 
        
        if (arr[i]==1 && arr[j]==0) {
            swap(arr[i],arr[j]);
            i++; j--;
        }
    }
}

int main() {
    int arr[11]={1,1,0,0,0,0,1,0,0,0,1};
    sorting(arr,11);
    print(arr,11);

}