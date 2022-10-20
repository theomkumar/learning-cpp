#include<bits/stdc++.h>
using namespace std;

//Not optimal-> Approach 1: BruteForce TC: O(N*k) TLE, SC: O(1)//excluding ans.
#define ll long long
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
#define ll long long
vector<ll> printFirstNegativeInteger(ll int A[], ll int N, ll int K) 
{
    vector<ll> ans;
    
    return ans;
}