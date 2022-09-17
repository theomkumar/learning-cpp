#include<iostream>
using namespace std;
//recursively implemented
//faster than bubbble,insertion and selection sort

// Time complexity of Merge Sort is  θ(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.
//space complexity = (k * logn-> recursive depth using constant space k) + n, n>>log n , so 
//                 = O(n)
void print (int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout <<"\n";
}

void merge (int *arr, int s, int e)
{
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copying value.

    //1st array
    int mainArrayIndex = s;
    for (int i = 0; i<len1; i++) 
        first[i] = arr[mainArrayIndex++];

    //2nd array
    mainArrayIndex = mid+1;
    for (int i = 0; i<len2; i++) 
        second[i] = arr[mainArrayIndex++];

    //merge 2 sorted array
    int index1 = 0, index2 = 0;
    mainArrayIndex = s;

    while (index1<len1 && index2<len2){

        if (first[index1]<second[index2])
            arr[mainArrayIndex++] = first[index1++]; 

        else 
            arr[mainArrayIndex++] = second[index2++];
    }

    while (index1 < len1) 
        arr[mainArrayIndex++] = first[index1++];

    while (index2 < len2)
        arr[mainArrayIndex++] = second[index2++];
    
    //deleting
    delete []first;
    delete []second;
}
void mergeSort (int *arr, int s, int e)
{
    //base case
    if (s>=e)
        return;

    int mid = s + (e-s)/2;
    
    //left part sort
    mergeSort(arr,s,mid);

    //right part sort
    mergeSort(arr,mid+1,e);

    //merge
    merge(arr,s,e);

}
int main() 
{
    int arr[] = {2,4,5,61,5,6,1,78};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n-1);
    print (arr, n);
    return 0;
}