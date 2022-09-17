#include<iostream>

using namespace std;

bool isSorted(int *arr, int n)
{
    //base case
    if (n<1)
        return 1;
    
    //processing
    if (arr[n-1]>arr[n])
    {
        return 0;
    }
    //recursive relation
    return isSorted(arr, n-1);

}

bool isSorted2( int *arr, int n) 
{
    //base case 
    if (n==0 | n==1) return 1; //if arr size is 1 or 0 we'll stop

    //processing
    if ( arr[0] > arr[1])
        return 0;
    else
    {
        bool remainingPart =  isSorted(arr+1,n-1);
        return remainingPart;
    }  
}

int main() 
{
    int arr[] = {0,1,2,3,5,6,7,8,9,10,12};

    int n = sizeof(arr)/sizeof(arr[0]);

    bool ans = isSorted(arr,n-1);

    bool ans2 = isSorted2(arr,n);
    

    //print
    cout<<'\n';
    if (ans) cout<<"Array is Sorted!"<<"\n";

    else cout << "Array is not Sorted!"<<"\n";

    //print
    if (ans2) cout<<"Array is Sorted!"<<"\n";

    else cout << "Array is not Sorted!"<<"\n";

    return 0;
}