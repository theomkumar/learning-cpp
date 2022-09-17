#include<iostream>
using namespace std;
//bad approach 

void findDuplicate(int arr[],int n) {
    int i=0;
    while(i<n) {
        int t=i+1;
        while(t<n) {
            if(arr[i]==arr[t]) {
            cout<<arr[i]<<" ";
            }        
            t++;

        } 
        i++;
    }
}
int main() {
    int arr[7]= {1,2,2,3,4,5,5};
    findDuplicate(arr,7);
}