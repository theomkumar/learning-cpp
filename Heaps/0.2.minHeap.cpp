//coding ninja
/*
The heapify function takes O(log N) time because it moves an element from the root to the leaf in a binary heap of height log N.
The buildMinHeap function calls heapify for N/2 elements, starting from the middle of the array.
The total time complexity is O(N) because most of the elements are in the bottom layer and take O(1) time to heapify. The formula for the number of elements at height h is N / 2^(h+1).
The summation of (N / 2^(h+1) * O(h)) over all values of h from 0 to log(N) is equal to O(2N), which is equivalent to O(N).
*/
#include <bits/stdc++.h> 
void heapify(vector<int> &arr, int n, int i){
    int smallest = i;
    int l = 2*i+1, r = 2*i+2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr,n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i = (n-1)/2; i >= 0; i--)
        heapify(arr,n,i);
    return arr;
}
