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
    void inOrder (TreeNode* root, vector<int> &in)
    {
        if(root == NULL)
            return;
        inOrder(root->left,in);
        in.push_back(root->val);
        inOrder(root->right,in);
    }
    bool findTarget(TreeNode* root, int k) {

        //2-sum logic: we are getting sorted by O(N)!
        vector<int> in;
        inOrder(root,in);

        //2 pointers 2-sum on sorted array
        int i = 0, j = in.size()-1;
        
        while (i < j)
        {
            if (in[i] + in[j] == k)
                return true;
            else if (in[i] + in[j] > k)
                j--;
            else
                i++;
        }
        return false;
    }
};