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
 

 **********INTUITIVE USING NULL to mark level************
 
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*>q;

        q.push(root);
        q.push(NULL);
        
        vector<int> level;

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp != NULL)
            {
                level.push_back(temp -> val);
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            else
            {
                ans.push_back(level);
                level.clear();
                if(!q.empty())
                    q.push(NULL);
            }
        }

        return ans;

    } 

 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*>q;

        q.push(root);
        
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
            ans.push_back(level);
        }
        return ans;
    } 
};