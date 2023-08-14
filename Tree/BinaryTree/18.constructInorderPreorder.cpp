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
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int &rootIdx, 
                     int left, int right ,unordered_map<int,int> &m)
    {
        if (left > right)
            return NULL;
        //make node
        int element = preorder[rootIdx++];
        int inorderIdx = m[element];
        TreeNode* newNode = new TreeNode(element);

        newNode->left = build(preorder, inorder, rootIdx, left, inorderIdx-1,m);
        newNode->right = build(preorder, inorder, rootIdx, inorderIdx+1, right,m);

        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;

        int rootIdx = 0;
        TreeNode* ans = build(preorder, inorder, rootIdx, 0, inorder.size()-1,m);
        return ans;
    }
};