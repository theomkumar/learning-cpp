#include<iostream>
using namespace std;

bool isFound(int *arr, int size,int key)
{
    //base case
    if (size==0)
        return 0;
    //solving one case
    if (arr[0]==key)
        return 1;
    //Recursive relation
    return isFound(arr+1, size-1, key);
    
}

int main()
{
    //input
    cout<<"Input Search: ";
    int n; cin>>n; cout<<'\n';

    int arr[] = {1,2,4,6,7,8,9,22,66};
    int size = sizeof(arr)/sizeof(arr[0]);

    //output
    if ( isFound(arr, size, n) )
        cout <<n<<" is present! \n";
    else 
        cout<<n<<"  not found \n";

    return 0;
}