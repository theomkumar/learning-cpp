#include<iostream>
using namespace std;

//https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=1
bool isPossible(vector<int> &stalls, int n, int k, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];
    for(int i=0; i<n; i++) {
		if (stalls[i] - lastPos >= mid) {
            cowCount++;
            if (cowCount==k) return true;
            lastPos = stalls[i];
        }
       
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    int maxi=-1;
    for(int i=0; i<n; i++) {
        if (stalls[i]>maxi) maxi=stalls[i];
    }
    
    int s=0, e=maxi, mid = s+(e-s)/2;
    int ans = -1;
    while (s<=e) {
        if (isPossible(stalls,n,k,mid)) {
            ans = mid;
            s = mid+1;
        }
    	else e = mid-1;
        mid = s+(e-s)/2;
    }
    return ans;
}

int main() {
     vector<int> &stalls;
    
}