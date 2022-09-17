#include<iostream>
using namespace std;

int lastOccurence(int arr[],int size,int key) {
    int start=0,end=size-1,mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end) {
        if(arr[mid]==key) {
            ans=mid;
            start=mid+1;
        }
        else if(arr[mid]<key) start=mid+1;  
        else end=mid-1;
        mid=start+(end-start)/2;
    }
    return ans;

}

int firstOccurence(int arr[],int size,int key) {
    int ans=-1;
    int start=0,end=size-1,mid=start+(end-start)/2;
    while(start<=end) {
        if(arr[mid]==key){
            ans=mid;
            end=mid-1;
        }
        else if (arr[mid]<key) start=mid+1;
        else end=mid-1; //(arr[mid]>key)
        mid=start+(end-start)/2;
    }
    return ans;

}
int main() {
    int arr[8]={0,0,1,1,2,2,2,2};
    cout<<firstOccurence(arr,8,2)<<" "<<lastOccurence(arr,8,2)<<endl;
}