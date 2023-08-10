
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 //METHOD 1:

    //UNOPTIMISED BASIC: 
    void dfs (TreeNode* root, long long sum)
    {
        if (!root) return ;
        if (root->val == sum) count++;
        dfs(root->left, sum-root->val);
        dfs(root->right, sum-root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root)
        {
            dfs(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return count;
    }
//Method 2:
    void findPathSum(TreeNode* root, int &targetSum, vector<int> &path, int &count)
    {
        //base case
        if (!root)
            return;
        path.push_back(root->val);
        findPathSum(root->left, targetSum, path, count);
        findPathSum(root->right, targetSum, path, count);

        //check if targetSum is +nt in vector or not
        for (long long int i = path.size()-1, sum = targetSum; i >= 0; i--)
        {
            if (sum == path[i])
                count++;
            sum -= path[i];
        }
        //backtracking
        path.pop_back();
    }
//OPTIMISED
class Solution {
    private:
    void findSum (TreeNode* root, unordered_map<long,int> &m, int k, int &count, long preSum )
    {
        if (!root)
            return;

        preSum += root->val;
        count += m[preSum-k];

        m[preSum]++;
        findSum(root->left, m, k, count, preSum);
        findSum(root->right, m, k, count, preSum);
        m[preSum]--;
    }
    public:
    int pathSum(TreeNode* root, int k) {
        int count = 0, preSum = 0;

        unordered_map<long,int> m;
        m[preSum]++;

        findSum(root, m, k,count, preSum);

        return count;
    }
};