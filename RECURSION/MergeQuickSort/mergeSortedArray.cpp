#include<iostream>
using namespace std;

void print (int *ans, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main() 
{
    int arr1[] = {1,2,3,5,7,8,90};
    int arr2[] = {2,6,8,12,64,122};

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    

    int ans[n1+n2];
    
    //merging sorted array;
    int index1 = 0, index2 = 0, ansIndex = 0;

    while ( index1<n1 && index2<n2 ) 
    {
        if (arr1[index1] < arr2[index2])
            ans[ansIndex++] = arr1[index1++];
        else
            ans[ansIndex++] = arr2[index2++];
    }

    while (index1<n1) 
        ans[ansIndex++] = arr1[index1++];
    
    while (index2<n2) 
        ans[ansIndex++] = arr2[index2++];


    print (ans,n1+n2);

    return 0;
}