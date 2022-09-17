#include<iostream>
#include <climits>
//https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?leftPanelTab=0
using namespace std;

int end(int arr[], int n) {
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

bool isPossible(int arr[], int n, int m, int mid) {
    
    int studentCount = 1;
    int pageSum = 0;

    for( int i=0; i<n; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum+=arr[i];
        }
        else {
            studentCount++;
            
            if (studentCount>m || arr[i]>mid) return false;
            pageSum = arr[i];
        }
    }
    return true;
}

int main() {
    int arr[4] = {10,20,30,40};
    int m =2, n=4;

    int s = 0;
    int e = end(arr,n);
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e) {
        if(isPossible(arr,n,m,mid)) {
            ans = mid;
            e = mid-1;
        }
        else s = mid+1;
        mid = s+(e-s)/2;
    }
    cout<<ans;
    return ans;
}