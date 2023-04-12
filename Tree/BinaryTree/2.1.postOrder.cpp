#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNod/**
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
/*
    //recursive;
    void solve(TreeNode* root, vector<int> &postOrder)
    {
        if(root == NULL)
            return;
        solve(root->left, postOrder);
        solve(root->right, postOrder);
        postOrder.push_back(root -> val);
    }
*/
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if (root == NULL)
            return postOrder;
        //solve(root,postOrder);

       //iterative method 1: using 2 stacks:

       //idea is to go in reverse order, like going from root->right instead of left, basically processing all right elements first, so when we reverse stack we'll get it sorted.

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while (!s1.empty())
        {
            root = s1.top();
            s1.pop();
            s2.push(root);

            if(root -> left)
                s1.push(root -> left);

            if(root -> right)
                s1.push(root -> right);
        }
        while (!s2.empty())
        {
            postOrder.push_back(s2.top()->val);
            s2.pop();
        }
        
        return postOrder;
    }
};e(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
/*
    //recursive;
    void solve(TreeNode* root, vector<int> &postOrder)
    {
        if(root == NULL)
            return;
        solve(root->left, postOrder);
        solve(root->right, postOrder);
        postOrder.push_back(root -> val);
    }
*/
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if (root == NULL)
            return postOrder;
        //solve(root,postOrder);

       //iterative method 1: using 2 stacks:

       //idea is to go in reverse order, like going from root->right instead of left, basically processing all right elements first, so when we reverse stack we'll get it sorted.

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while (!s1.empty())
        {
            root = s1.top();
            s1.pop();
            s2.push(root);

            if(root -> left)
                s1.push(root -> left);

            if(root -> right)
                s1.push(root -> right);
        }
        while (!s2.empty())
        {
            postOrder.push_back(s2.top()->val);
            s2.pop();
        }
        
        return postOrder;
    }
};