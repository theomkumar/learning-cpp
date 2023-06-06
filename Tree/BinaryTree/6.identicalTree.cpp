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

    bool isSameTree(TreeNode* p, TreeNode* q){
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL && q != NULL)
            return false;
        if (p != NULL && q == NULL)
            return false;

        bool left = isSameTree(p -> left, q -> left);
        bool right = isSameTree(p -> right, q -> right);
        bool curr = (p -> val == q -> val);

        return (left && right && curr);
    }

    bool isSameTree(TreeNode* p, TreeNode* q){
        if (!p && !q )  return true;
        if (!p && q || p && !q)  return false;

        bool left = isSameTree(p -> left, q -> left);
        bool right = isSameTree(p -> right, q -> right);
        bool curr = (p -> val == q -> val);

        return (left && right && curr);
    }

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
    //if p or q is null then only if both are NULL it's identical obviously, else it's false.* q){
        if (!p || !q)   return (p == q);
        
        return (isSameTree(p->left,q->left) && isSameTree(p->right, q->right) && (p->val == q->val));
    }
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        return (!p || !q) ? (p == q) : (isSameTree(p->left,q->left) && isSameTree(p->right, q->right) && (p->val == q->val));
    }
};