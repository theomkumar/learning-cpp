#include<iostream>
using namespace std;
bool isNum(int arr[],int size,int search){
    for(int i=0; i<size; i++) {
        if(arr[i]==search) return 1;
    }
    return 0;
}

int main() {
    int search;
    cout<<"\nSearch number from array! \n";
    cin>>search;
    int arr[10]={1,2,3,4,5,-12,-23,23,14,24};

    bool isFound= isNum(arr,10,search);
    if (isFound) cout<<"number "<<search<<" is found! \n";
    else cout<<"number "<<search<<" not found! \n";



}