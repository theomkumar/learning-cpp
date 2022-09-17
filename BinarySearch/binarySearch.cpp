#include<iostream>
using namespace std;

int binarySearch(int arr[],int size,int key){

    int start=0,end=size-1;
//  int mid=(start+end)/2; coz start +end can go outside int range.
    int mid=start+(end-start)/2;

    while(start<=end) {
        if (arr[mid]==key) return mid;

        else if (key>arr[mid]) start=mid+1; 

        else end=mid-1;   
        mid=start+(end-start)/2;
    }
    return -1;
}
int main(){
    int even[6]={2,4,6,8,12,18};
    int odd[5]={3,8,11,14,16};
    cout<<" index of 8 in even array is "<<binarySearch(even,6,8)<<"\n";

    cout<<" index of 3 in odd array is "<<binarySearch(odd,5,3)<<endl;
}