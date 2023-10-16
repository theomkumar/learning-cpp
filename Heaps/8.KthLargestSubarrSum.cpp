//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//APPROACH 1: BRUTE : O(N^2*logN) SC: O(N^2)
class Solution{
public:
    int kthLargest(vector<int> &arr,int N,int K){
        vector<int> sum;
        for (int i = 0; i < N; i++)
        {
            int currSum = 0;
            for (int j = i; j < N; j++)
            {
                currSum += arr[j];
                sum.push_back(currSum);
            }
        }
        sort(sum.begin(),sum.end());
        return (sum[sum.size()-K]);
    }
};
//Approach 2: OPTIMAL, TC: O(N^2*log K) SC: O(K)
class Solution{
public:
   
    int kthLargest(vector<int> &arr,int N,int K){
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for (int i = 0; i < N; i++)
        {
            int currSum = 0;
            for (int j = i; j < N; j++)
            {
                currSum += arr[j];
                pq.push(currSum);
                if (pq.size() > K)
                    pq.pop();
            }
        }
        return pq.top();
    }
};
//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends