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
    //MORRIS TRAVERSAL O(N) space O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr != NULL)
        {
            if (curr->left == NULL)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            //connect the right-most node of left subtree to curr, if it's already connected then it means we have returned , so we just go right
            else
            {
                TreeNode* temp = curr->left;

                while (temp->right && temp->right != curr)
                    temp = temp->right;

                //we have been returned from the left subtree so just print node and move to the right
                if (temp->right == curr)
                {
                    temp->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
                //connect the rightmost node to the curr, we can go back
                else
                {
                    temp->right = curr;
                    curr = curr->left;
                }
            }
        }
        return inorder;
    }
};