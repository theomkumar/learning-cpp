#include<iostream>
#include<vector>
// https://leetcode.com/problems/subsets/submissions/
using namespace std;
/*
**RECURSION + BACKTRACKING** then  **Bit manipulation**

class Solution {
private:
    void subset(vector<int> &nums, int i, vector<vector<int>>& ans, vector<int> &output)
    {
        if (i >= nums.size()) {
            ans.push_back(output);
            return;
        }
        //exclude
        subset(nums, i+1, ans, output);
        //include
        output.push_back(nums[i]);
        subset(nums, i+1, ans, output);
        output.pop_back();
        
    }  
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int i = 0;
        subset(nums, i, ans, output);
        return ans;
    }
		
**Bit manipulation**

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int total = 1<<nums.size();    //pow(2,nums.size() )
				
        for (int i = 0; i < total; i++) {
            temp.clear();			
            for (int j = 0; j < nums.size(); j++) {
                if ( (1<<j) & i ) { 
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
     
    }
};
		
};
*/
void print (vector<vector<int>> &ans) 
{
    for (int i = 0; i<ans.size(); i++) {

        cout<<"[";

        for (int j = 0; j<ans[i].size(); j++) {
            cout<< ans[i][j];

            if (j<ans[i].size()-1)
                cout<<",";
        }
            
        if (i<ans.size()-1)
            cout<<"], ";
        else cout<<"]";
    }
    cout<<"\n";
}

void solve (vector<int> &nums, vector<int> &output, int i, vector<vector<int>> &ans)
{
    //base case
    if (i == nums.size())
    {
        ans.push_back(output);
        return;
    }
    //exclude 
    solve (nums, output, i+1, ans);   
    //include
    output.push_back( nums[i]);
    solve (nums, output, i+1, ans);
    output.pop_back();
    //to optimize we can add pop back with output being reference variable.
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    //ans
    vector<vector<int>> ans;
    vector<int> output;
    //index
    //int i = 0;
    
    solve(nums, output, 0, ans);

    print (ans);
    return ans;
}

int main() 
{
    vector<int> nums{1,2,3};
    subsets(nums);
     
    return 0;
}

