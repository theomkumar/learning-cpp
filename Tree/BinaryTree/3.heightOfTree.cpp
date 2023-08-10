/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/
TC: O(N) going through each node
SC: O(height) storing max O(height) in call stack in case of skewed tree
 */


//Logic : maxDepth = max(maxDepthRight, maxDepthLeft) + 1(root node);

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);

        return max(left, right) + 1;
    }
};