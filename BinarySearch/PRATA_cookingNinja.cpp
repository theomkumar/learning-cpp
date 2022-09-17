#include<iostream>
using namespace std;
//incomplete;
bool isPossible(int rank[],int m,int n, int mid) {
    
    int i=0;
    int count = 0;
    int totalCount = 0;      
    int totalTime=0;
    
    while (i<n) {
        int time = count*rank[i];
        if(totalTime<=mid){
            totalTime+=time;
            totalCount+=count;
            count++;     
        }if (totalCount==m) return true;
        if (totalTime>mid) {
            i++;
            count=0;
        }
    }
    return false;
}


int minCookTime(int rank[], int n,int m)
{
    int maxi = -1; 
    for(int i=0; i<n; i++) {
        maxi = max(rank[i],maxi);
    }
    int s = 0, e = maxi*m, mid = s+(e-s)/2;
    int time = 0;
    while(s<=e) {
        if (isPossible(rank,m,n,mid)) {
            time = mid;
            e = mid-1;
        }else s = mid+1;
        mid = s+(e-s)/2;        
    }
    return time;
}
int main() {
    int rank[4] = {1,2,3,4};
    int n = 4;
    int m = 11;
    cout<<minCookTime(rank,n,m);
}