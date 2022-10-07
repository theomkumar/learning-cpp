/*
Logic : XOR of x even times = 0 and odd times = x
if n2 is odd this means every element of nums1 will be XOR-ed n2 times(odd) ,this will result in the number itself.

same with n1 and nums2;

*/
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int ans = 0;
        
        if (n1 % 2)
        {
            for (auto i : nums2)
                ans ^= i;
        }
        if (n2 % 2)
        {
            for (auto i : nums1)
                ans ^= i;
        }
        return ans;
    }
};