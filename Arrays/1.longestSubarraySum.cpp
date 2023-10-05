//TC : if using ordered map -> O(N*logn ), O(N^2) or O(N) if using unordered_map(worst in O(N^2))

//LOGIC: we need to find longest subarray with sum k, but finding k in the middle is difficult, that's why we do reverse engineering, we have presum and sum , we store presum in map, and sum as a variable,
//for any index i, suppose there exist a subarray with sum = k, then there must exist, x-k (presum)

// x = whole, k is part
// other part = x-k, at each index we will look if x-k exists.

#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    int maxLen = 0, sum = 0;
    unordered_map<int,int> preSum;
    

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == k)
            maxLen = i+1;
        else if (preSum.find(sum-k) != preSum.end())
            maxLen = max(maxLen, i-preSum[sum-k]);
        //if the sum exists previoulsy no need to update the index and it will only decrease the size of subarray:
        if (preSum.find(sum) == preSum.end())
            preSum[sum] = i;
    }
    return maxLen;   
}    
//if array consists non-negative number, we can use simple two pointers, left & right, if sum < k , then increase right, and if sum > k, then decrease left

time O(N) SPACE O(1) 
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int i = 0, j = 0;
    int maxLen = 0;
    long long sum = 0;
    

    while (j < a.size())
    {
        sum += a[j];
        if (sum == k)
        {
            maxLen = max(maxLen,j-i+1);
            j++;
        }
        //increase right
        else if (sum < k)
            j++;
        //decrease left(we are decreasing right also only coz we are adding jth element every loop)
        else if (sum > k)
            sum -= (a[i++] + a[j]);  
    }
   
    return maxLen; 
}


//2
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int i = 0, j = 0;
    int maxLen = 0;
    long long sum = a[0];

    while (j < a.size())
    {
        while (sum > k && i <= j)
            sum -= a[i++];

        if (sum == k)
            maxLen = max(maxLen,j-i+1);
        //sum < k or equal we need to increase
        j++;
        if (j < a.size())  sum += a[j];
    }
   
    return maxLen; 
}
//3
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int maxLen = 0;
    long long sum = a[0];

    for (int i = 0, j = 0; j < a.size(); sum += a[++j])
    {
        //shrink left if it's greater
        while (sum > k)
            sum -= a[i++];
        //update max len 
        if (sum == k)
            maxLen = max(maxLen,j-i+1);
    }
   
    return maxLen; 
}