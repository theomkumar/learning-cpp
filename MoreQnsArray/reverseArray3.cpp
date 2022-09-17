/*We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
based indexing so the subarray {5, 6} will be reversed and our 
output array will be {1, 2, 3, 4, 6, 5}. */

#include<iostream>
#include<vector>
using namespace std;

//reverse check
void reverse(vector<int> &arr, int n, int m) {

    for(int start=m+1,end=n-1; start<end; start++,end--) {
        swap(arr[start],arr[end]);
    }

   /* for(int start = (m+1), count = 0; count<(n-m)/2; count++,start++) {
        swap(arr[start],arr[n-count-1]);
    } */
}

void print(vector<int> arr,int n, int m){
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<'\n';
}
int main() {
    vector<int> arr;
    arr.insert(arr.end(),{1,2,3,4,5,6});
    int n = arr.size();
    int m = 3;

    reverse(arr,n,m);

    print(arr,n,m);
    return 0;
}