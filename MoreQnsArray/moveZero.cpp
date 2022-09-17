class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; //j will traverse and swaps with i++ if j is non zero
        // we are shifting all non zero value to left 
        for(int j = 0; j<nums.size(); j++) {
            if (nums[j]!=0) {
                nums[j]=nums[i++];
            }
        }
    }
};