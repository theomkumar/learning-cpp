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
    void solve (TreeNode* root, vector<int> &inorder)
    {
        if(root == NULL)
            return;
        solve(root -> left, inorder);
        inorder.push_back(root -> val);
        solve(root -> right, inorder);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;

        /* ITERATIVE

        stack<TreeNode*> s;
        TreeNode* currNode = root;

        while(!s.empty() || currNode != NULL)
        {
            if(currNode != NULL)
            {
                s.push(currNode);
                currNode = currNode -> left;
            }
            else
            {
                currNode = s.top();
                s.pop();
                inorder.push_back(currNode -> val);
                currNode = currNode -> right;
            }
        }
        */
        //RECURSIVE
        solve(root, inorder);
        return inorder;
    }
};