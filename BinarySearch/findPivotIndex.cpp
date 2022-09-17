#include<iostream>
using namespace std;

//unfinished

int postSum(int arr[],int i,int n){
    int s=0;
    for(; i<=n; i++) {
        s+=arr[i];
    }
    return s;

}

int preSum(int arr[],int i,int n) {
    int s=0;
    for(; i<n; i++) {
        s+=arr[i];
    }
    return s;
}


int main() {
    int arr[6]={1,7,3,6,5,6};
    int s=0, e=6-1,m =s+(e-s)/2;

    while(m>=s || m<=e) {        
        if ((preSum(arr,s,m))>(postSum(arr,m+1,m))) m--;
        else if (((preSum(arr,s,m))<(postSum(arr,m+1,m)))) m++;
        else if (((preSum(arr,s,m)) < (postSum(arr,m+1,m)))){
            cout<<m<<endl;
        } 
        
    }
    cout<<"-1";
    
}