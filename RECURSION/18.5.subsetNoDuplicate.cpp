//https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    void solve (vector<int>&nums, vector<vector<int>>&ans, vector<int>&temp,int begin)
    {
        ans.push_back(temp);
        for (int i = begin; i < nums.size(); i++)
        {
            if (i == begin || nums[i] != nums[i-1])
            {
                temp.push_back(nums[i]);
                solve (nums, ans, temp, i+1);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve (nums,ans,temp,0);
        return ans;
    }
};