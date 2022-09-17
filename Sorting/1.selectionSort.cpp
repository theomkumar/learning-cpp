#include<iostream>
using namespace std;
//traverse i and if j<i swap i with j
int main() {
    int arr[5] = {14,10,12,8,1};
    int n = 5;
    for (int i = 0; i<n-1; i++) {
        int minIndex = i;

        for (int j = i+1; j<n; j++) {

            if (arr[minIndex]>arr[j]) 
            minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}