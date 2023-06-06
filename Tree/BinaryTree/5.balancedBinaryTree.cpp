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
 *************METHOD 1:: O(N^2)********************

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
        bool isBalanced(TreeNode* root) {
            //base case 
            if (root == NULL)
                return true;
            //recursive call to the left and right subtree
            bool left = isBalanced(root -> left);
            bool right = isBalanced(root -> right);
            //solving one case
            bool diff = abs(maxDepth(root -> left) - maxDepth(root -> right)) <= 1;
    
            return (left && right && diff);
        }
 *********METHOD 2: O(N)***** ssss  
 */
class Solution {

    //<isBalanced,height>
    pair<bool, int> balanced(TreeNode* root)
    {
        if (root == NULL)
            return make_pair(true,0);

        //recursive call to left and right
        pair<bool, int> left = balanced(root -> left);
        pair<bool, int> right = balanced(root -> right);

        //balance conditions:(3) all left node,all right node, current node(root) height difference <= 1 
        bool leftBalance = left.first;
        bool rightBalance = right.first;
        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
       //checking balance condition 
        ans.first = (leftBalance && rightBalance && diff);
        //calculating height
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return balanced(root).first;
    }
};
