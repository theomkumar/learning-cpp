#include<iostream>
using namespace std;
//for n=2m+1; where 2m depicts 2xduplicate value and +1 represents 1 unique value
int findUnique(int arr[],int n) {
    int ans=0;
    for (int i=0; i<n; i++) {
        ans=ans^arr[i]; 
    }
    cout<<ans<<endl;
    return ans;

}
int main() {
    int arr[5]= {3,3,2,2,4};
    findUnique(arr,5);
    

}