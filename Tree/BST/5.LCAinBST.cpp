/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    //Recursive
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (!root)
            return NULL;
        //right (p & q)
        if (root->val < p->val && root->val < q->val )
            return lowestCommonAncestor(root->right,p,q);
        //left(p & q)
        else if (root->val > p->val && root->val > q->val )
            return lowestCommonAncestor(root->left,p,q);
        //p & q in both left & right, so root will be common ancestor
        return root;
    }

class Solution {
public:
    //Iterative same as recursive
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root)
        {
            if (root->val < p->val && root->val < q->val)
                root = root->right;
            else if (root->val > p->val && root->val > q->val)
                root = root->left;
            else
                return root;
        }
        return NULL;
    }
};