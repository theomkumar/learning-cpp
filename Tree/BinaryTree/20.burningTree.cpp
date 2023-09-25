Logic:
we need to traverse from the targetNode in 3 direction to infect:
1. Parent, 2. left , 3. right
//as we can't access parent from the node, we need to map every node to it's parent node;
//we have to make sure we don't infect same node twice so we can track the infected node as well 
class Solution {
private:
    TreeNode* findTarget(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&nodeToParent, int target)
    {
        TreeNode* targetNode = NULL;
        queue<TreeNode*> q;

        q.push(root);
        nodeToParent[root] = NULL;

        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->val == target)
                targetNode = temp;
            if (temp->left)
            {
                q.push(temp->left);
                nodeToParent[temp->left] = temp;
            }
            if (temp->right)
            {
                q.push(temp->right);
                nodeToParent[temp->right] = temp;
            }
        }
        return targetNode;
    }
    int infect(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &nodeToParent)
    {
        int time = 0;
        unordered_map<TreeNode*, bool>isInfected;
        queue<TreeNode*> q;
        q.push(root);
        isInfected[root] = true;

        while (!q.empty())
        {
            int n = q.size();
            bool infected = false;
            for(int i = 0; i < n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                //3 ways to infect;
                if (temp->left && !isInfected[temp->left])
                {
                    q.push(temp->left);
                    isInfected[temp->left] = true;
                    infected = true;
                }
                if (temp->right && !isInfected[temp->right])
                {
                    q.push(temp->right);
                    isInfected[temp->right] = true;
                    infected = true;
                }
                if (nodeToParent[temp] && !isInfected[nodeToParent[temp]])
                {
                    q.push(nodeToParent[temp]);
                    isInfected[nodeToParent[temp]] = true;
                    infected = true;
                }
            }
            if (infected)
                time++;
        }
        return time;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> nodeToParent;
        TreeNode* targetNode = findTarget(root,nodeToParent,start);
        return infect(targetNode, nodeToParent);
    }
};