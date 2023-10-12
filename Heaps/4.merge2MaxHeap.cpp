
// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void heapify(vector<int> &ans, int i) {
        if (i < 0) return;
        int l = 2*i+1, r = 2*i+2;
        int largest = i;
        if (l < ans.size() && ans[l] > ans[largest])
            largest = l;
        if (r < ans.size() && ans[r] > ans[largest])
            largest = r;
        if (largest != i)
        {
            swap(ans[i],ans[largest]);
            heapify(ans,largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // merge both array
        vector<int> ans(n+m);
        for(int i = 0; i < ans.size(); i++) {
            if (i < n)
                ans[i] = a[i];
            else
                ans[i] = b[i-n];
        }
        n = ans.size();

        //heapify this array
        for (int i = n/2-1; i >= 0; i--)
            heapify(ans,i);
        return ans;
    }
};
