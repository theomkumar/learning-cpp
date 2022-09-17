#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

long long merge (long long arr[], long long low, long long mid, long long high)
{
    long long inv = 0;
    long long i = low;
    long long j = mid+1;
    long long k = low;
    long long temp[high];

    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j]){
            inv += mid-i+1;
            temp[k++] = arr[j++];
        }
        else {
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];

     //copying temp(sorted array) long longo original array(unsorted)
    for (long long i = low; i <= high; i++) {
        arr[i] = temp[i];
    }

    return inv;
}
long long mergeSort(long long arr[], long long low, long long high) 
{
    static long long inv = 0;
    //base case
    if (low < high){
        long long mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        inv += merge (arr, low, mid, high);
    }
    return inv;
}
long long inversionCount(long long arr[], long long N)
{
    return mergeSort(arr, 0, N-1);
}

int main() 
{
    long long arr[] = {2, 4, 1, 3, 5};
    long long n = sizeof(arr) / sizeof(arr[0]);

    cout <<"Total Inversions: "<< inversionCount(arr, n);
    

    //prlong long array
    cout <<"\nsorted array: ";
    for (long long i = 0; i<n; i++) {
        cout << arr[i]<<" ";
    } cout <<"\n";
}