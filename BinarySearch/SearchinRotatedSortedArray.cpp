#include<iostream>
using namespace std;

int findKey(int a[], int n, int k, int pivotIndex) {
    int s = 0, e = n-1, m = s + (e-s)/2;

    if ( k >= a[pivotIndex] && k <= a[e]) s = pivotIndex;  
    else e = pivotIndex - 1;
    m = s + (e-s)/2;

    while(s<=e) {
        if (a[m]==k) return m;
        else if (a[m] > k) e = m-1;
        else s = m + 1;
        m = s + (e-s)/2;
    }
    return -1;
}

int findPivot(int a[], int n, int k) {
    //finding pivot point first i.e the lowest no. in rotated sorted array 
    int s = 0, e = n-1, m = s + (e-s)/2;
    
    while (s < e) {
        if (a[m] < a[e]) e = m;
        else s = m + 1;
        m = s + (e-s) / 2;
    }
    cout<< "index of pivot point is : "<< m<< "\n";
    return m;
}

int main() {
    int a[11] = {3,4,5,6,7,8,11,12,0,1,2};
    int n = sizeof(a) / sizeof(a[0]);

    int k;
    cout<<"enter key value : ";
    cin >> k;

    int pivotIndex = findPivot(a, n, k); 
    

    cout<<"Index of key is : "<<findKey(a, n, k, pivotIndex)<<"\n";
    
}