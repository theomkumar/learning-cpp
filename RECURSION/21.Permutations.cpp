#include<iostream>
#include<vector>
using namespace std;

void print (vector<vector<int>> &ans)
{
    for (int i = 0; i<ans.size(); i++) {
        cout <<"( ";
        for (int j = 0; j<ans[i].size(); j++){
            cout << ans[i][j] <<" ";
        } cout <<") ";
    }
}
void solve (vector<int>&nums, vector<vector<int>>&ans, int idx)
{
    //base case
    if (idx >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
 
    for (int j = idx; j<nums.size(); j++)
    {
        //step1
        swap(nums[idx], nums[j]);
        //recursive call
        solve (nums, ans, idx+1); 
        //undo step1 
        swap(nums[idx], nums[j]);
    }
}
//(backtracking) coz we are making changes in original array,and we are using reference variable, //if we remove reference variable then we don't need to do backtracking but it will take extra space.

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> ans;
    solve(nums, ans, 0);

    print(ans);
    return ans;
}

int main() 
{
    vector<int> nums = {1,2,3};
    permute(nums);
    
    return 0;
}