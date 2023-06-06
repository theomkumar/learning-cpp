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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        //queue<TreeNode*,<horizontalDistance, vertical level> >
        queue<pair<TreeNode*,pair<int,int>>> q;
        //map <horizontalDistance, map<verticalLevel,multiset<int> >
        map<int, map<int, multiset<int>>> node;

        q.push(make_pair(root, make_pair(0,0)));

        while (!q.empty())
        {
            pair<TreeNode*,pair<int,int>> curr = q.front();
            q.pop();
            TreeNode* currNode = curr.first;
            //horizontal distance
            int hd = curr.second.first;
            //vertical distance
            int level = curr.second.second;

            node[hd][level].insert(currNode->val);
            if(currNode -> left)
                q.push(make_pair(currNode->left, make_pair(hd-1,level+1)));
            if(currNode -> right)
                q.push(make_pair(currNode->right, make_pair(hd+1,level+1)));
        }
        for (auto i:node)
        {
            vector<int> temp;
            for (auto j: i.second)
            {
                temp.insert(temp.end(), j.second.begin(),j.second.end()); 
            }
            ans.push_back(temp);
        }
        return ans;
    }
};