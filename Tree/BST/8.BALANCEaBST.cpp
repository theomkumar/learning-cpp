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

    void inOrder(TreeNode* root, vector<int> &in)
    {
        if (!root)  return;
        inOrder(root->left,in);
        in.push_back(root->val);
        inOrder(root->right,in);
    }
    TreeNode* inorderToBST(vector<int>&in, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = inorderToBST(in,start,mid-1);
        root->right = inorderToBST(in,mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inOrder(root,in);
        return inorderToBST(in,0, in.size()-1);
    }
 */
class Solution {
public:
    void inOrder(TreeNode* root, vector<TreeNode*> &in)
    {
        if (!root)  return;
        inOrder(root->left,in);
        in.push_back(root);
        inOrder(root->right,in);
    }
    TreeNode* inorderToBST(vector<TreeNode*>&in, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = (start+end)/2;
        TreeNode* root = in[mid];
        root->left = inorderToBST(in,start,mid-1);
        root->right = inorderToBST(in,mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> in;
        inOrder(root,in);
        return inorderToBST(in,0, in.size()-1);
    }
};