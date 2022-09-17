#include<iostream>
using namespace std;

void print (int *arr, int n)
{
    for (int i = 0; i<n; i++) 
        cout << arr[i] <<" ";
    cout<<"\n";
}
//iterative 
/*
void sort (int *arr, int n)
{
    for (int i = 1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1; 

        while ( j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }  
}
*/
//recursive

void sort (int *arr, int n)
{
    //base case 
    if (n <= 1)
        return;
    
    //recursive call
    sort(arr, n-1);
    
    //processing
    int key = arr[n-1];
    int j = n-2;

    while ( j >= 0 && key < arr[j] )
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;  
}

void insertionSortRecursive(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return;
 
    // Sort first n-1 elements
    insertionSortRecursive( arr, n-1 );
 
    // Insert last element at its correct position
    // in sorted array.
    int last = arr[n-1];
    int j = n-2;
 
    /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

int main() 
{
    int arr[] = {32,1,34,3,5,6,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort (arr, n);
    print (arr,n);
    
    int arr2[] = {12, 11, 13, 5, 6};
    n = sizeof(arr2)/sizeof(arr2[0]);
 
    insertionSortRecursive(arr2, n);
    print(arr2, n);

    return 0;
}