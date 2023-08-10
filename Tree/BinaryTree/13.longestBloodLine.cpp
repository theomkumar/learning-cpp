class Solution
{
public:
    void findSum(Node* root, int sum, int lvl, int &maxLevel, int &maxSum)
    {
        if (root == NULL) return;
        sum += root->data;
        
        if (lvl == maxLevel)
            maxSum = max(maxSum, sum);
        
        else if (lvl > maxLevel)
        {
            maxLevel = lvl;
            maxSum = sum;
        }
        findSum(root->right, sum, lvl+1, maxLevel,maxSum);
        findSum(root->left, sum, lvl+1, maxLevel,maxSum);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum = 0, lvl = 0, maxLevel = -1, maxSum = 0;
        if (root == NULL)
            return 0;
        findSum(root, sum, lvl, maxLevel, maxSum);
        return maxSum;
    }
};