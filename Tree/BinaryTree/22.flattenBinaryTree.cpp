/**
 //RECURSIVE O(N) O(N)
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }

//iterative O(N) O(N)
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            st.pop();
            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);
            if (!st.empty())
            {
                curr->left = NULL;
                curr->right = st.top();
            }
        }
    }
 */
class Solution {
public:
//Morris O(N) O(1)
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode *curr = root, *next;
        while (curr)
        {
            if (curr->left)
            {
                next = curr->left;
                while (next->right)
                    next = next->right;
                next->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};