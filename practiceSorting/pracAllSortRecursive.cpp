#include<iostream>
using namespace std;

void print (int *arr, int n)
{
    for (int i = 0; i<n; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << '\n';
}

void selectionSort (int *arr, int n)
{
    //base case
    if (n<2)
        return;
    //processing
    int minIndex = 0;
    for (int i = 0; i<n; i++) 
    {
        if (arr[minIndex] > arr[i]){
            minIndex = i;
        }
    }
    swap (arr[0], arr[minIndex]);
    //
    selectionSort(arr+1, n-1);
}

void bubbleSort(int *arr, int n)
{
    //base case
    if (n<2)
        return;
    //
    bool swapped = false;
    for (int i = 0; i<n-1; i++) {
        if (arr[i] > arr[i+1]) {
            swap (arr[i], arr[i+1]);
            swapped = true;
        }
    }
    if (!swapped)
        return;
    // 
    bubbleSort( arr, n-1);
}

void insertionSort(int *arr, int n) 
{
    //
    if (n <= 1) 
        return;
    //
    insertionSort(arr, n-1);
    //
    int key = arr[n-1]; //current element
    int j = n-2; //index of element before key(current element) and  i.e sorted area

    while (j>=0 && key < arr[j])
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}

int main() 
{
    int arr[] = {0,7,1,3,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    //selectionSort(arr, n);
    insertionSort(arr, n );
    // bubbleSort(arr, n);
    print(arr, n);
    
    return 0;
}