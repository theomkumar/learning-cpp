/**

 *****************INTUITION**********************

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*>q;

        q.push(root);
        int z = 1;
        while(!q.empty())
        {
            int count = q.size();
            vector<int> level; 

            for(int i = 0; i < count; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp -> val);

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            if(z % 2)
                ans.push_back(level);
            else
            {
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            z++;
        }
        return ans; 
    }
 */
// Logic : 2 ways
// 1. push into the queue in a zig-zag manner
// 2. push into queue normally (level order i.e left to right) but insert in vector in zig zag manner, using a boolean value
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*>q;

        q.push(root);
        bool leftToRight = true;

        while(!q.empty())
        {
            int n = q.size();
            vector<int> currLevel(n); 

            for(int i = 0; i < n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                
                int index = leftToRight ? i : n-i-1;
                currLevel[index] = temp -> val;
                
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            ans.push_back(currLevel);
            leftToRight = !leftToRight;
        }
        return ans; 
    }
};