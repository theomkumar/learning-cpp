#include<iostream>
#include<vector>
#include<map>
#include <unordered_map>

using namespace std;

 int minGroups(vector<vector<int>>& nums) {
        if (nums.size() == 1) return 1;
        map<vector<int>, bool> m;
        
        int ans = 0;
        int i;
        
        for (i = 0; i < nums.size(); i++ ) 
        {
            if (m[nums[i]] != 1)
            {
                ans++;
                m[nums[i]] = 1;
                
                int j = i+1;
                while ( j < nums.size())
                {
                    if (m[nums[j]] == 1)
                    {
                        j++;
                    }
                    else if ( ((nums[j][0] >= nums[i][0]) && (nums[j][0] <= nums[i][1])) ||  
                              ((nums[j][1] >= nums[i][0]) && (nums[j][1] <= nums[i][1])) )
                    {
                        j++;
                    }
                    else
                    {
                        m[nums[j]] = 1;
                        j++;
                    }
                    
                }
            }
        }
        return ans;
    }

int main() 
{
    vector<vector<int>> nums = {
                                    {5,10},
                                    // {6, 8},
                                    // {1,5},
                                    {2, 3},
                                    {1, 2}
    
                               };
    int ans = minGroups(nums);
    cout << ans;

    
    return 0;
}