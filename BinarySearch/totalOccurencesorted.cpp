#include<iostream>
using namespace std;

int firstOccurence(int arr[],int n,int k) {
    int s=0, e=n-1, m=s+(e-s)/2;
    int ans=0;

    for(; s<=e; m=(s+(e-s)/2)) {
        if (arr[m]==k) {
            ans=m;
            e=m-1;
        }
        else if (arr[m]>k) {
            e=m-1;
        }
        else s=m+1;
    }
    return ans;
}

int lastOccurence(int arr[],int n,int k) {
    int s=0, e=n-1, m=s+(e-s)/2;
    int ans=0;
    for(; s<=e; m=s+(e-s)/2) {
        if (arr[m]==k) {
            ans=m;
            s=m+1;
        }
        else if(arr[m]<k) {
            s=m+1;
        }
        else e=m-1;
    }
    return ans;
}

int main() {
    cout<<"search total no. of occurences of : ";

    int s; cin>>s;
    int arr[6]={1,2,3,4,4,4};
    int ans=(lastOccurence(arr,6,s)-firstOccurence(arr,6,s));
    cout<<"\ntotal occurence= "<<ans<<"\n";


}