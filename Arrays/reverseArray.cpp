#include<iostream>
using namespace std;

void print(int arr[],int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void reverse(int arr[], int n) {
    //int temp[0];
    
    for (int i=0; i<n/2; i++) {
        swap(arr[i],arr[n-i-1]);
        //temp[0]=arr[i];
        //arr[i]=arr[size-i-1];
        //arr[size-i-1]=temp[0];
    }
}
int main() {
    int even[6]={1,2,3,4,5,6};
    int odd[5]={23,234,232,-12,0};
    reverse(even,6);
    reverse(odd,5);

    print(even,6);
    print(odd,5);


    return 0;
}