#include <iostream>
using namespace std;
//incomplete trying to use index without creating two new subarray

void print (int *arr, int n) 
{
    for (int i = 0; i<n; i++) {
        cout << arr[i] <<" ";
    }
    cout <<'\n';
}

void merge(int arr[], int l, int m, int r)
{
    int len1 = m - l + 1;
    int len2 = r - m;
    int *first = new int[len1];
    int *second = new int[len2];
    //copy 
    for (int i = 0; i<len1; i++) 
    first[i] = arr[l+i];
    for (int i = 0; i<len2; i++)
    second[i] = arr[m+1+i];
    //merge 
    int i1 = 0;
    int i2 = 0;
    int i = l; //index of arr
    
    while (i1 < len1 && i2 < len2) {
        if (first[i1] < second[i2])
        arr[i++] = first[i1++];
        else 
        arr[i++] = second[i2++];
    }
    while (i1 < len1)
    arr[i++] = first[i1++];
    while (i2<len2)
    arr[i++] = second[i2++];
    //delete
    delete []first;
    delete []second;
}
void mergeSort(int arr[], int l, int r)
{
    //base case
    if (l>r)
        return;
    //
    int m = l + (r-l)/2;
    //
    mergeSort (arr, l, m);
    mergeSort (arr, m+1, r);
    merge(arr, l, m, r);
}
int main() {
    int arr[] = {1,12,0,12,3,6,17};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n-1);
    print (arr, n);
    return 0;
}