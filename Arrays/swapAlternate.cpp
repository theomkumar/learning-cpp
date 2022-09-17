#include<iostream>
using namespace std;

void print (int arr[],int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void altSwap(int arr[],int n) {
    //for(int i=0,Count=1;Count<=n/2; i+=2,Count++) {
        for(int i=0; i+1<n; i+=2) {
        swap(arr[i],arr[i+1]);
    }
}
int main() {
    int odd[7]={1,2,3,4,5,6,7};
    int even[4]={1,2,3,4};

    altSwap(odd,7);
    altSwap(even,4);

    print(odd,7);
    print(even,4);
    

}