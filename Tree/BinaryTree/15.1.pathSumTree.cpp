/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findPath(TreeNode* root, vector<vector<int>> &allPaths, vector<int> &currPath, int sum, int &targetSum)
    {
        if (!root)
            return;
    
        sum += root->val;
        currPath.push_back(root->val);

        if (sum == targetSum && root->left == NULL && root->right == NULL)
            allPaths.push_back(currPath);
    
        findPath(root->left, allPaths, currPath, sum, targetSum);
        findPath(root->right, allPaths, currPath, sum, targetSum);
        //Backtracking (after going through left & right we'll return while popping)
        currPath.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currPath;
        int sum = 0;
        findPath(root, allPaths, currPath,sum , targetSum);
        return allPaths;
    }
};