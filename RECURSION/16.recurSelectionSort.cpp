#include<iostream>
using namespace std;
//selection sort minimum element at right place one at a time.
/*
void sort(int *arr, int n)
{
    // base case 
    for (int i = 0; i<n-1; i++) {
        int minIndex = i;

        for (int j = i+1; j<n; j++) {
            if ( arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}
*/

void sort (int arr[], int n) 
{
    // base case ->already sorted
    if (n == 0 || n == 1)
        return;
    // solving for one case
    int minIndex = 0;
    for (int i = 1; i<n; i++) {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }
    swap (arr[0],arr[minIndex]);
    //recursive call
    return sort(arr+1,n-1);  

}
int main() 
{
    int arr[] = {9,11,8,8,7,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort (arr,n);

    for (int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}