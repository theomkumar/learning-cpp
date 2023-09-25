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
 //
 using range (min, max)

    bool isBST(TreeNode* root, long min, long max)
    {
        if (root == NULL)
            return true;
        if (root->val <= min || root->val >= max)
            return false;

        bool left = isBST(root->left, min, root->val); 
        bool right = isBST(root->right, root->val, max);
        return (left && right);
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN, LONG_MAX);
    }
 */
class Solution {
public:
//using the inorder traversal

    bool isBST(TreeNode* root, TreeNode* &prev)
    {
        if (!root) return true;
        
        //Left SubTree First
        bool left = isBST(root->left,prev); 

        //check current node
        if (prev != NULL && prev->val >= root->val)
            return false;
        //after checking update the prev 
        prev = root;

        //right subtree last
        bool right = isBST(root->right,prev);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return isBST(root,prev);
    }
};