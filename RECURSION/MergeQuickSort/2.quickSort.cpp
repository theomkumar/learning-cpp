#include<iostream>
using namespace std;
//space -> O(n)
//avg case - O(nlogn)
//best case - O(nlogn)
//worst case - O(n^2)
void print(int *arr, int n)
{
    for (int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int partition (int *arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    
    for (int i = s+1; i<=e; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    //place pivot at right position
    int pivotIndex = s+count;
    swap(arr[s], arr[pivotIndex]);

    //left and right part
    int i = s, j = e;

    while (i<pivotIndex && j>pivotIndex)
    {
        while (arr[i]<=pivot)
            i++;
        while (arr[j]>pivot)
            j--;
        if (i<pivotIndex && j>pivotIndex)
            swap (arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort( int *arr, int s, int e)
{
    //base case
    if (s>=e)
        return;
    
    //partition
    int p = partition(arr, s, e);

    //left part
    quickSort (arr, s, p-1);

    //right part
    quickSort (arr, p+1, e);

}

int main() 
{
    int arr[] = {6, 5, 6, 0, -4, 7, 2, 9 };
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,n-1);
    print (arr,n);
    return 0;
}