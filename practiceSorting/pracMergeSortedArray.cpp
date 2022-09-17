#include<iostream>
using namespace std;

void print (int *arr, int n)
{
    for (int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
    cout<<'\n';
}

void merge (int arr1[], int n1, int arr2[], int n2, int *ans)
{
    int i = 0;
    int index1 = 0;
    int index2 = 0;

    while (index1<n1 && index2<n2) {
        if (arr1[index1] > arr2[index2]) {
            ans[i++] = arr2[index2++];
        }
        else if (arr1[index1] < arr2[index2]){
            ans[i++] = arr1[index1++];
        } else {
            ans[i++] = arr1[index1++];
        }
    }
    while (index1 < n1) {
        ans[i++] = arr1[index1++];
    }
    while (index2 < n2) {
        ans[i++] = arr2[index2++];
    }
}

int main() 
{
    int arr1[] = {1,3,5,7,8,9};
    int arr2[] = {0,1,2,3,4,6,7,8,10,11,13};

    int n1 = sizeof(arr1) / sizeof (arr1[0]);
    int n2 = sizeof(arr2) / sizeof (arr2[0]);

    int ans[n1+n2];
    merge(arr1,n1,arr2,n2, ans);

    print(ans, n1+n2);
    
    return 0;
}