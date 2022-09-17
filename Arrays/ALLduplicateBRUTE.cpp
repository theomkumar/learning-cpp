/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n]
and each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int i=0;
    while(i<n) {
        int j=i+1;
        while(j<n) {
            if(nums[i]==nums[j]) {
                int s=nums[i];
                ans.push_back(s);
            }
            j++;
        } 
        i++;
    }
        return ans;
    }
};