//gfg
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//note testCount is just to see reference variable.
long long int merge(long long arr[], long long low, long long mid, long long high, long long &testCount)
{
    long long invCount = 0;
    long long len1 = mid - low + 1;
    long long len2 = high - mid;
    long long a[len1], b[len2];
    //
    for (long long i = 0; i < len1; i++) 
        a[i] = arr[low + i];
    for (long long i = 0; i< len2; i++)
        b[i] = arr[mid + 1 + i];
    //
    long long i = 0, j = 0, k = low;
    
    while (i < len1 && j < len2) 
    {
        if (a[i] <= b[j])
            arr[k++] = a[i++];
        else {
            arr[k++] = b[j++];
            invCount += len1 - i;
            testCount += len1 - i;
        }
    }
    while (i < len1)
        arr[k++] = a[i++];
    while (j < len2) 
        arr[k++] = b[j++];
 
    return invCount;
}

long long int mergeSort(long long arr[], long long low, long long high, long long &testCount)
{
    long long invCount = 0;
    if (low < high) {
        //
        long long mid = low + (high - low)/2;
        
        invCount += mergeSort(arr, low, mid, testCount);
        invCount += mergeSort(arr, mid+1, high, testCount);
        //
        invCount += merge(arr, low, mid, high, testCount);
    }
    return invCount;
}
long long int inversionCount(long long arr[], long long N, long long &testCount)
{
    return mergeSort(arr, 0, N-1, testCount);
}

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        //testing ref variable
        long long testCount = 0;
        std::cout<<"count : "<< inversionCount(A,N,testCount)<<"\n";
        std::cout <<"Count from ref. variable : " << testCount <<"\n";
        //print array 
        std::cout <<"sorted array: ";
        for (long long i = 0; i<N; i++)
            std::cout <<A[i] << " ";
        std::cout<<"\n";
    }
    
    return 0;
}
  // } Driver Code Ends