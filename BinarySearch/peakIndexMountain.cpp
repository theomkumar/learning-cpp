#include<iostream>
using namespace std;


//mountain peak is higest point ,so required no. is index of largest number in the array.

/*
852. Peak Index in a Mountain Array

* traverse linearly to find the maximum value of the array;  *
	 
	 int peakIndexInMountainArray(vector<int>& arr) {
        int maxi=INT_MIN, ans=0;
        for(int i=0; i<arr.size(); i++) {
            if (arr[i]>maxi) {
                maxi=arr[i];
                ans=i;
            }
        }
        return ans;
    }

*BINARY*

method 1

    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int start=0, end=n-1, mid=(start+(end-start)/2);

    while(start<end){
        if(arr[mid]>arr[mid+1]){
            end=mid;     
        }
        else {
            start=mid+1; 
        }
         mid=(start+(end-start)/2);   
    }
    return mid;
}    
*/
// Method 2 //first attempt


int peakIndex(int arr[], int n) {
    int start=0, end=n-1, mid=(start+(end-start)/2);

    while(start<=end){

    
        if(arr[mid]>arr[mid+1]){
            end=mid; mid=(start+(end-start)/2);
            
        }
        if (arr[mid]<arr[mid+1]) {
            start=mid+1; mid=(start+(end-start)/2);
        }

        if (arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) {
            return mid;
        }
    }
    return -1;
}  

int main() {
    int arr[10]={40,48,61,75,100,99,98,39,30,10};
    
    cout<<peakIndex(arr,4);

}