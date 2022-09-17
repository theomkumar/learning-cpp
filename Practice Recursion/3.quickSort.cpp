#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 // } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low >= high)
            return;
        //
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1); 
        quickSort(arr, p+1, high);
    }
/*
    class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low >= high)
            return;
        //
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1); //not p-1 as p will act as infinity
        quickSort(arr, p+1, high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = low-1;
        int j = low;
        
        while (j < high) 
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap (arr[i], arr[j]);
            }
            j++;
        }
        swap (arr[i+1], arr[high]);
        return i+1;
    }
};  

*/
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;
        
        while (i < j) 
        {
            while (arr[i] <= pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i < j)
                swap (arr[i], arr[j]);
        }
        swap (arr[low], arr[j]);
        return j;
    }
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends