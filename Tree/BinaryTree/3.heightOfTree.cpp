/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/
TC: O(N) going through each node
SC: O(height) storing max O(height) in call stack
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        int ans = max(left, right) + 1;

        return ans;
    }
};