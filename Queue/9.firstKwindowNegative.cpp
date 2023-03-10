#include<bits/stdc++.h>
using namespace std;

//Not optimal-> Approach 1: BruteForce TC: O(N*k) TLE, SC: O(1)//excluding ans.
/#define ll long long
vector<ll> printFirstNegativeInteger(ll int A[], ll int N, ll int K) 
{
    vector<ll> ans(N-K+1);
    for (ll i = 0; i < N-K+1; i++)
    {
        int temp = 0;
        for (ll j = i; j < i+K; j++)
        {
            if (A[j] < 0)
            {
                temp = A[j];
                break;
            }
        }
        ans[i] = temp;
    }
    return ans;
}
//Approach 2: TC O(N) SC O(k)
//NOTE: DEQUEUE IS NOT NECCESSARILY NEEDED FOR THIS QUESTION, WE CAN DO IT EASILY USING QUEUE!

// Passes all test cases, but can be optimised   
#define ll long long
vector<ll> printFirstNegativeInteger(ll int A[], ll int N, ll int K) 
{
    vector<ll> ans;
    deque<int> q;
    //step 1: process first window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            q.push_back(i);
    }
    if (!q.empty())
        ans.push_back(A[q.front()]);
    else
        ans.push_back(0);
    //step 2: process remaining window
    for (int i = K; i < N; i++)
    {
        if (!q.empty() && i - q.front() >= K)
            q.pop_front();
        if (A[i] < 0)
            q.push_back(i);
        if (!q.empty())
            ans.push_back(A[q.front()]);
        else ans.push_back(0);
    }
    return ans;
}
//Approach 3: TC O(N) SC O(1)
/*

*/
 
#define ll long long
vector<ll> printFirstNegativeInteger(ll int A[], ll int N, ll int K) 
{
    vector<ll> ans;
    int firstIndex = 0, element; //(first negative element)
    
    for(int i = K-1; i < N; i++)
    {
        //skip +ve or out of window element while making sure it is less than i!(inside window)
        while (firstIndex < i && ((firstIndex <= i-K) || A[firstIndex] >= 0))
            firstIndex++;

        //processing current element 
        if (A[firstIndex] < 0)
            element = A[firstIndex];
        else
            element = 0;
        ans.push_back(element);
    }
    return ans;
}
 
//#2 Attempt

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

#define ll long long 
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) 
{
    vector<ll> ans;
    int firstNegativeIndex = 0, firstNegativeElement;
    
    for (int i = K-1; i < N; i++)
    {
        //skip +ve element, out of window element
        while(firstNegativeIndex < i && (firstNegativeIndex <= i-K || A[firstNegativeIndex] >= 0 ))
            firstNegativeIndex++;
        //
        if (A[firstNegativeIndex] < 0)
            ans.push_back(A[firstNegativeIndex]);
        else
            ans.push_back(0);
    }
    return ans;
}