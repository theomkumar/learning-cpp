#include<iostream>
using namespace std;
/*

 //normal binary search
bool binarySearch( int *arr, int size, int key)
{
    int s = 0, e = size-1, m;

    while (s<=e) 
    {
        m = s + (e-s)/2;
        if (arr[m]==key)
            return 1;
        if (arr[m]<key)
            s = m+1;
        else
            e = m-1;
    }

    return 0;
}
*/

bool binarySearch(int *arr, int s, int e, int k)
{
    //base case
    if (s>e) 
        return 0;

    int mid = s + (e-s)/2;

    if (arr[mid]==k) 
        return 1;
    
    if (arr[mid] < k)
        return binarySearch(arr, mid+1, e, k);
    else 
        return binarySearch(arr, s, mid-1,k);

}

int main() 
{
    //input key
    int key; cout<<"enter key: "; cin>>key; cout<<'\n';
    
    int arr[] = {1,4,6,7,8,9,11,12};

    int size = sizeof(arr)/sizeof(arr[0]);


    if ( binarySearch(arr,0,size-1,key) )
        cout<<"Key found! \n";
    else 
        cout << "key not found! \n";
    

    return 0;
}