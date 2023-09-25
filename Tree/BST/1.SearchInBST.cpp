/**

 //IN CASE OF SKEWED TREE, Time complexity will be O(N), generally O(Height);  

//RECURSIVE:

    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL)
            return NULL;
        if (root->val == val)
            return root;
        if (root->val < val)
            return searchBST(root->right, val);
        else
            return searchBST(root->left, val);
    }
 
 //ITERATIVE:
    
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root)
        {
            if (root->val == val)
                return root;

            if (root->val < val)
                root = root->right;
            else
                root = root->left;
        }
        return NULL;
    }
};