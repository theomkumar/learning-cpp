//i'th round-> i'th largest element in right (n-i) position
#include<iostream>
using namespace std;

void print ( int *arr, int n)
{
    for (int i = 0; i<5; i++)
        cout << arr[i] << " ";
    cout<<"\n";
}

void sortArray (int *arr, int n)
{
    //print (arr,n);
    // base case - already sorted 
    if (n == 0 || n == 1)
        return;
    // 1 case solved - largest element at end 
    
    bool swapped = 0;
    for (int i = 0; i<n-1; i++) {
        if (arr[i]>arr[i+1]) {
            swap (arr[i],arr[i+1]);
            swapped = 1;
        }
          
    }
    if (!swapped) return; //if already sorted return 
    return sortArray (arr,n-1);
}

int main() 
{
    int arr[5] = {2,4,5,1,9};
    sortArray(arr,5);

    print (arr,5);
    
    
    return 0;
}