//https://www.codingninjas.com/studio/problems/build-heap_975375?leftPanelTab=1
/*
The heapify function takes O(log N) time because it moves an element from the root to the leaf in a binary heap of height log N.
The buildMinHeap function calls heapify for N/2 elements, starting from the middle of the array.
The total time complexity is O(N) because most of the elements are in the bottom layer and take O(1) time to heapify. The formula for the number of elements at height h is N / 2^(h+1).
The summation of (N / 2^(h+1) * O(h)) over all values of h from 0 to log(N) is equal to O(2N), which is equivalent to O(N).
*/
#include <bits/stdc++.h>
using namespace std;
//STANDARD
void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int l = 2*i+1, r = 2*i+2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr,n, largest);
    }
}

vector<int> buildHeap(vector<int> arr, int n)
{	
	// Write your code here 
    for(int i = (n-1)/2; i >= 0; i--)
        heapify(arr,n,i);
    return arr;
}


//SELF ()
#include <bits/stdc++.h>
using namespace std;

void heapifySelf(vector<int> &arr, int n, int index){
    //base case
    if (index < 0) return;

    int i = index;

    while(i < n)
    {
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;
        }
        else
            break;
    }
    heapifySelf(arr,n,--index);
}


vector<int> buildHeap(vector<int> arr, int n)
{	
	// Write your code here 
    heapifySelf(arr,n,(n-1)/2);
    return arr;
}