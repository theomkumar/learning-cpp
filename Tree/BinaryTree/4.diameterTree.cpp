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

***METHOD 1: O(N^2)***

class Solution {
public:
    int maxDepth(TreeNode* root) {
            if (root == NULL)
            {
                return 0;
            }
            int left = maxDepth(root -> left);
            int right = maxDepth(root -> right);
            int ans = max(left, right) + 1;

            return ans;
        }
    //diameter = max distance between one leaf node to another root/leaf node.
    //3 ways: 1. max distance is on left 2. on right 3. sum of left + right
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) 
            return 0;
        int opt1 = diameterOfBinaryTree(root -> left);
        int opt2 = diameterOfBinaryTree(root -> right);
        int opt3 = maxDepth(root->left) + maxDepth(root->right);
        int ans = max(opt1, max(opt2, opt3)); 
        return ans;
    }
};
 */
//O(N)
class Solution {
public:
    //<diameter,height>
    pair<int,int> diameter(TreeNode* root)
    {
        if (root == NULL)
            return make_pair(0,0);
        //recursive call to get <diameter,height> from right & left
        pair<int,int> left = diameter(root -> left);
        pair<int,int> right = diameter(root -> right);
        // 3 ways from where we can get diameter
        int op1 = left.first;
        int op2 = right.first;
        //3rd from both right and left, which will get calculated from height
        int op3 = left.second + right.second; //+1 if we want no.of nodes
        //ans
        pair<int, int> ans;
        //max diameter
        ans.first = max(op1, max(op2,op3));
        //max height
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};